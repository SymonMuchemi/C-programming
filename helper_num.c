#include "shell.h"

/**
 * long_to_string - converts a number to a string.
 * @number: number to be stringified.
 * @string: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0;
	int inNegative = 0;
	long quot = number;
	char letters[] = {"0123456789abcdef"};

	if (quot == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (quot)
	{
		if (quot < 0)
			string[index++] = letters[-(quot % base)];
		else
			string[index++] = letters[quot % base];
		quot /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origen.
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/*2 - extract the number */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - count the coincidences of character in string.
 *
 * @string: pointer to str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *string, char *character)
{
	int x;
	int counter = 0;

	for (x = 0; string[x]; x++)
	{
		if (string[x] == character[0])
			counter++;
	}
	return (counter);
}