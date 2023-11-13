#include "main.h"

/**
 * _getline - used for reading a line from a file stream or standard input
 * @lineptr: A pointer to the buffer where the line will be stored.
 * @n: A pointer to the size of the buffer pointed to by lineptr.
 * @stream: A pointer to the file stream from which to read the line
 *
 * Return: in case of success returns the number of characters read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream)); }
