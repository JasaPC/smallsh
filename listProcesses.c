#include "smallsh.h"

void initList(){	
	lista = (ListProcess*) malloc(sizeof(ListProcess));
	lista->tam = 0;
}

void addProcess(Process * p1) {
	Process * p = (struct Process *)malloc(sizeof(struct Process));
	p = p1;
	p->nameCommand = (char *)strdup(p1->nameCommand);
	if (lista->tam == 0) {
		if (lista->first == NULL){
			p->nextProcess = NULL;
			p->prevProcess = NULL;
			lista->first = p;
			lista->last = p;
		}
	} else {
		p->nextProcess = NULL;
		p->prevProcess = lista->last;
		lista->last->nextProcess = p;
		lista->last = p;
	}
	lista->tam++;
}

void deleteProcess(int pid){
	Process * p = (struct Process *)malloc(sizeof(struct Process));
	p = lista->first;
	for (; p != NULL; p = p->nextProcess){
		//Si el pid coincide con p
		if (p->PID == pid){
			if (p == lista->first) 
				lista->first = p->nextProcess;
			if (p == lista->last)
				lista->last = p->prevProcess;
			if (p->nextProcess != NULL)
				p->nextProcess->prevProcess = p->prevProcess;
			if (p->prevProcess != NULL)
				p->prevProcess->nextProcess = p->nextProcess;

			lista->tam--;
			if (lista->tam == 0){
				free(lista->first);
				free(lista->last);
				lista->first = lista->last = NULL;
			}
			//free(p);
			//p = NULL;
			return;
		}
	}
	
	

}


int getNumProcesses(){
	return lista->tam;
}


Process* getProcess(int pid) {
	struct Process * p = lista->first;
	for (; p!=NULL; p = p->nextProcess) {
		if (p->PID == pid) {
			return p;
		}
	}
	return NULL;
}

int getTam(){
	return lista->tam;
}

void showProcesses() {
	if (lista != NULL && lista->tam > 0){
		int i = 0;
		printf("---------SHOW PROCESSES----------\n");
		printf("Command/IP\t\t%24s\t\t\tActive Time\t\tLeft Time \n","Init Date");
		Process * process = lista->first;
		if (process != NULL && lista->tam > 0){
			for (; process != NULL; process = process->nextProcess) {
				if (process != NULL){
					getInfo(process);
					i++;
				} else return;
			}
		} else return;
	} else {
		printf("---------NO PROCESSES---------\n");
	}
}

/** Mata todos los procesos cuya alarma haya sido sobrepasada */

void killAlarm(){
	struct Process * process = (struct Process *) malloc(sizeof(struct Process));
	process = lista->first;
	if (process != NULL && lista->tam > 0){
		for (; process != NULL; process = process->nextProcess){
			//printf("Proceso: tiempo de vida: %i segundos\n", getTimeLeft(process));
			if (process->alarmActive == 0 && getTimeLeft(process) <= 0){
				kill(process->PID, SIGKILL); //Lanzamos al proceso con PID, la señal SIGKILL
				usleep(1);
			}
		}
	}
	free(process);
}

void deleteAll(){
	struct Process * process = (struct Process *) malloc(sizeof(struct Process));

	if (lista != NULL && lista->tam > 0){
		process = lista->first;
		for (; process != NULL ; process = process->nextProcess){
			printf("Mando SIGKILL al proceso: %i\n", process->PID);
			kill(process->PID, SIGKILL);
			usleep(1);
		}
	}
	//printf("Salgo de los procesos \n");
	free(process);
}

/** Esta función obtiene el proceso con la alarma con el menor tiempo de vida **/

int getFirstAlarm(){
	int time = -1;
	int first = 0;
	struct Process * process = lista->first;
	for (; process != NULL; process = process->nextProcess){
		if (process->alarmActive == 0) {
			if (first == 0){
				time = getTimeLeft(process);
				first = 1;
			} else if (getTimeLeft(process) < time)
				time = getTimeLeft(process);
		}
	}
	return time;
}


/** Esta función elimina todos los procesos de la lista**/

void freeProcesses(){
	while (lista->last != NULL){
		lista->last = lista->last->prevProcess;
		if (lista->last != NULL){
			free(lista->last->nextProcess);
			lista->last->nextProcess = NULL;
		} else{
			free(lista->first);
			lista->first = NULL;
		}
		lista->tam--;
	}
} //Elimina todos los procesos de la lista





