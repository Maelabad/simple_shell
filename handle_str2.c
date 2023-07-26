#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 */
int _strlen(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}


/**
 * _strcspn - Return the length of the string without a char *
 * @s: the initial string
 * @reject: elements to remove
 * Return: number of characters read
*/
int _strcspn(char *s, char *reject)
{
	int i, j;

	if (s == NULL || reject == NULL)
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (s[i] == reject[j])
				return (i);
		}
	}
	return (i);
}



/**
 * _strcmp - Compare 2 string
 * @s1: the first string
 * @s2: the second string
 * Return: number of characters read
*/
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{

		return (*s1 - *s2);
	}
}
