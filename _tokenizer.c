#include "main.h"

/**
 * _tokenizer - parsing the input line
 * @line: line to be tokenized
 * @nchar: number of line characters
 *
 * Return: the tokenized line
 */

char **_tokenizer(char *line, ssize_t nchar)
{
	char *linecpy = NULL, *token, **par_array;
	int ntokens = 0, i, j;

	linecpy = (char *)malloc(nchar * sizeof(char));
	if (linecpy == NULL)
	{
		perror("Memory Allocation Failure");
		return (NULL); }
	strcpy(linecpy, line);
	token = strtok(linecpy, " ");
	while (token != NULL)
	{
		ntokens++;
		token = strtok(NULL, " "); }
	ntokens++;
	par_array = (char **)malloc(ntokens * sizeof(char *));
	if (par_array == NULL)
	{
		free(linecpy);
		perror("Memory Allocation Failure");
		return (NULL); }
	token = strtok(line, " ");
	for (i = 0; token != NULL; i++)
	{
		par_array[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
		if (par_array[i] == NULL)
		{
			free(linecpy);
			for (j = 0; j < i; j++)
				free(par_array[j]);
			free(par_array);
			return (NULL); }
		strcpy(par_array[i], token);
		token = strtok(NULL, " "); }
	par_array[i] = NULL;
	free(linecpy);
	return (par_array); }
