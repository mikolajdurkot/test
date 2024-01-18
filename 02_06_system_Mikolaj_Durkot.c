#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Hello, I'm system program!\n");
    getchar();
    system("ls -al /var/log");
    return 0;
}
