#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkce pro alokaci pole double
double* allocate_array(size_t N) {
    double* array = (double*)malloc(N * sizeof(double));
    if (array == NULL) {
        perror("Error allocating memory");
        return NULL;
    }
    return array;
}

// Funkce pro kontrolu, zda hodnota u� byla v poli
int is_duplicate(double* array, double value, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}

// Funkce pro nalezen� duplicitn�ch hodnot
double** find_duplicates(double* array, size_t N, size_t* dup_count) {
    double** duplicates = (double**)malloc(N * sizeof(double*));
    if (duplicates == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    *dup_count = 0;
    for (size_t i = 0; i < N; i++) {
        if (!is_duplicate(array, array[i], i)) {
            for (size_t j = i + 1; j < N; j++) {
                if (array[i] == array[j]) {
                    duplicates[*dup_count] = &array[i];
                    (*dup_count)++;
                    break;
                }
            }
        }
    }
    return duplicates;
}

// Funkce pro p�evr�cen� byt� v ka�d�m double
void reverse_bytes(double* value) {
    unsigned char* byte_ptr = (unsigned char*)value;
    for (size_t i = 0; i < sizeof(double) / 2; i++) {
        unsigned char temp = byte_ptr[i];
        byte_ptr[i] = byte_ptr[sizeof(double) - 1 - i];
        byte_ptr[sizeof(double) - 1 - i] = temp;
    }
}

// Funkce pro v�pis pole
void print_array(double** array, size_t count) {
    for (size_t i = 0; i < count; i++) {
        int* int_ptr = (int*)array[i];
        printf("Value %zu: ", i);
        for (size_t j = 0; j < sizeof(double) / sizeof(int); j++) {
            printf("%d ", int_ptr[j]);
        }
        printf("\n");
    }
}

int main() {
    size_t N;
    printf("Enter the size of the array: ");
    scanf("%zu", &N);

    // Alokace pole
    double* array = allocate_array(N);
    if (array == NULL) return 1;

    // Na�ten� hodnot pole
    printf("Enter %zu double values:\n", N);
    for (size_t i = 0; i < N; i++) {
        scanf("%lf", &array[i]);
    }

    // Nalezen� duplicit
    size_t dup_count;
    double** duplicates = find_duplicates(array, N, &dup_count);
    if (duplicates == NULL) {
        free(array);
        return 1;
    }

    // Obr�cen� byt� u ka�d�ho duplicitn�ho prvku
    for (size_t i = 0; i < dup_count; i++) {
        reverse_bytes(duplicates[i]);
    }

    // V�pis upraven�ho pole
    printf("Modified duplicate values:\n");
    print_array(duplicates, dup_count);

    // Uvoln�n� pam�ti
    free(array);
    free(duplicates);

    return 0;
}
