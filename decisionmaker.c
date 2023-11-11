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

	if (*token == NULL)
		return (token);
	while (token[i] != NULL)
		i++;
	i++;
	if (_strcmp(token[0], "exit") == 0)
	{
		if (i == 2)
		{
			token = (char **)realloc(token, (i + 1) * sizeof(char *));
			if (token == NULL)
				return (NULL);
			token[1] = "0";
			token[2] = "a";
			return (token); }
		if (i == 3)
		{
			if (_strcmp(token[1], "0") == 0)
				token[2] = "a";
			token[2] = "b";
			return (token); }
		if (i > 3)
			return (token); }
	else if (_strcmp(token[0], "env") == 0)
	{
		if (i == 2)
		{
			token[1] = "a";
			return (token); }
		if (i > 2)
			return (token); }
	else
		return (token);
return (token); }

/**
 * _strcmp - compares two strings s1 and s2
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0, if strings are equal
 * if first string < second string, -1
 * if first string > second string, 1
*/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
