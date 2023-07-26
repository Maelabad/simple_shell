#include "shell.h"


/**
 * change_dir - Change the current dir
 * @data: A set of data
 * Return: 0 or 1
*/
int change_dir(Infos *data)
{
	if (chdir(data->args[1]) == 0)
	{
		if (data->lastdir == NULL)
			data->lastdir = malloc(sizeof(char) * 100);
		_strcpy(data->lastdir, data->curdir);
		getcwd(data->curdir, 100);
		setenv("PWD", data->args[1], 1);
		return (1);
	}
	return (0);
}


/**
 * _cd - Change the current directory
 * data->args[1] - The data->args[1]uments of cd
 *  Command syntax: cd [DIRECTORY]
 *  If no data->args[1]ument is given to cd the command must be
 *  interpreted like cd $HOME
 *  You have to handle the command cd -
 *  You have to update the environment variable PWD when you change directory
 * @data: The set of information
 * Return: 0 or 1
 *
*/
int _cd(Infos *data)
{
	char path[256];

	if (data->curdir == NULL)
	{
		data->curdir = malloc(sizeof(char) * 100);
		getcwd(data->curdir, 100);
	}
	if (data->args[1] == NULL)
		data->args[1] = getenv("HOME");
	else if (!strcmp(data->args[1], "-"))
	{
		if (data->lastdir == NULL)
		{
			fprintf(stderr, "no previous directory\n");
			return (1);
		}
		data->args[1] = data->lastdir;
	}
	else
	{
		if (*data->args[1] == '~')
		{
			if (data->args[1][0] == '/' || data->args[1][0] == '\0')
			{
				snprintf(path, 256, "%s%s", getenv("HOME"), data->args[1] + 1);
				data->args[1] = path;
			}
			else
			{
				fprintf(stderr, "syntax not supported: %s\n", data->args[1]);
				return (1);
			}
		}
	}
	return (change_dir(data));
}
