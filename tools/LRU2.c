#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

int main() {
    //READ A B C
    char buf1[10];
    char buf2[10];
    char buf3[10];
    int fd1 = open("A_", O_RDONLY);
    read(fd1, buf1, 10);
    int fd2 = open("B_", O_RDONLY);
    read(fd2, buf2, 10);
    int fd3 = open("C_", O_RDONLY);
    read(fd3, buf3, 10);
    close(fd1);
    close(fd2);
    close(fd3);

    //READ B D E B
    char buf4[10];
    char buf5[10];
    char buf6[10];
    char buf7[10];
    int fd4 = open("B_", O_RDONLY);
    read(fd4, buf4, 10);
    int fd5 = open("D_", O_RDONLY);
    read(fd5, buf5, 10);
    int fd6 = open("E_", O_RDONLY);
    read(fd6, buf6, 10);
    int fd7 = open("B_", O_RDONLY);
    read(fd7, buf7, 10);
    close(fd4);
    close(fd5);
    close(fd6);
    close(fd7);

    //READ F G
    char buf8[10];
    char buf9[10];
    int fd8 = open("F_", O_RDONLY);
    int fd9 = open("G_", O_RDONLY);
    close(fd8);
    close(fd9);
    
    

    return 0;
}