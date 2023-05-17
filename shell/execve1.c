#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {NULL};

    execve("/bin/ls", args, env);

    // If execve() returns, an error occurred.
    perror("execve");
    return 1;
}
