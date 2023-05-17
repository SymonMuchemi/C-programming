#include "shell.h"
/**
 * string_seperator - this function separate the string using a designed delimiter
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */
void string_seperator(data_of_program *data)
{
	char *delimiter = " \t";
	int x;
	int y;
	int counter = 2;
	int length;

	length = str_length(data->input_ln);
	if (length)
	{
		if (data->input_ln[length - 1] == '\n')
			data->input_ln[length - 1] = '\0';
	}

	for (x = 0; data->input_ln[x]; x++)
	{
		for (y = 0; delimiter[y]; y++)
		{
			if (data->input_ln[x] == delimiter[y])
				counter++;
		}
	}

	data->token = malloc(counter * sizeof(char *));
	if (data->token == NULL)
	{
		perror(data->pg_name);
		exit(errno);
	}
	x = 0;

	data->token[x] = str_duplicate(_strtok(data->input_ln, delimiter));
	data->cmd_name = str_duplicate(data->token[0]);
	
	while (data->token[x++])
	{
		data->token[x] = str_duplicate(_strtok(NULL, delimiter));
	}
}
