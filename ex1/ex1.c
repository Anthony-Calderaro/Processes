// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here

    //(e.g., x) and set its value to something (e.g., 100).
    int x = 50;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 100;
        printf("The child's X is: %d\n", x, (int) getpid());
    } else {
        x = 0;
        printf("The parent's X is: %d\n", x, (int) getpid());
    }

    return 0;
}
