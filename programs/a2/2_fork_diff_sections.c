#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // Child section
        printf("Child Process Running...\n");

        for (int i = 1; i <= 5; i++)
        {
            printf("Child Count: %d\n", i);
            sleep(1);
        }
    }
    else
    {
        // Parent section
        printf("Parent Process Running...\n");

        for (int i = 1; i <= 5; i++)
        {
            printf("Parent Count: %d\n", i);
            sleep(1);
        }
    }

    return 0;
}