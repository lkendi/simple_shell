#include "headers.h"

/**
* execute - execute command
* @user_command: user command
*/
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
		/*Parent process*/
		wait(NULL);
	}
	else
	{
		/*Execute the child process*/
		char *args[] = {user_command, NULL};

		execve(user_command, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
