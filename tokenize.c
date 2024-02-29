#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *tokenizer - tokenize a string
 *@str: string to tokenize
 *@delim: characters that separate a string
 *
 *Return: number of words tokenized
 */
size_t tokenizer(char *str, char *delim)
{
	size_t word_counter = 0;

	if (strtok(str, delim) != NULL)
		++word_counter;
	while (strtok(NULL, delim) != NULL)
		++word_counter;
	return (word_counter);
}

/**
 *word_array - creates an array of words
 *@str:string to prepare an array from
 *@delim: delimiter that determines end of words
 *
 *Return: pointer of an array of words
 */
char **word_array(char *str, char *delim)
{
	char **array = NULL;
	size_t array_iter = 0;
	size_t array_size = 0;
	size_t str_size = strlen(str);
	size_t str_iter;
	char prev_char = '\0';

	array_size = tokenizer(str, delim) + 1;
	if (array_size > 0)
	{
		array = malloc(sizeof(char *) * (array_size));
		if (array == NULL)
			return (NULL);
		for (str_iter = 0; str_iter < str_size; ++str_iter)
		{
			if (str[str_iter] != '\0' && prev_char == '\0')
			{
				array[array_iter] = str + str_iter;
				++array_iter;
			}
			prev_char = str[str_iter];
		}
		array[array_iter] = NULL;
	}
	return (array);
}
