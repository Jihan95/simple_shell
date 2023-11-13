#include "main.h"

/**
 * decisionmaker - taking decision regarding command execution
 * @token: the recieved tokanized input
 *
 * Return: modified tokens;
 */

char **decisionmaker(char **token)
{
	int i = 0;
	char **temp;

	if (*token == NULL)
		return (token);
	while (token[i] != NULL)
		i++;
	i++;
	if (_strcmp(token[0], "exit") == 0)
	{
		if (i == 2)
		{
			temp = (char **)realloc(token, (i + 2) * sizeof(char *));
			if (temp == NULL)
			{
				_freetokens(token);
				return (NULL); }
			token = temp;
			token[1] = strdup("0");
			token[2] = strdup("a");
			token[3] = NULL;
			return (token); }
		if (i == 3)
		{
			temp = (char **)realloc(token, (i + 1) * sizeof(char *));
			if (temp == NULL)
			{
				_freetokens(token);
				return (NULL); }
			token = temp;
			if (_strcmp(token[1], "0") == 0)
			{
				token[2] = strdup("a");
				token[3] = NULL; }
			else
			{
				token[2] = _strdup("b");
				token[3] = NULL; }
			return (token); }}
	return (token); }
