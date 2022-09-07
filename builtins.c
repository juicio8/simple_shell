#include "shell.h"

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * change_dir - changes director
 * @data: a pointer to the data struct
 * 
 * Return: (Success) 0 is returned
 * --------(Fail) negative number will be returned
 */
int change_dir(sh_t *data)
{
    char *home;

    home = _getenv("HOME");
    if (data->args[1] == NULL)
    {
        SETOWD(data->oldpwd);
        if (chdir(home) < 0)
            return (FAIL);
        return (SUCCESS);
    }
    if (_strcmp(data->args[1], "-") == 0)
    {
        if (data->oldpwd == 0)
        {
            SETOWD(data->oldpwd);
            if (chdir(home) < 0)
                return (FAIL);
        }
        }
        else
        {
            SETOWD(data->oldpwd);
            if (chdir(oldpwd) < 0)
                return (FAIL);
        }

    else
    {
        SETOWD(data->oldpwd);
        if (chdir(data->args[1]) < 0)
            return (FAIL);
    }
    return (SUCCESS);
}
#undef GETCWD
/**
 * abort_prg - exit the program
 * @data: a pointer to the data structure
 * 
 * Return: (Success) 0 is returned
 * --------(Fail) negative number will returned
 * 
 */
int abort_prg(sh_t *data _attribute_((unused)))
{
    int code, i = 0;

    if (data->args[1] == NULL)
    {
        free_data(data);
        exit(errno);
    }
    while (data->args[1[i]])
    {
        if (_isalpha(data->args[i][i++] < 0)
        {
            data->error_msg = _strdup("Illegal number\n");
            return(FAIL);
        }

    }
    code = _atoi(data->args[1]);
    free_datat(data)
    exit(code); 
    
} 
/**
 * display_help - display the help menu
 * @date: a pointer to the data structure
 * 
 * Return: (Success)
 * --------(Fail)
 */
int display_help(sh_t *data)
{
    int fd, fw, rd = 1;
    char c;

    fd = open(data->args[1], O_RDONLY);
    if (fd < 0)
    {
        data->error_msg = _strdup("no help topics match\n");
        return (FAIL);
    }
    while (rd > 0)
    {
        rd = read(fd, &c, 1);
        fw = write(STDOUT_FILENO, &c, rd);
        if (fw < 0)
        {
            data->error_msg = _strdup
        }
    }
}





}  
