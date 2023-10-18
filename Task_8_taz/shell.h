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
#include <sys/stat.h>

#define DELIMITER " \n\t"
#define BUFFER_SIZE 15000
extern char **environ;


/*main Functiond*/
int shell(int ac, char **av);

/*input_commands.c module*/
char *read_command();
char **tokenize_command(char *);

/*execute.c module*/
int execute_command(char **, char **, int);
void free_command(char **);
char *get_env_var(char *);
char *check_command_in_path(char *);

/*string_funcs.c module*/
size_t _strlen(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);

/*string_funcs_2.c module*/
char *_strchr(char *, int);
ssize_t _getline(char **, size_t *, FILE *);
char *_strdup_lim(char *, ssize_t);
int _is_pos_digit(char *);

/*utillity.c module*/
char *expand_command(char *, char *, size_t);
void _perror(char *, char *, int);
void print_number(int);
int _atoi(char *);
void exit_error(char *, char *, int);

/*shell_builtins.c*/
void exit_builtin(char **, char **, int *, int);
void env_builtin(void);
#endif
