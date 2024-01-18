#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Sposób użycia: %s <typ> <liczba filozofow>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int typ = atoi(argv[1]);
    int n = atoi(argv[2]);

    
    if (typ != 1 || typ != 2){
    	fprintf(stderr, "Zly typ programu\n");
    }
    
    float filozof[n] - {0};
    int cutlery[n] = {0};
    int siz = 10;
    
    clock_t start[n];
    
    if (typ == 1){//jesli oba sztucce wolne - mozesz podniesc
    	for (int i=0; i++; i<n){
    		if (cutlery[i] == 0 && cutlery[(i+1)%n] == 0){
    			cutlery[i] = 1;
    			cutlery[(i+1)%n] = 1;
    			filozof[i] = (float)rand()/(float)(RAND_MAX/siz);
    			start[i] = clock_t;
    			printf("Filozof %d je.",i);
    		}
    	}
    	for (int i=0; i++; i<n){
    		if (filozof[i] > start[i]]){
    			cutlery[i] = 0;
    			cutlery[(i+1)%n] = 0;
    			filozof[i] = 0;
    			printf("Filozof %d skonczyl jesc.",i);
    		}
    	}
    	
    }
    else{//parzysty filozof najpierw podnosi lewy sztuciec, potem prawy a nieparzysty odwrotnie
    	
    }
    
    
    
    
    return EXIT_SUCCESS;

   
