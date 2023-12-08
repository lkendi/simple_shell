#include "headers.h"


void execute(char *user_command)
{
	pid_t child;

	/*Create a child process*/
	child = fork();

	if (child < 0)
	{
		perror("fork failure");
		exit(EXIT_FAILURE);
	}
	else if (child > 0)
	{



	}
	else
	{
		/*Execute the child process*/
		execve(user_command, (char *[]){user_command, NULL}, (char *[]{NULL});
		perror("execve");
		exit(EXIT_FAILURE);
	}



}
