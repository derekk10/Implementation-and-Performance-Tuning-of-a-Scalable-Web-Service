#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS  1

// void *helper_open( void *arg) { // main thread
//     printf("In thread... opening foo.txt\n");
// 	int fd = open("foo.txt", O_RDWR);
// 	printf("fd: %d\n", fd);
// }

int main() {
    int fd1 = open("foo", O_CREAT);
    int fd2 = open("foo", O_RDWR);
    char *buf = "123456789";
    char *buf2 = "fucking fuck fuck fck";
    write(fd1, buf, 10);
    write(fd2, buf2, 22);
    close(fd1);
    close(fd2);
    return 0;
}
