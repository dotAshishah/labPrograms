*/Reader process*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUF 1024

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo.txt";
    char buf[MAX_BUF];

    /* Open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Writer: %s\n", buf);
    close(fd);

    return 0;
}

*/Writer process*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    char buf[1024];
    char *myfifo = "/tmp/myfifo.txt";

    /* Create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);
    printf("Run Reader process to read the FIFO File\n");

    fd = open(myfifo, O_WRONLY);
    write(fd, "Hi", sizeof("Hi")); /* Write "Hi" to the FIFO */
    close(fd);

    unlink(myfifo); /* Remove the FIFO */

    return 0;
}
