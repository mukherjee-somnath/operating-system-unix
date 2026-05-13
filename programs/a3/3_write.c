#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char *path = "output.txt";
    char *text = "Hello from the C program!\nThis is a test of the write() system call.";

    // 1. Open the file
    // O_WRONLY: Write only
    // O_CREAT: Create if it doesn't exist
    // O_TRUNC: If the file exists, clear it first
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 2. Write data
    // strlen(text) ensures we write exactly the number of characters in the string
    ssize_t bytes_written = write(fd, text, strlen(text));

    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Success: Wrote %ld bytes to '%s'.\n", bytes_written, path);

    // 3. Close the file
    close(fd);

    return 0;
}