#include "shell.h"
/**
 * is_path_form - check if the given filename is a path
 * @data: the data struct pointer
 * Return: (Success), otherwise (Fail)
 */
int is_path_form(sh_t *data)
{
    if (_strchr(data->args[0], '/') != 0)
    {
            data->cmd = _strdup(data->args[0]);
            return (SUCCESS);
    }
    return (FAIL);
}
#define DELIMETER ":"
/**
 * is_short_form - check if the given filename is short form
 * @dsta: the data structure
 * 
 */