#include "header.h"

void execute(char **args)
{
    char *cmd = NULL; /*the actual command before any arguments*/
    char *cmd_path = NULL; /*get path to the command*/
    if (args != NULL)
    {
        /*command is the first element in args*/
        cmd = args[0];

        /*command path*/
        cmd_path = get_command_path(cmd);

        /*execute the command*/
        if (execve(cmd_path, args, NULL) == -1)
        {
            perror("error:");
        }
    }
}