#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Main process PID: %d\n", getpid());
    getchar();
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Error");
        return 1;
    }

    if (child_pid == 0) {
        printf("1 child process PID: %d, PPID: %d\n\n", getpid(), getppid());
        getchar();

    } else {
        pid_t second_child_pid = fork();

        if (second_child_pid == -1) {
            perror("Error");
            return 1;
        }

        if (second_child_pid == 0) {
            printf("2 child process PID: %d, PPID: %d\n\n", getpid(), getppid());
            pid_t third_child_pid = fork();

            if (third_child_pid == -1) {
                perror("Error");
                return 1;
            }

            if (third_child_pid == 0) {
                printf("Grandchild process PID: %d, PPID: %d\n\n", getpid(), getppid());
                system("ps -o pid,ppid,args --forest");
                getchar();

            } else {
                wait(NULL);
                getchar();
            }

        } else {
            wait(NULL);
            getchar();
        }
    }

    return 0;
}
