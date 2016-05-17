/* -*- mode: C; c-basic-offset: 4; -*- */
#ifndef __SMALLSH_H
#define __SMALLSH_H

/* Definicion del buffer de tokens */
#include "gettok.h"

/* Funciones del usuario */
#include "userfn.h"

/* Funciones del buffer */
#include "buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "cmd/bgproc.h"
#include "cmd/directorio.h"
#include "listProcesses.h"
#include "time.h"
#include "process.h"
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "command.h"
#include "listCommands.h"

#define MAXARG 512

#define FOREGROUND 0
#define BACKGROUND 1
#define MAXCOMMAND 10

#define MODO_INTERPRETADO_ON 1
#define MODO_INTERPRETADO_OFF 0

/**
 * @file smallsh.h
 * @author José Ángel
 * @date 17 May 2016
 */

void procline(struct TokBuf*);
int runcommand(char *const *, unsigned);
/**
 * @brief runcommand_alarm, se utiliza cuando queremos llamar a un proceso en segundo plano estableciendo
 * una alarma, haciendo uso de la notación "@".
 * Ĺa funcionalidad es similar a runcommand, aunque necesitamos un parámetro más que simboliza el tiempo
 * de la alarma establecida.
 * la orden bgproc.
 * @return int, devuelve el código de salida de la operación.
 */
int runcommand_alarm(char *const *, unsigned, int);
/**
 * @brief runcommand_pipe, se utiliza cuando queremos llamar a una tubería.
 * Necesitamos recuperar todos los comandos de la tubería, para poder lanzarlos en correcto orden, y para ello
 * utilizamos las estructuras PipeCommand y ListPipeCommand. De esta manera, es más sencilla una correcta
 * organización de los comandos introducidos en el pipe actual y su lanzamiento.
 * @return int, devuelve el código de salida de la operación.
 */
int runcommand_pipe(char * const*cline);
/**
 * @brief runcommand_exit, se utiliza cuando queremos terminar la ejecución de smallsh.
 * Necesitamos eliminar todos los procesos que queden en segundo plano, y para ellos hacemos uso de la estructuras
 * ListProcess, Process para liberar la memoria de los procesos activos. 
 * @return int, devuelve el código de salida de la operación.
 */
int run_exit();
/**
 * @brief join, utilizada dentro de la función runcommand_pipe.
 * Es el encargado de procesar los comandos recogidos en la estructura ListPipeCommand, haciendo uso
 * de la función pipe() y fork() para un uso correcto.
 * @return int, devuelve el código de salida de la operación.
 */
int join();
/**
 * @brief Orden bgproc, visualización de comandos en segundo plano.
 * En esta orden, utilizamos una lista de comandos (ListCommand) para mostrar los procesos activos
 * en segundo plano.
 * @return void
 */
void run_bgproc();
/**
 * @brief Orden sleep, prueba para un proceso que simplemente se duerme.
 * En esta orden, utilizamos la orden sleep para dormir a un proceso y poder probar correctamente
 * la orden bgproc.
 * @return void
 */
void run_sleep();

void run_findByString(char * const*);
void run_cd(char * const*);
void setLastAlarm(int );
int getLastAlarm();
#endif
