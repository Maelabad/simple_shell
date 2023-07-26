#include "shell.h"
/**
 * _strcpy - Copy the string src to the dest
 * @dest: The string of destination
 * @src: The source string
 * Return: A pointer on the result
*/
char *_strcpy(char *dest, const char *src)
{
	char *result = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (result);
}




/**
 * _strcat - Concatenate 2 strings
 * @dest: The string of destination
 * @src: The source string
 * Return: A pointer on the result
*/
char *_strcat(char *dest, const char *src)
{
	char *tmp = dest + _strlen(dest);

	while (*src != '\0')
	{
		*tmp++ = *src++;
	}

	*tmp = '\0';

	return (dest);
}




/**
 * _atoi - Convert a string to int
 * @str: The string to convert
 * Return: 0 if fails, something else if success
*/

int _atoi(const char *str)
{
	int res = 0;
	int sign = 1;

	while (isspace(*str))
	{
		str++;
	}

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	while (isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}

	return (sign * res);
}


/**
 * _strtok - separates strings with delimiters
 * @line: Pointer to array we receive in _getline.
 * @delim: Characters we mark off string in parts.
 * Return: A pointer to the created token
*/
char *_strtok(char *line, char *delim)
{
	int j;
	static char *str;
	char *copystr;

	if (line != NULL)
	str = line;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
				break;
		}
		if (delim[j] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
