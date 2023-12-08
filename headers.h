#ifndef MAINHEADER_FILE_
#define MAINHEADER_FILE_

/**HEADER FILES*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include <stdbool.h>
#include <sys/wait.h>
=======
#include <sys/types.h>


>>>>>>> 7df50e0 (debugging execute.c)



/**STRUCTURES*/





/**FUNCTION PROTOTYPES*/
void display_prompt();
char *get_command(char *user_command);
void execute(char *user_command);


#endif
