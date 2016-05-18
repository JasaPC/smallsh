#include "smallsh.h"

int getActiveTime(const Process * p){
	//Fecha actual menos la fecha en la que fue lanzado
	if (time(NULL) > p->initTime)
		return (time(NULL) - p->initTime);
	else return (p->initTime - time(NULL)); //time(NULL) es el tiempo en segundos
}

int getTimeLeft(const Process * p){
	//El tiempo que le queda al proceso, es el tiempo actual - (fecha de Inicio + timeLife).
	//Puede pasar que al crear el proceso, el tiempo actual sea igual al initData y por tanto
	//la operación daría un resultado negativo (en ese caso lo establecemos a 0.)
	if (time(NULL) > (p->initTime + p->timeLife)){
		return 0;
	} else {
		return (p->initTime + p->timeLife - time(NULL));

	}
	
}

int getAlarm(const Process * p){
	//Indica si un proceso tiene alarma
	return p->alarmActive;
}

void getInfo(Process * p){
	//Obtiene información sobre el proceso
	if (p != NULL) {
	    char * time_char = asctime(p->initDate);
	    time_char[strlen(time_char)-1] = ' ';
		printf("%7s/%5i,\t\t%s,\t\t%5i secs", strdup(p->nameCommand), p->PID, time_char, getActiveTime(p));
		if (p->alarmActive == 1)
				printf("\t\t0 secs \n");
		else printf(", \t\t%i secs \n", getTimeLeft(p));
	}
}

void setAlarm(Process * p1){
	p1->alarmActive = 1;
}



