#include "smallsh.h"

void initCommandsList(){
	listCommands = (struct ListCommand *) malloc(sizeof(ListCommand));
	listCommands->tam = 0;
}

void initPipeList(){
	pipeCommands = (struct ListPipeCommand *) malloc(sizeof(ListPipeCommand));
	pipeCommands->tam = 0;
}

void addPipeCommand(PipeCommand * c1){
	//printf("ADD PIPE COMMAND: Voy a añadir el comando: %s", c->command[0]);
	if (pipeCommands->tam == 0) {
				c1->nextCommand = NULL;
				c1->prevCommand = NULL;
				pipeCommands->first = pipeCommands->last = (struct PipeCommand *)c1;
				pipeCommands->tam++;
	} else {
			PipeCommand * last = (struct PipeCommand *)pipeCommands->last;
			//intf("Commando last: %s \n", last->command);
			if (last != NULL){
					c1->nextCommand = NULL;
					c1->prevCommand = pipeCommands->last;
					pipeCommands->last->nextCommand = c1;
					pipeCommands->last = c1;
					pipeCommands->tam++;
			}
	} 
}

void addCommand(Command * c1){
		
		if (listCommands->tam == 0) {
				//printf("Entro por aquí a añadir el primero\n");
				//printf("Primer comando añadido\n");
				c1->nextCommand = NULL;
				c1->prevCommand = NULL;
				listCommands->first = listCommands->last = (struct Command *)c1;
				listCommands->tam++;
		} else {
			Command * last = (struct Command *)listCommands->last;
			//intf("Commando last: %s \n", last->command);
			if ((struct Command *)last != NULL){
				if (equals((struct  Command *)c1, (struct Command *)listCommands->last) != 0){
					//printf("Más de un elemento añadido, tamaño de la lista: %i\n", listCommands->tam);
					c1->nextCommand = NULL;
					c1->prevCommand = (struct Command *)listCommands->last;
					listCommands->last->nextCommand = (struct Command *)c1;
					listCommands->last = (struct Command *)c1;
					listCommands->tam++;
				}  else {
					//printf("Eran iguales junto al último\n");
				}
				//printf("Toy por aquí, tamaño lista: %i\n", listCommands->tam)
			}
		} 
		//intf("Commando last: %s\n", listCommands->last->command);
		//printf("Commando first: %s\n", listCommands->first->command);
		//printf("ADD COMMAND: SALGO\n");
}

void showCommands(){
	printf("-------------------SHOW COMMANDS-------------------\n");
	printf("Command\n");
	Command * c3 = (struct Command *)malloc(sizeof(Command));
	if (listCommands->tam > 0 && listCommands->first != NULL){
		c3 = (struct Command *)listCommands->first; 	
		for (; c3 != NULL; c3 = (struct Command *)c3->nextCommand){
			if (c3->command != NULL)
					printf("%s \n", c3->command);
		}
	}
	
	free(c3);
	c3 = NULL;
	printf("Termino showCommands\n");
}

/*void showPipe(){
	printf("-------------------SHOW PIPE-------------------\n");
	printf("Command\n");
	Command * c3;
	if (pipeCommands->tam > 0 && pipeCommands->first != NULL){
		c3 = (struct Command *)pipeCommands->first; 	
		for (; c3 != NULL; c3 = (struct Command *)c3->nextCommand){
			if (c3->command != NULL)
					printf("%s \n", c3->command);
		}
	}
	printf("Termino showPipe\n");
}*/

void showPipe(){
	printf("-------------------SHOW PIPE-------------------\n");
	printf("Command\n");
	PipeCommand * c3;
	if (pipeCommands->tam > 0 && pipeCommands->first != NULL){
		c3 = (struct PipeCommand *)pipeCommands->first; 	
		for (; c3 != NULL; c3 = (struct PipeCommand *)c3->nextCommand){
			int i;
			i = 0;
			printf("{");
			while (c3->command[i] != NULL){
				printf("%s,", c3->command[i]);
				i++;
			}
			printf("}\n");
		}
	}
}

int getCommandsTam(){
	return listCommands->tam;
}

struct Command * getCommand(int elem){
	if (elem == 0)
		return NULL;
	Command * _elem = (struct Command *)listCommands->last;
	int i;
	for (i = 1; i<elem; i++)
		_elem = (struct Command *)_elem->prevCommand;
	return _elem;
}

ListCommand * getCommands(){
	return listCommands;
}


void freeList(){
	while (listCommands->last != NULL){
		free(listCommands->last->command);
		listCommands->last->command = NULL;
		listCommands->last = listCommands->last->prevCommand;
		if (listCommands->last != NULL){
			free(listCommands->last->nextCommand);
			listCommands->last->nextCommand = NULL;
		} else{
			free(listCommands->first);
			listCommands->first = NULL;
		}
		listCommands->tam--;
	}

}


void freePipe(){
	while (pipeCommands->last != NULL){
		free(pipeCommands->last->command);
		pipeCommands->last->command = NULL;
		pipeCommands->last = pipeCommands->last->prevCommand;
		if (pipeCommands->last != NULL){
			free(pipeCommands->last->nextCommand);
			pipeCommands->last->nextCommand = NULL;
		} else{
			free(pipeCommands->first);
			pipeCommands->first = NULL;
		}
		pipeCommands->tam--;
	}
}