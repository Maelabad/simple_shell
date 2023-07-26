#include "shell.h"


/**
 * handle_args - ...
 * @info: A set of information
 * Return: Nothing
*/
void handle_args(Infos *info)
{
	char *token;
	int i = 0;
	int stop_reading = 0;

	token = _strtok(info->input_line, " ");
	while (token != NULL && i < MAX_ARGS && stop_reading == 0)
	{
		if (token[0] == '#')
		{
			stop_reading = 1;
			break;
		}
		info->args[i++] = token;
		token = _strtok(NULL, " ");
	}
	info->nb_arg = i;
	info->args[i] = NULL;
}



/**
 * execute_command - Execute the commamds
 * @arguments: The args
 * Return: Nothing
*/
void execute_command(char **arguments)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork failed");
		return;
	}
	else if (pid == 0)
	{
		execvp(arguments[0], arguments);
		perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			/*exit_status = WEXITSTATUS(status);*/
			WEXITSTATUS(status);

		}
	}
}



/**
 * handle_path - Check each possibility for path
 * @data: A set of informations
 * Return: 1 or 0
*/
int handle_path(Infos *data)
{
	int i, j;
	char *path = (char *)malloc(sizeof(char) * MAX_COMMAND_LENGTH);

	for (i = 0; data->PATH[i] != NULL; i++)
	{
		strcpy(path, data->PATH[i]);
		strcat(path, "/");
		strcat(path, data->args[0]);
		if (access(path, X_OK) == 0)
		{
			char **args = (char **)malloc(sizeof(char *) * (MAX_ARGS + 1));

			for (j = 0; data->args[j] != NULL; j++)
			{
				args[j] = data->args[j];
			}
			args[j] = NULL;

			execute_command(args);
			free(args);
			free(path);
			return (1);
		}
	}

	fprintf(stderr, "%s: command not found\n", data->args[0]);
	free(path);
	return (0);
}




/**
 * execute - Execute the commamds
 * @data: A set of informations
 * Return: 0 or 1
*/
int execute(Infos *data)
{
	handle_args(data);
	if (data->nb_arg == 0)
		return (0);

	if (_strcmp(data->args[0], "exit") == 0)
		return (built_in_exit(data));
	else if (_strcmp(data->args[0], "env") == 0)
		return (display_env());
	else if (_strcmp(data->args[0], "cd") == 0)
		return (_cd(data));
	else
		return (handle_path(data));
	return (1);
}

