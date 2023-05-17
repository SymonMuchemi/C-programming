#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t childPid;
    int status;

    childPid = fork();

    if (childPid == 0)
    {
        // Child process
        printf("Child process executing\n");
        sleep(20); // Simulating some work
        printf("Child process exiting\n");
        return 0;
    }
    else if (childPid > 0)
    {
        // Parent process
        printf("Parent process waiting for child to terminate\n");
        wait(&status);
        printf("%d\n", status);

        if (WIFEXITED(status))
        {
            printf("Child process terminated with exit status: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Child process terminated abnormally\n");
        }

        printf("Parent process exiting\n");
    }
    else
    {
        // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}
/**
 * In this example, the parent process creates a child process using fork().
 * The parent then uses wait() to wait for
 * the child to terminate. Once the child terminates,
 *  the parent retrieves the termination status using
 * WIFEXITED() and WEXITSTATUS() to determine if the
 * child terminated normally and obtain its exit status.
 */