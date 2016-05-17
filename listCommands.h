#ifndef __LIST_COM_H
#define __LIST_COM_H
#include "command.h"

/**
 * @file listCommands.h
 * @author José Ángel
 * @date 17 May 2016
 */

 /**
 * @brief Tipo de datos ListCommand.
 *
 * Estructura ListCommand, que contiene punteros al primer y último elemento,
 * y el tamaño de la lista.
 */

typedef struct ListCommand {
	struct Command * first;
	struct Command * last; //Primer proceso
	int tam; 
} ListCommand;


 /**
 * @brief Tipo de datos ListPipeCommand.
 *
 * Estructura ListPipeCommand, que contiene punteros al primer y último elemento,
 * y el tamaño de la lista.
 */

typedef struct ListPipeCommand {
	struct PipeCommand * first;
	struct PipeCommand * last; //Primer proceso
	int tam; 
} ListPipeCommand;

ListCommand * listCommands;
ListPipeCommand * pipeCommands;

/**
 * @brief Inicializa la lista de comandos listCommands.
 * @return 
 */
void initCommandsList();
/**
 * @brief Inicializa la lista de comandos de pipe pipeCommands.
 * @return 
 */
void initPipeList();
/**
 * @brief Añade un comando Command a la lista listCommands.
 * @return 
 */
void addCommand(Command *);
/**
 * @brief Añade un comando PipeCommand a la lista pipeCommands.
 * @return 
 */
void addPipeCommand(PipeCommand *);
//Command *  getCommand();
/**
 * @brief Muestra el contenido de la lista listCommands.
 * @return 
 */
void showCommands();
/**
 * @brief Muestra el contenido de la lista pipeCommands.
 * @return 
 */
void showPipe();
/**
 * @brief Libera el contenido de la lista listCommands.
 * @return 
 */
void freeList();
/**
 * @brief Libera el contenido de la lista pipeCommands.
 * @return 
 */
void freePipe();
ListCommand * getCommands();
int getCommandsTam();
/**
 * @brief Obtiene el comando correspondiente al elemento actual.
 * @param el entero del elemento a ser buscado.
 * @return Command, el comando encontrado o NULL si no se encuentra.
 */
Command * getCommand(int);
#endif