#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int old_fd, new_fd;
    char *text1 = "Writing using old_fd.\n";
    char *text2 = "Writing using new_fd.\n";

    // 1. Open a file to get an initial file descriptor
    old_fd = open("dup_demo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (old_fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 2. Duplicate the file descriptor
    new_fd = dup(old_fd);
    if (new_fd == -1) {
        perror("Error duplicating descriptor");
        close(old_fd);
        return 1;
    }

    printf("Old FD: %d\n", old_fd);
    printf("New FD: %d\n", new_fd);

    // 3. Write using the original descriptor
    write(old_fd, text1, strlen(text1));

    // 4. Write using the duplicated descriptor
    // Notice that it continues where text1 left off because they share the offset
    write(new_fd, text2, strlen(text2));

    printf("Success: Check 'dup_demo.txt' to see combined output.\n");

    // 5. Close both
    close(old_fd);
    close(new_fd);

    return 0;
}