#ifndef __COM_H
#define __COM_H
#include "smallsh.h"

/**
 * @file command.h
 * @author José Ángel
 * @date 17 May 2016
 */

/**
 * @brief Tipo de datos Command.
 *
 * Estructura Command, que contiene una cadena con el comando,
 * y punteros al próximo comando y al previo.
 */

typedef struct Command {
	char * command;
	struct Command * nextCommand;
	struct Command * prevCommand;
} Command;

/**
 * @brief Tipo de datos PipeCommand.
 *
 * Estructura Command, que contiene un array de cadenas con el comando
 * separado en distintas posiciones,
 * y punteros al próximo comando y al previo.
 */

typedef struct PipeCommand{
	char * * command ; //Array de comandos
	struct PipeCommand * nextCommand;
	struct PipeCommand * prevCommand;
} PipeCommand;

/**
 * @brief Tipo de datos PipeCommand.
 *
 * Estructura Command, que contiene un array de cadenas con el comando
 * separado en distintas posiciones,
 * y punteros al próximo comando y al previo.
 * @return Command *, el comando creado para ser añadido a la lista.
 */
Command * createCommand(const char *);

/**
 * @brief Tipo de datos PipeCommand.
 *
 * Estructura Command, que contiene un array de cadenas con el comando
 * separado en distintas posiciones,
 * y punteros al próximo comando y al previo.
 * @note La última modificación el segundo comando no se utiliza, 
 * ya que siempre utilizamos el último de la lista
 * @return 0, si los comandos son iguales, 1 en otro caso.
 */
int equals(struct Command *, struct Command *);


#endif