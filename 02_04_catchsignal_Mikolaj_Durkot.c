#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void signalHandler(int signal) {
    printf("Signal received: %s (%d)\n", strsignal(signal), signal);
    if (signal == 20) {
        exit(0);
    }
}

int main() {
    for (int i = 1; i < NSIG; ++i) {
        signal(i, signalHandler);
    }

    printf("Catchsignal is running.\nPress Ctrl+C to exit.\nPid: %d\n", getpid());

    while (1) {
    }

    return 0;
}
