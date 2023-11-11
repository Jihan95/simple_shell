#include "main.h"

/**
 *_strcpy - copies the string to another
 * @src: string required to be copied
 * @dest: the new destination
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int length = 0, i;

	for (i = 0; src[i] != '\0'; i++)
		length++;

	for (i = 0; i < length; i++)
		dest[i] = src[i];
	dest[i] = '\0';


return (dest); }

/**
 * _strlen - get the length of passed string
 * @s: passed string
 *
 * Return: the length of passed string
 */

int _strlen(char *s)
{
	int length = 0, i;

	for (i = 0; s[i] != '\0'; i++)
		length++;

	return (length);
}

/**
 * _atoi - convert a string to an integer.
 * @s: passed string
 *
 * Return: the numerical value of passed string
 */

int _atoi(char *s)
{
	unsigned int num = 0;
	int i, sign = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = num * 10 + (s[i] - 48);
			if (s[i + 1] == ' ')
				break;	}
		else if (s[i] == 45)
			sign = sign * -1;
		else if (s[i + 1] <= 48 && s[i + 1] >= 57)
			break;
	}
	return (sign * num);
}

/**
 * _strdup - copy a given string to a new located part at memory
 * @str: the given string
 *
 * Return: a pointer to the new array
 */

char *_strdup(char *str)
{
	char *p = NULL;
	int i, str_length = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + str_length) != '\0')
		str_length += 1;

	p = (char *) malloc(str_length * sizeof(char) + 1);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < str_length; i++)
		*(p + i) = *(str + i);
	return (p);
}

/**
 * _strncat - concatenates two strings
 * @dest: destination char
 * @src: source char
 * @n: number of bytes from src
 * Return: new string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int len = 0;

	while (dest[len] != '\0')
		len++;
	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
