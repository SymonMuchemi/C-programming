#include <stdio.h>

char *_strchr(char *s, char c)
    {
        int index;

	for (index = 0; s[index] >= '\0'; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return ('\0');
        
    } 

int main(void)
{
      char *s = "hello";
    char *f;

    f = _strchr(s, 'k');

    if (f != NULL)
    {
        printf("%s\n", f);
    }
    return (0);
}