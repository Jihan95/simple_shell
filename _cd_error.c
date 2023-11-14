#include "main.h"

/**
 * _cdError - displaying error in case of system call failure
 * @av: command line arguments
 *
 * Return: always 1
 */

int _cdError(char **av)
{
	perror(av[0]);
	return (1); }
