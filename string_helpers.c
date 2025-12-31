#include "simple_shell.h"

/**
* _strlen - returns length of string
* @s: string
*
* Return: length
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/**
* _strdup - duplicate string
* @s: string to duplicate
*
* Return: pointer to new string
*/
char *_strdup(char *s)
{
	char *dup;

	int i, len;

	if (!s)
		return (NULL);

	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[i] = '\0';

	return (dup);
}

/**
* _strcmp - compare two strings
* @s1: first string
* @s2: second string
*
* Return: 0 if equal, difference otherwise
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
* _strcat - concatenate two strings
* @dest: destination string
* @src: source string
*
* Return: pointer to destination string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
* _strcpy - copy string from src to dest
* @dest: destination string
* @src: source string
* Return: pointer to destination string
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest || !src)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
* _strncmp - compare first n bytes of two strings
* @s1: first string
* @s2: second string
* @n: number of bytes to compare
* Return: 0 if equal, difference otherwise
*/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
	}

	return (0);
}
