#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[1024]; // A place to store the data we read
    ssize_t bytes_read;
    char *path = "output.txt"; // The file we created in the last step

    // 1. Open the file for Reading Only
    fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // 2. Read the data
    // read(file_descriptor, buffer_to_store_data, max_bytes_to_read)
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    // 3. Null-terminate the string
    // read() doesn't add a '\0', so we must do it manually to use printf
    buffer[bytes_read] = '\0';

    // 4. Display on screen
    printf("Data read from file:\n%s\n", buffer);

    // 5. Close
    close(fd);

    return 0;
}