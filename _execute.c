#include "headers.h"


void handle_execve_failure(char *cmd_path, char **args);
void handle_command_not_found(char *cmd_path, char **args,
char *cmd, int cmd_count);
void handle_fork_failure(char *cmd_path);
void exit_command(char *cmd_path, char **args);

/**
* handle_execve_failure - handles execve failure
* @cmd_path: command path
* @args: command arguments
*
*/
void handle_execve_failure(char *cmd_path, char **args)
{
	perror("execve");
	free(cmd_path);
	_free(args);
	exit(EXIT_FAILURE);
}

/**
* handle_command_not_found - handles the case when the command is not found
* @cmd_path: command path
* @args: command arguments
* @cmd: command name
* @cmd_count: command count
* Return: nothing
*/
void handle_command_not_found(char *cmd_path, char **args,
char *cmd, int cmd_count)
{
	fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_count, cmd);
	free(cmd_path);
	_free(args);
	exit(127);
}
/**
* handle_fork_failure - handle fork failure
* @cmd_path: command path
*/

void handle_fork_failure(char *cmd_path)
{
	perror("fork");
	free(cmd_path);
	exit(EXIT_FAILURE);
}

/**
 * exit_command - exits the shell
 * @cmd_path: previous command path
 * @args: command arguments
 * Return: nothing
*/
void exit_command(char *cmd_path, char **args)
{
	free(cmd_path);
	_free(args);
	exit(EXIT_SUCCESS);
}

/**
* _execute - executing the command
* @args: command input from the user
* Return: nothing
*/
void _execute(char **args)
{
	pid_t child;
	char *cmd = NULL, *cmd_path = NULL;
	int cmd_count = 1;

	if (args == NULL)
		return;
	cmd = args[0];
	cmd_path = (cmd[0] == '/') ? strdup(cmd) : get_command_path(cmd);
	if (strcmp(cmd, "exit") == 0)
		exit_command(cmd_path, args);
	if (cmd_path != NULL)
	{
		child = fork();
		if (child < 0)
			handle_fork_failure(cmd_path);
		else if (child == 0)
		{
			if (execve(cmd_path, args, __environ) == -1)
				handle_execve_failure(cmd_path, args);

			free(cmd_path);
			_free(args);
			_exit(0);
		}
		else if (child > 0)
		{
			wait(NULL);
			free(cmd_path);
		}
		cmd_count++;
	}
	else
	{
		handle_command_not_found(cmd_path, args, cmd, cmd_count);
		cmd_count++;
	}
}
