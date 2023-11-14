#include "main.h"

/**
 * _cd - Implement the builtin command cd
 * @argv: command arguments;
 * @av: command line arguments
 *
 * Return: exit_code
 */

int _cd(char **argv, char **av)
{
	int i = 0, exit_code = 0;
	char *directory = NULL, currentdir[DIR_SIZE];
	struct stat st;

	while (argv[i] != NULL)
		i++;
	if (i > 2)
	{
		fprintf(stderr, "%s cd: too many arguments\n", av[0]);
		return (1); }
	if (i == 1)
	{
		directory = getenv("HOME");
		if (directory == NULL)
			exit_code = _cdError(av); }
	else if (i == 2)
	{
		if (strcmp(argv[1], "-") == 0)
		{
			directory = getenv("OLPDPWD");
			if (directory == NULL)
				exit_code = _cdError(av); }
		else if (stat(argv[1], &st) != 0)
		{
			fprintf(stderr, "%s: 1: cd: can't cd to %s\n", av[0], argv[1]);
			return (1); }
		if (stat(argv[1], &st) == 0 && exit_code != 1)
			directory = argv[1]; }
	if (getcwd(currentdir, sizeof(currentdir)) == NULL && exit_code != 1)
		exit_code = _cdError(av);
	if (setenv("OLDPWD", currentdir, 1) != 0 && exit_code != 1)
		exit_code = _cdError(av);
	if (chdir(directory) != 0 && exit_code != 1)
		exit_code = _cdError(av);
	if (getcwd(currentdir, sizeof(currentdir)) == NULL && exit_code != 1)
		exit_code = _cdError(av);
	if (setenv("PWD", currentdir, 1) != 0 && exit_code != 1)
		exit_code = _cdError(av);
	return (exit_code); }
