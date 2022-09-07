#include "shell.h"
/**
* main - the main function
* Return: (Success) 0 always
* --------(fail) we drop out the looser
*/
int main(void)
{
    sh_t data; /* creates a new struct */
    int pl;

    _memst((void *)&data, 0, sizeof(data)); /* filling struct data with 0 */
    signal(SIGINT, signal_handler); /* checks for ^C */
    while (1) /* a repeated loop */
    {
        index_cmd(&data); /* increment index in struct */
        if (read_line(&data) < 0)/*reads line*/
        {
            if (isatty(STDIN_FILENO))
                PRINT("\n");
                break;
        }
        if (split_line(&data) < 0)/* splitss data in fragments */
        {
            free_data(&data);/* if it fails free */
            continue;
        }
        pl = parse_line(&data);
        if (pl == 0)
        {
            free_data(&data);
            continue;
        }
        if (process_cmd(&data) < 0)
        {
            print_error(&data);
            break;
        }
        free_data(&data);
    }
    free_data(&data);
    exit(EXIT_SUCCESS);
}    
