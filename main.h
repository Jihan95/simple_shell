#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define DEFAULT_LINE_SIZE 128
#define DIR_SIZE 1024
extern char **environ;

/**
 * struct command - defines new data type for a command
 * @path: command path
 * @found: it sets for 1 if command found, 0 in case of not found
 */
typedef struct command
{
	char *path;
	int found;
} CommandResult;



int _putchar(char c);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _atoi(char *s);
char *_strdup(char *str);
char *_strncat(char *dest, char *src, int n);
int _strcmp(const char *s1, const char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


char **tokenizer(char *str);
int executer(char **args, char **argv);
CommandResult get_cmd_path(char *cmd);
void _freetokens(char **tokens);
char **decisionmaker(char **tokens);
int __exit(char **cmdexit, char **argv, int exit_code);
int get_input(char **line);
void _printenv(void);
int parentchild(char **tokens, char **argv);
int _cd(char **argv, char **av);
int _cdError(char **av);

char *_strtok(char *str, const char *delimiters);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int exit_error(char **cmd_exit, char **argv);
void command_error(char **tokens, char **argv);
#endif
