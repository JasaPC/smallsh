#ifndef __LIST_PROC_H
#define __LIST_PROC_H
#include "process.h"

/**
 * @file listProcesses.h
 * @author José Ángel
 * @date 17 May 2016
 */

 /**
 * @brief Tipo de datos ListProcess.
 *
 * Estructura ListProcess, que contiene punteros al primer y último elemento,
 * y el tamaño de la lista.
 * @note, comprobar si utilizamos el nameCommand.
 */

typedef struct ListProcess {
	char * nameCommand; //Nombre de la orden
	struct Process * first;
	struct Process * last; //Primer proceso
	int tam; 
} ListProcess;

ListProcess * lista;
/**
 * @brief Inicializa la lista de procesos lista.
 * @return 
 */
void initList(); 
/**
 * @brief Añade un proceso Process a la lista lista.
 * @return 
 */
void addProcess(Process *); 
/**
 * @brief Elimina un proceso de la lista de procesos.
 * @param pid, el entero del elemento a ser eliminado (pid)
 * @return 
 */
void deleteProcess(int pid); //Elimina un proceso con un pid
/**
 * @brief Obtiene a un proceso de la lista de procesos.
 * @param pid, el entero del elemento a ser buscado (pid)
 * @return Process, el proceso.
 */
Process *  getProcess(int pid); //Obtiene un proceso con pid 
/**
 * @brief Muestra el contenido de la lista de procesos.
 * @return 
 */
void showProcesses(); 
/**
 * @brief Mata los procesos cuya alarma ha sido sobrepasada.
 * @return 
 */
void killAlarm(); 
/**
 * @brief Obtiene la siguiente alarma que va a ser activada.
 * @return 
 */
int getFirstAlarm();
/**
 * @brief Mata a todos los procesos de la lista de procesos.
 * @return 
 */
void deleteAll(); 
/**
 * @brief Elimina todos los procesos de la lista.
 * @return 
 */
void freeProcesses();

#endif
