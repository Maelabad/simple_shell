#include "shell.h"

/**
 * _read_line - Read line ...
 * @stream: An array
 * @buffer: A buffer
 * @n: A size_t
 * Return: Nothing
*/
ssize_t _read_line(FILE *stream, char *buffer, size_t n)
{
	ssize_t count = read(fileno(stream), buffer, n);

	if (count < 0)
		perror("read failed");
	return (count);
}


/**
 * _free_and_exit - free and exit ...
 * @lineptr: An array
 * Return: Nothing
*/
void _free_and_exit(char **lineptr)
{
	free(*lineptr);
	exit(0);
}


/**
 * _is_newline - For execute the commande ...
 * @c: A char
 * Return: An int
*/
int _is_newline(char c)
{
	return (c == '\n');
}


/**
 * _getline - Reads a line of input from a stream
 * @lineptr: Address of buffer containing the text
 * @stream: Where read the file
 * Return: Number of characters read, -1 on failure
*/
ssize_t _getline(char **lineptr, FILE *stream)
{
	ssize_t count = 0;
	size_t pos = 0, n = BUFFER_SIZE;
	char *new_ptr;

	if (lineptr == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	*lineptr = malloc(n);
	if (*lineptr == NULL)
	{
		perror("malloc failed");
		errno = ENOMEM;
		return (-1);
	}
	do {
		if (pos >= n)
		{
			n *= 2;
			new_ptr = realloc(*lineptr, n);
			if (new_ptr == NULL)
			{
				perror("realloc failed");
				_free_and_exit(lineptr);
			}
			*lineptr = new_ptr;
		}
		count = _read_line(stream, *lineptr + pos, n - pos);
		if (count == 0)
			_free_and_exit(lineptr);
		if (count > 0)
		{
			pos += count;
			if (_is_newline((*lineptr)[pos - 1]))
				break;
		}
	} while (count > 0);
	(*lineptr)[pos] = '\0';
	return ((ssize_t)pos);
}
