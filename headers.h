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

/**FUNCTION PROTOTYPES*/
void _prompt(void);
char **get_command(void);
char *get_command_path(char *user_command);
void _execute(char **args);


#endif
