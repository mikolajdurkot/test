#include <stdio.h>
#include <stdlib.h>

void statyczna() {

    double tablica[1000000];

    printf("Tablica statyczna - Wcisnij Enter, aby zakonczyc...");
    getchar();
}

void dynamiczna() {
    double *tablica = (double*)malloc(1000000 * sizeof(double));

    if (tablica == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci dynamicznej\n");
        exit(EXIT_FAILURE);
    }

    printf("Tablica dynamiczna - Wcisnij Enter, aby zakonczyc...");
    getchar();

    free(tablica);

}

int main() {

    printf("Brak tablic - nacisnij ENTER aby rozpoczac");
    getchar();
    
    statyczna();
    
    dynamiczna();

    printf("Brak tablicy dynamicznej - nacisnij ENTER aby zakonczyc");
    getchar();

    return 0;
}
