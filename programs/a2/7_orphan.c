#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        sleep(5);

        printf("Child Process:\n");
        printf("PID = %d\n", getpid());
        printf("New PPID = %d\n", getppid());
    }
    else
    {
        // Parent exits immediately
        printf("Parent exiting...\n");
    }

    return 0;
}