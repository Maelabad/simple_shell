#include "shell.h"

/**
 * free_Infos - Free the struct
 *  @data: The struct to free
 *  Return: Nothing
*/
void free_Infos(Infos *data)
{
	free(data->curdir);
	free(data->lastdir);
	free(data->input_line);
	data = NULL;
}
