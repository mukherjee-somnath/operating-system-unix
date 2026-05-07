#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // Child Process
        printf("Child process executing...\n");
        sleep(3);
        printf("Child process completed.\n");
    }
    else
    {
        // Parent waits
        wait(NULL);

        printf("Parent resumes execution.\n");
    }

    return 0;
}