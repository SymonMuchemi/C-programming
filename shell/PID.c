#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    __pid_t my_pid;
    __pid_t ThePPID;

    my_pid = getpid();
    ThePPID = getppid();

    printf("My process ID is %u\nMy Parent process ID is %u\n", my_pid, ThePPID);
    return (0);
}