#include <stdio.h>

int _strlen_recursion(char *s)
{
	int len = 0;

	if (*s)
	{
		len++;
		len += _strlen_recursion(s + 1);
	}

	return (len);
}

int main(void){
 
    
    int length = _strlen_recursion("Bananas turn yellow when ripe");
    printf("%d",length);
}