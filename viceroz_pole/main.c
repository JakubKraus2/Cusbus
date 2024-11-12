#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3; // poèet øádkù
    int cols[] = { 2, 4, 3 }; // rùzná délka sloupcù pro každý øádek

    // Alokace pole ukazatelù (øádkù)
    int** array = (int**)malloc(rows * sizeof(int*));

    // Alokace jednotlivých øádkù s rùznou velikostí
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols[i] * sizeof(int));
    }

    // Naplnìní pole pøíkladovými hodnotami
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            array[i][j] = i + j; // napø. souèet indexù
        }
    }

    // Výpis hodnot
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Uvolnìní pamìti
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}