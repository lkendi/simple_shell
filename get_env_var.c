#include "headers.h"

/**
 * get_env_var - gets the value of an environment variable
 * @var: name of the environment variable
 * Return: <TBD>
 */

char *get_env_var(const char *var)
{
        extern char **environment;
        char **current_env;
        char *token;

        if (var == NULL)
        {
                return (NULL);
        }

        current_env = env_vars;
        while (current_env != NULL)
        {
                token = strtok(current_env, "=");
                if (token != NULL)
                {
                        if (strcmp(var, token) == 0)
                        {
                                return (strtok(NULL, "="));
                        }
                }
                current_env++;
        }
        return (NULL);
}

