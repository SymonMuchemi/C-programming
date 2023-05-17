#include <stdio.h>
#include <unistd.h>

void forkExample(){
    if (fork() == 0){
        printf("Hello from child!\n");
    }
    else
        printf("Hello from parent!\n");
}

int main(void){
    forkExample();

    return (0);
}
/**
 * Output:
 *      Hello from parent!
 *      Hello from child!
*/
/**
 * Explanation
 * 
 * In the above code, a child process is created. fork() returns a
 * a positive integer in the child process and 0 in the parent 
 * process. The two process runn concurrently.
 * 
*/