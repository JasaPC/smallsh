#ifndef __BGPROC_H
#define __BGPROC_H

/**
 * @file bgproc.h
 * @author José Ángel
 * @date 17 May 2016
 */

/**
 * @brief Muestra los procesos en segundo plano, haciendo uso de la lista activa de procesos.
 * @return 
 */
void bgproc_showProcesses();

/**
 * @brief Comprueba si el comando es un proceso interno, o creado.
 * @return 0, si es interno, 1 si no.
 * @note, Comprobar si se sigue usando.
 */
int bgproc_isInternProcess(char *);

#endif
