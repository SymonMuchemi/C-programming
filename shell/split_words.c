#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(const char *str, const char *delim, int *num_words)
{
    char **words = NULL;
    char *token = NULL;
    int i = 0;

    // Make a copy of the input string since strtok modifies it
    char *str_copy = strdup(str);

    // Split the string into words using strtok
    token = strtok(str_copy, delim);
    while (token != NULL)
    {
        // Add the word to the array
        words = realloc(words, (i + 1) * sizeof(char *));
        words[i] = strdup(token);
        i++;
        token = strtok(NULL, delim);
    }

    // Free the copy of the string
    free(str_copy);

    // Set the number of words and return the array
    *num_words = i;
    return words;
}

int main()
{
    char str[] = "This is a test string.";
    char delim[] = " ";
    int num_words = 0;
    char **words = split_string(str, delim, &num_words);

    for (int i = 0; i < num_words; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]); // Free each word
    }

    free(words); // Free the array
    return 0;
}
