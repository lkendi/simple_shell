#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/*Function prototypes*/
void execute(char **args);
char *get_command_path(char *command);