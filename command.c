#include "smallsh.h"

struct Command * createCommand(const char * comando){
	Command * c = (struct Command *)malloc(sizeof(Command));
	c->command = strdup(comando);	//printf("Problema inicializar memoria\n");
	return c;
}

int equals(Command * c_, Command * c2_){
	Command * c1_ = (struct Command *)listCommands->last;
	printf("Comandos: %s , %s \n", c_->command, c1_->command );
	if (c_ == NULL || c1_ == NULL) return 0;	
	if (strcmp(c_->command, c1_->command) == 0) return 0;
	else return 1;

}