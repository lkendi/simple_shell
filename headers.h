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



/**STRUCTURES*/





/**FUNCTION PROTOTYPES*/
void display_prompt(void);
char **get_command(void);
char *get_command_path(char *user_command);
void _execute(char **args);

/*not in use currently*/
char *get_cmd(char *user_command);
void execute(char *user_command);
char *get_command_path(char *user_command);
#endif
