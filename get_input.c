#include "main.h"

/**
 * get_input - reads input line from user
 * @line: the line to be read
 *
 * Return: 0 incase of success, -1 incase of failure
 */

int get_input(char **line)
{
	ssize_t rby;
	size_t n;
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
		printf("%s", prompt);
	rby = getline(line, &n, stdin);
	if (rby == EOF || rby == '\0')
		return (-1);
	(*line)[strcspn(*line, "\n")] = '\0';
	return (0); }
