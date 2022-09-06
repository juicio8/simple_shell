#include "shell.h"
#include <sys/stat.h>
unsigned int sig_flag;
extern char **environ;

static void sig_handler(int uuv)
{
	(void) uuv;
	if (sig_flag == 0)
		printf("\n$ ");
	else
		printf("\n");
}
char **split_path(char *s);

int main(int ac __attribute__((unused)), char **av __attribute((unused)))
{
	int int_mode;
	char *line;
	char **args;

	signal(SIGINT, sig_handler);
	/*int_mode = isatty(STDIN_FILENO);*/

	while(1)
	{
		printf("$ ");
		line = read_line();
		args = split_line(line);
		excecute(args);
		free(line);
		free(args);
	}
}
char *read_line() 
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);
	return (line);
}
#define DELIMETER " \n\t\r\a\v"
char **split_line(char *line)
{
	char *token;
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char));
 
	token = strtok(line, DELIMETER);
	while (token != NULL)
	{
		tokens[length] = token;
		length++;
		if (length >= capacity)
		{	capacity = (capacity * 2);
			tokens = realloc(tokens, capacity * sizeof(char));
		}
		token = strtok(NULL, DELIMETER);

	}
	tokens[length] = NULL;
	return tokens;
	
}

int checkin_path(char **args)
{
	int x = 0;
	char *environ_tok;

	while (environ[x] != NULL)
	{
		if (strcmp(environ[x], "PATH") == 0)
		{
			char **envi;

			environ_tok = strdup(environ[x]);
			printf("%s\n", environ_tok);
			/*envi = split_line(environ_tok);*/
		}
		x++;
	}
	return (0);
}
void excecute(char **args)
{
/*	for (int i = 0; aliases[i].name != NULL; i++)
	{
		  if (strcmp(args[0], aliases[i].name) == 0)
                {
                        args[0] = strdup(aliases[i].aliz);
                        (alias_excecution(args));
			return;
                }	

	}
	for (int i = 0; builtins[i].name != NULL; i++)
	{
		  if (strcmp(args[0], aliases[i].name) == 0)
                {
                        free(args);
                        builtins[i].func;
			return;
                }
	}
	        int x = 0;*/
extern char **environ;
	char *path;
	int i = 0;
	char **dirs;
	char *cwd = getcwd(NULL, 0);
	struct stat sb;

	path = environ[12] + 5;
	dirs = split_path(path);
	while (dirs[i] != NULL)
	{
		chdir(dirs[i]);
		if (stat(args[0], &sb) == 0)
		{
			args[0] = strcat(dirs[i], args[0]);
			break;
		}
		i++;
	}
	chdir(cwd);
	printf("%s", args[0]);       

}
void alias_excecution(char **args) {
	return;
}
char **split_path(char *s)
{
	
	char *token;
        int length = 0;
        int capacity = 16;
        char **tokens = malloc(capacity * sizeof(char));

        token = strtok(s, ":");
        while (token != NULL)
        {
                tokens[length] = token;
                length++;

                if (length >= capacity)
                {       capacity = (capacity * 2);
                        tokens = realloc(tokens, capacity * sizeof(char));
                }
                token = strtok(NULL, ":");

        }
        tokens[length] = NULL;
        return tokens;
}
