#include "shell.h"

/**
 * init_path - Initialize the path
 * @data: A set of informations
 * Return: Nothing
*/
void init_path(Infos *data)
{
	data->PATH = malloc(8 * sizeof(char *));

	if (data->PATH == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	data->PATH[0] = strdup("/usr/local/sbin");
	data->PATH[1] = strdup("/usr/local/bin");
	data->PATH[2] = strdup("/usr/sbin");
	data->PATH[3] = strdup("/usr/bin");
	data->PATH[4] = strdup("/sbin");
	data->PATH[5] = strdup("/bin");
	data->PATH[6] = strdup("");
	data->PATH[7] = NULL;
}



/**
 * free_path - Free ...
 * @data: A set of data
 * Return: Nothing
*/
void free_path(Infos *data)
{
	int i;

	for (i = 0; i < 7; i++)
	{
		free(data->PATH[i]);
	}
	free(data->PATH);
}



/**
 * initialize_data - inicialize the struct with the infos of the program
 * @data: pointer to the structure of data
 * @argv: array of arguments pased to the program execution
 * @argc: number of values received from the command line
 */
void initialize_data(Infos *data, int argc, char *argv[])
{
	int env_size = 0, i;

	data->line_buffer_size = malloc(sizeof(size_t));
	if (!data->line_buffer_size)
	{
		perror("Failed to allocate memory for line_buffer_size");
		exit(EXIT_FAILURE);
	}
	*data->line_buffer_size = 0;

	init_path(data);
	data->program_name = strdup(argv[0]);
	data->input_line = malloc(sizeof(char) * 256);
	data->curdir = NULL;
	data->lastdir = NULL;
	data->nb_arg = 0;
	while (environ[env_size] != NULL)
		env_size++;
	data->env = malloc(sizeof(char *) * (env_size + 1));
	if (data->env == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < env_size; i++)
		data->env[i] = strdup(environ[i]);
	data->env[env_size] = NULL;
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}
	}
}



/**
 * free_data - free the data
 * @data: A set of informations
 * Return: Nothing
*/
void free_data(Infos *data)
{
	int i = 0;

	free_path(data);
	free(data->program_name);
	free(data->input_line);
	free(data->curdir);
	free(data->lastdir);

	while (data->env[i] != NULL)
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
}






