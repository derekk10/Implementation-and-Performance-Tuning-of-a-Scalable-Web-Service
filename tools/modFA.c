#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

int main() {
    //modify F
    int fd1 = open("F_", O_RDWR);
    char *buf = "suckmybal";
    lseek(fd1, 0, SEEK_SET);
    write(fd1, buf, 10);
    close(fd1);
    
    //modify A
    int fd2 = open("A_", O_RDWR);
    char *buf2 = "nsiallaa";
    lseek(fd2, 0, SEEK_SET);
    write(fd2, buf2, 10);
    close(fd2);

    return 0;

}