#include "simple.h"

static void sig_handler(int uuv)
{
	(void) uuv;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}

int main(int ac ___attribute__((unused)), char **av__attribute((unused)))
{
	int int_mode;
	char *line;
	char **args;

	signal(SIGINT, sig_handler);
	int_mode = isatty(STDIN_FILENO);

	while(1)
	{
		PRINT("$ ");
		line = read_line();
		args = split_line(line);
		

	}
}
char *read_line() 
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);
	return line;
}
#define DELIMITER " \n\t\r\a\v"
char **split_line(char *line)
{
	char *token = NULL;
	char **args = NULL;
	int toksize = 0;
 
	token = strtok(line, DELIMETER);
	while (token != NULL)
	{
		args[toksize] = strdup(token);
		token = strtok(NULL, DELIMETER);

	}
	args[toksize] = NULL;
	return args;
	
	
}

