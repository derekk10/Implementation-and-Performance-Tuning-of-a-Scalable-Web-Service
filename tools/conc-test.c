#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS  1

void *helper_open( void *arg) { // main thread
    printf("In thread... opening foo.txt\n");
	int fd = open("foo.txt", O_RDWR);
	printf("fd: %d\n", fd);
}


int main() {
  int fd1 = open("foo.txt", O_RDONLY);
  int fd2 = open("foo.txt", O_RDWR);
  char* buf = "ayeayeayeturnup !!";
  ssize_t bytesWrite = write(fd2, buf, 19);
  int close2 = close(fd2);
  int close1 = close(fd1);

  return 0;
}
