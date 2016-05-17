#ifndef __PROC_H
#define __PROC_H

/**
 * @file process.h
 * @author José Ángel
 * @date 17 May 2016
 */

 /**
 * @brief Tipo de datos Process.
 *
 * Estructura Process, que identifica a un proceso junto con los campos necesarios,
 * además de punteros a dos procesos (previo y siguiente) en caso de ser necesario su acceso.
 */


typedef struct Process {
	char * nameCommand; //Nombre de la orden
	struct tm * initDate; //Fecha de inicio
	time_t initTime; //Fecha de inicio(segundos);
	struct tm * currentTime; //Tiempo en segundos que lleva el proceso activo
	int timeLife; //Tiempo para su expiración
	int PID; //Pid del proceso
	struct Process * nextProcess; //siguiente proceso de la lista
	struct Process * prevProcess; //proceso previo en la lista de procesos
	int alarmActive; //indica si un proceso tiene una alarma establecida
} Process;

/**
 * @brief Devuelve el tiempo activo de un proceso.
 * @param, Process, el proceso del cual queremos obtener el tiempo que lleva activo
 * @return int, el tiempo que lleva activo
 */
int getActiveTime(const Process *);
/**
 * @brief Devuelve el tiempo restante de un proceso.
 * @param, Process, el proceso del cual queremos obtener el tiempo restante.
 * @return int, el tiempo restante
 */
int getTimeLeft(const Process *);
/**
 * @brief Indica si el proceso tiene una alarma activa.
 * @param, Process, el proceso del cual queremos ver si tiene alarma activa.
 * @return int, indica si tiene alarma (0) o no (1)
 */
int getAlarm(const Process *);
/**
 * @note comprobar si se usa
 */
int getTimeLeftAlarm(const Process *);
/**
 * @brief Obtiene la información necesaria de un proceso.
 * @param, Process, el proceso del cual queremos ver su información.
 * @return
 */
void getInfo(const Process *);
/**
 * @brief Establece una alarma para un proceso.
 * @param, Process, el proceso del cual vamos a establecer una alarma.
 * @return
 */
void setAlarm(Process *);

#endif