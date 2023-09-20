#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * struct command - struct that holds the command name and arguments passed.
 * @cmd: command name.
 * @args: arguments passed to the program.
 * @Gline: pointer to the full command
 * @prog_name: name the program called
 * @c_cmd_num: the cumulative number of given commands
 */

typedef struct command
{
	char *cmd;
	char **args;
	char *Gline;
	char *prog_name;
	int c_cmd_num;
} full_cmd;

/**
 * struct built_in_t - struct for in-built name
 * @name: built-in name.
 * @func: function pointer of the built-in.
 */

typedef struct built_in_t
{
	char *name;
	void (*func)(full_cmd);
} builtin_t;

extern char **environ;

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
char *_strcpy(char *dest, char *src);

char **tokenize(char *string);
ssize_t get_input(char **line, size_t *buffsize);
void print_prompt(void);
full_cmd get_args(char *line);
void _free(void *p1, ...);
char *_which(full_cmd);
void print_err_m(char *exe_name, int c);
int exec_cmd(full_cmd c);
char **tokenize(char *string);
char *get_envpath(void);
void print_notfound(char *prog_name, int c, char *cmd);

void Print_env(full_cmd c);
void sh_exit(full_cmd c);
int built_in(full_cmd c);
#endif /* SHELL_H */
