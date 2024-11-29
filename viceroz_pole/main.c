#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3; // po�et ��dk�
    int cols[] = { 2, 4, 3 }; // r�zn� d�lka sloupc� pro ka�d� ��dek

    // Alokace pole ukazatel� (��dk�)
    int** array = (int**)malloc(rows * sizeof(int*));

    // Alokace jednotliv�ch ��dk� s r�znou velikost�
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols[i] * sizeof(int));
    }

    // Napln�n� pole p��kladov�mi hodnotami
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            array[i][j] = i + j; // nap�. sou�et index�
        }
    }

    // V�pis hodnot
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Uvoln�n� pam�ti
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}