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
        printf("$ ");
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
