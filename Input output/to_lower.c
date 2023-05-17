#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;

    while ((c = getchar()) || c == EOF)
    {
        putchar(tolower(c));
    }
    
}