#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing date command using execl()...\n");

    execl("/bin/date", "date", NULL);

    printf("Exec failed.\n");

    return 0;
}