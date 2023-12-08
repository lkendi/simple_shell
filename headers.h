#ifndef MAINHEADER_FILE_
#define MAINHEADER_FILE_

/**HEADER FILES*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>




/**STRUCTURES*/





/**FUNCTION PROTOTYPES*/
void display_prompt();
int get_command(char *user_command, size_t c_size);
void execute(char *user_command);


#endif
