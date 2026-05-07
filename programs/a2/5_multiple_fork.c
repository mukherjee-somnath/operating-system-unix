#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            // Child process
            printf("Child %d: PID = %d, PPID = %d\n",
                   i + 1, getpid(), getppid());

            return 0;
        }
    }

    // Parent process
    sleep(2);

    return 0;
}