#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int numArrays, rows, cols;

    printf("Podaj liczbę tablic 2D: ");
    scanf("%d", &numArrays);

    int ***arrayOfArrays = (int ***)malloc(numArrays * sizeof(int **));
    if (arrayOfArrays == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci dla tablicy wskaźników\n");
        return 1;
    }

    printf("Podaj liczbę wierszy i kolumn dla tablic: ");
    scanf("%d %d", &rows, &cols);

    int count=1;
    for (int i = 0; i < numArrays; i++) {

        arrayOfArrays[i] = (int **)malloc(rows * sizeof(int *));
        if (arrayOfArrays[i] == NULL) {
            fprintf(stderr, "Błąd alokacji pamięci dla tablicy %d\n", i);
            return 1;
        }

        for (int j = 0; j < rows; j++) {
            arrayOfArrays[i][j] = (int *)malloc(cols * sizeof(int));
            if (arrayOfArrays[i][j] == NULL) {
                fprintf(stderr, "Błąd alokacji pamięci dla wiersza %d\n", j);
                return 1;
            }
        }

        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                arrayOfArrays[i][j][k] = count++;
            }
        }

        printf("Tablica %d:\n", i + 1);
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                printf("%2d ", arrayOfArrays[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < numArrays; i++) {
        for (int j = 0; j < rows; j++) {
            free(arrayOfArrays[i][j]);
        }
        free(arrayOfArrays[i]);
    }
    free(arrayOfArrays);

    return 0;
}
