#ifndef MAINHEADER_FILE_
#define MAINHEADER_FILE_

/**HEADER FILES*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


/**FUNCTION PROTOTYPES*/
void _prompt(void);
char **get_command(void);
char *get_command_path(char *user_command);
void _execute(char **args);
char **_tokenize(char *input_copy);
void _free(char **args);
void _uncomment(char *str);
void env_command(void);
void exit_command(char *cmd_path, char **args);
void handle_cd(char *dir);

#endif
