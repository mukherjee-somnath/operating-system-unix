#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[20];
    char *filename = "seek_demo.txt";
    char *data = "ABCDEFGHIJ"; // 10 bytes

    // 1. Create a file and write some initial data
    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, data, strlen(data));

    // 2. Move pointer to the 5th byte from the beginning (SEEK_SET)
    // The pointer will now be at 'F'
    lseek(fd, 5, SEEK_SET);
    read(fd, buffer, 1);
    printf("Byte at position 5: %c\n", buffer[0]);

    // 3. Move forward 2 bytes from current position (SEEK_CUR)
    // We were at 6 (after reading F), now we jump to 8 ('I')
    lseek(fd, 2, SEEK_CUR);
    read(fd, buffer, 1);
    printf("Byte after jumping 2 from current: %c\n", buffer[0]);

    // 4. Move to 3 bytes before the end (SEEK_END)
    // The pointer goes to position 7 ('H')
    lseek(fd, -3, SEEK_END);
    read(fd, buffer, 1);
    printf("Byte 3 positions before end: %c\n", buffer[0]);

    // 5. Find current offset
    off_t current = lseek(fd, 0, SEEK_CUR);
    printf("Current pointer position: %ld\n", current);

    close(fd);
    return 0;
}