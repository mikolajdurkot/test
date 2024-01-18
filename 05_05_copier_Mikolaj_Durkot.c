#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Sposób użycia: %s <rozmiar_bufora> <plik.src> <plik.trg>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int rozmiar_bufora = atoi(argv[1]);
    char *plik_src = argv[2];
    char *plik_trg = argv[3];

    FILE *plik_src_ptr = fopen(plik_src, "rb");
    FILE *plik_trg_ptr = fopen(plik_trg, "wb");

    if (plik_src_ptr == NULL || plik_trg_ptr == NULL) {
        perror("Błąd otwarcia pliku");
        return EXIT_FAILURE;
    }

    char *bufor = (char *)malloc(rozmiar_bufora);
    if (bufor == NULL) {
        perror("Błąd alokacji bufora");
        fclose(plik_src_ptr);
        fclose(plik_trg_ptr);
        return EXIT_FAILURE;
    }

    clock_t start, end;
    double czas_kopiowania;

    start = clock();

    size_t odczytane_bajty;
    while ((odczytane_bajty = fread(bufor, 1, rozmiar_bufora, plik_src_ptr)) > 0) {
        fwrite(bufor, 1, odczytane_bajty, plik_trg_ptr);
    }

    end = clock();

    czas_kopiowania = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Czas kopiowania: %.6f sekundy\n", czas_kopiowania);

    free(bufor);
    fclose(plik_src_ptr);
    fclose(plik_trg_ptr);

    return EXIT_SUCCESS;
}
