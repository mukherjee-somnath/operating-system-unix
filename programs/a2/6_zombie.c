#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child exits immediately
        printf("Child process exiting...\n");
        return 0;
    }
    else
    {
        // Parent sleeps without wait()
        printf("Parent sleeping...\n");
        printf("Zombie process created temporarily.\n");

        sleep(20);

        printf("Parent finished.\n");
    }

    return 0;
}