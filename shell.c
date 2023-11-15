#include "main.h"

/**
 * main - simple shell
 * @argc: number of passed arguments
 * @argv: command line arguments
 *
 * Return: always 0
 */

int main(__attribute__((unused))int argc, char **argv)
{
	char *line = NULL, **tokens = NULL;
	int exit_code = 0;

	while (1)
	{
		if (get_input(&line) == -1)
			break;
		tokens = tokenizer(line);
		if (*tokens == NULL)
		{
			free(line);
			continue; }
		if (_strcmp(tokens[0], "exit") == 0)
		{
			exit_code = __exit(tokens, argv, exit_code);
			_freetokens(tokens);
			free(line);
			continue; }
		if (_strcmp(tokens[0], "env") == 0)
		{
			_printenv();
			_freetokens(tokens);
			free(line);
			continue; }
		if (_strcmp(tokens[0], "cd") == 0)
		{
			exit_code = _cd(tokens, argv);
			_freetokens(tokens);
			free(line);
			continue; }
		exit_code = parentchild(tokens, argv);
		_freetokens(tokens); }
	if (isatty(STDIN_FILENO))
		printf("\n");
	free(line);
	exit(exit_code); }
