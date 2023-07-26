#include "shell.h"
/**
 * _putchar - display a char
 * @c: char to display
 * Return: An int
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printf - writes a array of chars in the standar output
 * @string: pointer to the array of chars
 * Return: the number of bytes writed or .
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}



/**
 * print_prompt - display the prompt
 * @msg: prompt message
 * Return: Nothing
*/
void print_prompt(char *msg)
{
	while (*msg)
	{
		_putchar(*msg);
		msg++;
	}
}
