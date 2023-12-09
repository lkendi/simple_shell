#include "header.h"

char *get_command_path(char *command)
{
    char *path, *path_duplicate;
    char *path_token;
    char *f_path;
    int c_length, d_length;
    struct stat stat_buffer;

    /*get the PATH env variable*/
    path = getenv("PATH");

    if (path != NULL)
    {
        /*Duplicate path*/
        path_duplicate = strdup(path);

        /*Get command length*/
        c_length = strlen(command);

        /*Tokenize path_duplicate to get all the directories available*/
        path_token = strtok(path_duplicate, ":");

        while (path_token != NULL)
        {
            /*length of directory in the current token*/
            d_length = strlen(path_token);

            /*to get the complete file path (command name + dir name) to each command*/
            f_path = malloc(c_length + d_length + 2);

            /*concat command to dir path*/
            strcpy(f_path, path_token);
            strcat(f_path, "/");
            strcat(f_path, command);
            strcat(f_path, "\0");


            if (stat(f_path, &stat_buffer) == 0)
            {
                /*valid file path */
                /*free up path_duplicate and return the file path*/
                free(path_duplicate);
                return(f_path);
            }

            else
            {
                /*free current path to check for another path*/
                free (f_path);
                path_token = strtok(NULL, ":");
            }
        }

            /*no existing file path*/
            free(path_duplicate);

            /*check if command itself is an existing path*/
            if (stat(command, &stat_buffer) == 0)
            {
                return (command);
            }
            return (NULL);
    }
    return (NULL); 
}