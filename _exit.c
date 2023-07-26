#include "shell.h"

/**
* built_in_exit - exit of the program with the status
* @data: struct for the program's data
* Return: zero if sucess, or other number if its declared in the arguments
*/
int built_in_exit(Infos *data)
{
	int status;

	if (data->args[1] != NULL)
	{
		status = _atoi(data->args[1]);
		exit(status);
	}
	else
	{
		exit(0);
	}
	return (0);
}


/**
* display_env - Display the env
* Return: Nothing
*/
int display_env(void)
{
	char **env, **envp = environ;

	for (env = envp; *env != NULL; env++)
		printf("%s\n", *env);

	return (0);
}



