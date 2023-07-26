#include "shell.h"

/**
 * separateInstructions - Separate the imput line
 * @data: The struct data
 * @input_line: The input line
 * Return: 0 or 1
*/
int separateInstructions(Infos *data, char *input_line)
{
	char *instructions[MAX_INSTRUCTIONS] = {0}, *input_copy;
	char *token;
	int num_instructions = 0, result = 0, i;
	/*Copie de la chaîne d'entrée car strtok modifie la chaîne originale*/
	/*char input_copy[_strlen(input_line) + 1];*/

	input_copy = malloc((_strlen(input_line) + 1) * sizeof(char));
	if (input_copy != NULL)
	{
		free(input_copy);
	}


	_strcpy(input_copy, input_line);

	/*Utilisation de strtok pour séparer les instructions basées sur ';'*/
	token = strtok(input_copy, ";");
	while (token != NULL && num_instructions < MAX_INSTRUCTIONS)
	{
		instructions[num_instructions++] = token;
		token = strtok(NULL, ";");
	}

	for (i = 0; i < num_instructions; i++)
	{
		data->input_line = instructions[i];
		result = execute(data);
	}
	return (result);
}


/**
 * non_interactive - For the non interactif mode
 * @data: A set of infos
 * @argv: A vector of args
 * Return: Nothing
*/
void non_interactive(Infos *data, char *argv[])
{
	char *line = NULL;
	ssize_t read;
	FILE *file;
	int status;

	file = fopen(argv[1], "r");
	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while ((read = _getline(&line, file)) != -1)
	{
		if (read == -1)
			break;
		line[strcspn(line, "\n")] = '\0';
		if (strlen(line) == 0)
		{
			continue;
		}

		strcpy(data->input_line, line);
		status = execute(data);
		if (status == EXIT_FAILURE)
		{
			printf("Error executing command\n");
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = NULL;
	}
	fclose(file);
	free(line);
	exit(EXIT_SUCCESS);
}


/**
 * read_input - ...
 * Return: Always a char
*/
char *read_input()
{
	ssize_t ret;
	char *line = NULL;

	ret = _getline(&line, stdin);
	if (ret == -1)
		return (NULL);
	return (line);
}


/**
 * run_program - Run the program
 * @data: A struct
 * Return: 0 or 1
*/
int run_program(Infos *data)
{
	int run = 1, index; /* Flag to determine when to exit */
	char *line;

	while (run)
	{
		_printf("$ ");
		fflush(stdout);
		line = read_input();
		if (!line)
			continue;
		if (feof(stdin))
		{
			free(line);
			return (0);
		}

		index = _strcspn(line, "\n");
		if (index < _strlen(line))
		line[index] = '\0';

		if (_strlen(line) == 0 || line[0] == '#')
		{
			free(line);
			continue;
		}

		separateInstructions(data, line);
		free(line);
	}

	return (0);
}




/**
 * main - Entry point
 * @argc: numbers of args
 * @argv: Vertors of args
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	Infos info, *data = &info;
	int exit_status;

	initialize_data(data, argc, argv);
	if (argc > 1)
		non_interactive(data, argv);
	else
	{
		exit_status = run_program(data);
		free_data(data);
		return (exit_status);
	}

	free_data(data);
	return (0);
}
