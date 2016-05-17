/* -*- mode: C; c-basic-offset: 4; -*- */
#include "smallsh.h"

/* El siguiente procedimiento procesa una línea de entrada. La ejecución
 * termina cuando se encuentra un final de linea ('\n'). El caracter ';'
 * sirve para separar unas ordenes de otras y el caracter '&' permite
 * una orden en background.
 */
int pipeActive = 1; //pipe is not active
void
procline(struct TokBuf * tb) {
    char * arg[MAXARG + 1]; /* Array de palabras: orden + argumentos. */
    int i;
    for (i=0; i<tb->length; i++){
        //arg[i] = (char *)malloc(100);
        arg[i] = NULL;
    }
    TokType toktype;        /* Tipo de token. */
    unsigned narg;          /* Número de argumentos leídos para la orden. */
    unsigned where;         /* El proceso se ejecutará en primer o segundo plano .*/
    unsigned ntoken;        /* Tokens procesados */
    unsigned sec; /* Segundos si se establece la alarma */
   /* for (ntoken = 0; ntoken < tb->length; ntoken++) {
        printf("Parámetro de token buffer: %s \n", tb->tokens[ntoken].data);
    }*/
    narg = 0;
    for (ntoken = 0; ntoken < tb->length; ntoken++) {
        //printf("Número de tokens: %i\n", tb->length);
        switch(toktype = tb->tokens[ntoken].type) {
        case ARG:   /* Se ha leído un argumento. */
            if (narg < MAXARG){
                arg[narg++] = tb->tokens[ntoken].data;
                printf("Añado token: %s\n", tb->tokens[ntoken].data);
            }
            break;
        case ARROBA:{
            char * p = strtok(tb->tokens[ntoken].data,"@"); //Numero de segundos
            //printf("Lanzo el runcommand con alarma, tiempo : %i\n", atoi(p));
            //printf("Voy a añadir el comando a la lista\n");
            runcommand_alarm(arg, BACKGROUND, atoi(p));
            narg = 0;
            break;
        }
        case PIPE:{
            pipeActive = 0; //pipeLine is now active
            //printf("Activo PIPE");
            if (narg < MAXARG){
                arg[narg++] = tb->tokens[ntoken].data;
                //printf("Añado token: %s\n", tb->tokens[ntoken].data);
            }
            break;
        }
        case EOL:
        case SEMICOLON:
        case AMPERSAND:
       
        case AND:
        case OR:
            if (pipeActive == 1) {
                if (toktype == AMPERSAND){
                        where = BACKGROUND;
                } else where = FOREGROUND; 
                if (narg != 0) {
                    arg[narg] = NULL; //Borra el EOL
                    //showCommands();
                    //printf("Voy a añadir el comando a la lista\n");
                    //showCommands();
                    runcommand(arg, where);
                }
            } else {
                if (narg != 0) {
                    arg[narg] = "|"; //Borra el EOL
                    arg[narg+1] = NULL;
                    runcommand_pipe(arg);
                }
            }
            pipeActive = 1;
            narg = 0;
            break;
        default:
            ; /* Ignorar */
        }
    }
}
