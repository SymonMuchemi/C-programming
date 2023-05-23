#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        printf("Input: ");
        nread = getline(&line, &len, stdin);

        if (nread == -1)
        {
            // End of file or error occurred
            break;
        }

        printf("%s", line);
    }

    free(line);
    return 0;
}
void separateAndConvert(char *input, int *B1, int *B2, char *S)
{
    // Find the delimiter position
    char *delimiterPos = strchr(input, ':');

    if (delimiterPos == NULL)
    {
        printf("Delimiter not found in the input.\n");
        return;
    }

    // Calculate the length of the first part
    int firstPartLength = delimiterPos - input;

    // Allocate memory for the first part and copy it
    char *firstPart = (char *)malloc(firstPartLength + 1);
    strncpy(firstPart, input, firstPartLength);
    firstPart[firstPartLength] = '\0';

    // Convert the first part to decimal
    *B1 = atoi(firstPart);

    // Store the delimiter
    *S = *delimiterPos;

    // Calculate the length of the second part
    int secondPartLength = strlen(delimiterPos + 1);

    // Allocate memory for the second part and copy it
    char *secondPart = (char *)malloc(secondPartLength + 1);
    strncpy(secondPart, delimiterPos + 1, secondPartLength);
    secondPart[secondPartLength] = '\0';

    // Convert the second part to decimal
    *B2 = atoi(secondPart);

    // Free the dynamically allocated memory
    free(firstPart);
    free(secondPart);
}