#include <stdio.h>

int main(int argc, char **argv)
{
    // Start with the first argument
    char **arg = &argv[1];

    // Print out all arguments until a NULL pointer is reached
    while (*arg != NULL)
    {
        printf("%s\n", *arg);
        arg++;
    }

    return 0;
    }
