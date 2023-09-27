#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

int main() {
	int fd1 = open("foo.txt", O_RDWR);
	char* four_chars = "abcd";
	write(fd1, four_chars, 5);
	char* one = "lll";

	int fd2 = open("grind", O_CREAT);
	write(fd2, one, 3);
	close(fd2);

	char* jkl = "qwer";

	int fd3 = open("no2", O_CREAT);
	write(fd3, jkl, 4);
	close(fd3);

	close(fd1);

	return 0;
}
