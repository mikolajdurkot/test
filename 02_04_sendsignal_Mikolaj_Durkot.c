#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./sendsignal <PID> <signal>\n");
        return 1;
    }

    pid_t dest_pid = atoi(argv[1]);
    int signal_num = atoi(argv[2]);

    kill(dest_pid, signal_num);

    return 0;
}
