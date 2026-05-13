#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // File name to be created
    char *filename = "example_file.txt";

    // creat() returns a file descriptor on success, or -1 on error
    // S_IRUSR | S_IWUSR sets read and write permissions for the owner
    int fd = creat(filename, 0644);

    if (fd == -1) {
        printf("Error: Could not create the file.\n");
        return 1;
    }

    printf("Success: File '%s' created successfully!\n", filename);

    // Always close your file descriptors
    close(fd);

    return 0;
}