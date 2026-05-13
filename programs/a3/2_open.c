#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Path to the file
    char *path = "open.txt";

    // open() flags:
    // O_RDONLY: Open for reading only
    // O_CREAT: Create the file if it doesn't exist
    // 0644: Permissions (Read/Write for owner, Read for others)
    int fd = open(path, O_RDONLY | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Displaying the file descriptor
    printf("File opened successfully!\n");
    printf("The File Descriptor (fd) is: %d\n", fd);

    // Clean up
    close(fd);

    return 0;
}