#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Hello, I'm exec program!\n");
    getchar();

    execl("./another", "./another", (char *)NULL);

    return 0;
}
