#include "main.h"

/**
 * __exit - Implement the exit built-in, that exits the shell
 * @cmdexit : recieved command
 * @argv: command line arguments
 *
 * Return: 2 in case if not exit
 */

int __exit(char **cmdexit, char **argv)
{
	int charvalue, ex = 0;

	if (strncmp(cmdexit[2], "a", 1) == 0)
		exit(0);
	if (strncmp(cmdexit[2], "b", 1) == 0)
	{
		charvalue = atoi(cmdexit[1]);
		if (charvalue > 0)
			exit(charvalue);
		else
			ex = exit_error(cmdexit, argv); }
return (ex); }
