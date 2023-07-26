#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64


#define MAX_CMD_LEN 1024

#define BUFFER_SIZE 256


#define MAX_INSTRUCTIONS 8


#define MAX_ARGS 8

extern char **environ;


/**
 * struct infos - struct for the program's data
 * @PATH: The path
 * @program_name: the name of the executable
 * @command_name: pointer to the first command typed by the user
 * @input_line: pointer to the input read for _getline
 * @file_descriptor: file descriptor to the input of commands
 * @curdir: Current working directory
 * @lastdir: The last working directory
 * @args: Argument in the input line
 * @nb_arg: Numbers of arguments in the input line
 * @env: copy of the environ
 */
typedef struct infos
{
	char **PATH;
	char *program_name;
	char *command_name;
	int file_descriptor;
	char *input_line;
	char *args[20];
	int nb_arg;
	char **env;
	char *curdir;
	char *lastdir;
} Infos;


/*============================exec.c DONE==============================*/
void handle_args(Infos *infos);

void execute_command(char **arguments);

int execute(Infos *data);

int handle_path(Infos *data);


/*============================_exit.c DONE==============================*/

int built_in_exit(Infos *data);
int display_env(void);

/*============================_cd.c DONE====================================*/
int _cd(Infos *data);

int change_dir(Infos *data);


/*============================infos.c DONE=====================================*/
void init_path(Infos *data);
void initialize_data(Infos *data, int argc, char *argv[]);


/*============================print_shell.c DONE=============================*/
int _putchar(char c);

void print_prompt(char *msg);

int _printf(char *string);


/*============================_getline.c DONE=================================*/
ssize_t _getline(char **lineptr, FILE *Stream);


/*============================handle_str1.c DONE ============================*/
char *_strtok(char *line, char *delim);

char *_strcpy(char *dest, const char *src);

char *_strcat(char *dest, const char *src);

int _atoi(const char *str);


/*============================handle_str2.c DONE==============================*/
int _strcspn(char *s, char *reject);

int _strcmp(char *s1, char *s2);

int _strlen(char *string);


/*============================frees.c.c=============================*/
void free_data(Infos *data);
void free_Infos(Infos *data);
void free_path(Infos *data);


int separateInstructions(Infos *data, char* input_line);


#endif
