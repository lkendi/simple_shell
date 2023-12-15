#include "headers.h"

/**
 * env_command - handles the builtin env command
 * Return: nothing
*/

void env_command(void)
{
	char **env = NULL;
	int count = 0, i = 0;

	env = malloc((count + 1) * sizeof(char *));
	if (env == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	while (__environ[count] != NULL)
		count++;
	while (i < count)
	{
		env[i] = strdup(__environ[i]);
		if (env[i] == NULL)
		{
			perror("strdup error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	env[count] = NULL;
	while (env)
	{
		printf("%s\n", env[i]);
		free(env[i]);
		i++;
	}
	free(env);
}
