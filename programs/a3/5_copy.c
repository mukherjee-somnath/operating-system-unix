#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // 1. Open the source file (must exist)
    src_fd = open("output.txt", O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // 2. Open/Create the destination file
    // O_WRONLY: Write only
    // O_CREAT: Create if doesn't exist
    // O_TRUNC: Overwrite if it already exists
    dest_fd = open("open.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    // 3. The Copy Loop
    // We read a chunk into the buffer, then write that same chunk out
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source");
    } else {
        printf("File copied successfully!\n");
    }

    // 4. Clean up
    close(src_fd);
    close(dest_fd);

    return 0;
}