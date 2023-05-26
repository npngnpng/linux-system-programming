#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 512

int main() {
    char *msg = "apple is red";
    char *msg2 = "banana is yellow";
    char buffer[SIZE];

    int filedes[2];
    int nread;


    if (pipe(filedes) == -1) {
        printf("fail to call pipe()\n");
        exit(1);
    }

    write(filedes[1], msg, strlen(msg)+1);
    write(filedes[1], msg2, strlen(msg2)+1);

    nread = read(filedes[0], buffer, SIZE);
    printf("%d %s\n", nread, buffer);

    nread = read(filedes[0], buffer, SIZE);
    printf("%d %s\n", nread, buffer);
}
