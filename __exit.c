#include "main.h"

/**
 * __exit - Implement the exit built-in, that exits the shell
 * @cmdexit : recieved command
 * @argv: command line arguments
 * @exit_code: the exit code
 *
 * Return: 2 in case if not exit
 */

int __exit(char **cmdexit, char **argv, int exit_code)
{
	int charvalue, ex = 0;

	if (_strcmp(cmdexit[2], "a") == 0)
	{
		if (exit_code != 0)
		{
			_freetokens(cmdexit);
			exit(exit_code); }
		else
		{
			_freetokens(cmdexit);
			exit(0); }}
	if (strncmp(cmdexit[2], "b", 1) == 0)
	{
		charvalue = atoi(cmdexit[1]);
		if (charvalue > 0)
		{
			_freetokens(cmdexit);
			exit(charvalue); }
		else
			ex = exit_error(cmdexit, argv); }
return (ex); }
