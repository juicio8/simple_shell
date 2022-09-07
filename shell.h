#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/* Globalvariable */
extern char **environ;

/* Macros*/
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c,_strlen(c)))
#define PROMPT "$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* Struct */
/**
 * struct sh_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environment
 * 
 * Description: A structure contains all the variables needed to manage the program, 
 * memory, and accesabiliy
 */
typedef struct sh_data
{
    char *line;
    char **args;
    char *cmd;
    char *error_msg;
    char *oldpwd;
    unsigned long int index;
    char *env;
} sh_t;
/**
 * struct builtin - Manage the buitin functions
 * @cmd: the command line on string form
 * @f: the associated function
 * 
 * Description: this struct made to manage builtins cmd
 */
typedef struct builtin
{
    char *cmd;
    int (*f)(sh_t *data);
} blt_t;

/* --------Process prototype -------*/
int read_line(sh_t *);
int split_line(sh_t *);
int parse_line(sh_t *);
int process_cmd(sh_t *);
/* ------String prototype ------- */
char *_strcat(char *first, char *second)
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
