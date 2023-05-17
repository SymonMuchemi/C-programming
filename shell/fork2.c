#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    fork();
    fork();
    fork();
    printf("Hello\n");

    return (0);
}
/**
 * output: 
 *      Hello
 *      Hello
 *      Hello
 *      Hello
 *      Hello
 *      Hello
 *      Hello
 *      Hello
*/
/**
 * Explanation:
 *      The total number of processse vcreated by the 
 *      fork() call are: 2^n 
 *                        where n is the number of fork calls
 *      Therefore, 'Hello' will be printed out 8 (2^3) times
*/