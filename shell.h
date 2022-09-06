#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

char* read_line();
char **split_line(char *line);
int check_alias(char **args);
int checkin_path(char **args);
int check_builtins(char **args);
void excecute(char **args);
void alias_excecution(char **args);
void excecute(char **args);
void alias_excecution(char **args);

typedef struct ali {
	char *name;
	char *aliz;

} alias;
alias aliases[] = {
	{"ls", "ls --color=auto"},
	{"la", "ls -A"},
	{"ll", "ls -alF"},
	{NULL, NULL}
};
typedef struct bin {
	char *name;
	void (*func)(char **args);
} builtin;
builtin builtins[] = {
	{"exit", /*exit_func*/},
	{"env", /*env_funct*/},
	{NULL, NULL}
};

#endif
