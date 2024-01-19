#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Skrypt przyjmuje 2 argumenty (oprocz jego nazwy)\n");
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    srand(time(NULL));

    time_t start = time(NULL);

    time_t stop = time(NULL);
    int czas = difftime(stop, start);

    return 0;
}
