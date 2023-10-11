#ifndef SHELL_H
#define SHELL_H


/*
 * File: shell.h
 * Auth: tazy-dev and minatalla sabri
 * Desc: Header file containing prototypes for all functions
 *       written in the simple_shell directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define DELIMITER " \n\t"
extern char **environ;

/*main Function*/
int shell(int, char **);

/*Simple functions*/
char *read_command();
char **tokenize_command(char *);
int execute_command(char **, char **);
void free_command(char **);
#endif
