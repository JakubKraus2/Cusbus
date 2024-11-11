#include <stdio.h>
#include <stdlib.h>


// task 1
long * allocateArray(const size_t n)
{
    return (long*)malloc(sizeof(long) * n);
}

long * copyArray(const long * originalArray, const size_t n) {
    long * newArray = (long *)malloc(n * sizeof(long));

    for (size_t i = 0; i < n; i++) {
        newArray[i] = originalArray[i];
    }

    return newArray;
}

// task 2
long * mixArray(const long * originalArray, const size_t n)
{
    if (n < 2) {
        return NULL;
    }

    size_t randomIndex1, randomIndex2;
    do {
        randomIndex1 = (size_t)(rand() % n);
        randomIndex2 = (size_t)(rand() % n);
    } while (randomIndex2 == randomIndex1);

    long * newArray = copyArray(originalArray, n);

    long temp = newArray[randomIndex1];
    newArray[randomIndex1] = newArray[randomIndex2];
    newArray[randomIndex2] = temp;

    return newArray;

}

// task 4
uint8_t isDifferent(const long * arr1, const long * arr2, const size_t n)
{
    if (arr1 == arr2)
    {
        return 0;
    }

    for (size_t i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i]) {
            return 1;
        }
    }

    return 0;
}

// task 3
void printOriginalAndMixed(const long * original, const long * mixed, const size_t n) {
    printf("Original\tMixed");
    for (size_t i = 0; i < n; ++i) {
        printf("%ld\t%ld", original[i], mixed[i]);
    }
}


int main(int argc, char* argv[])
{

    if (argc - 1 != 1) {
        printf("Incorrect argument count.\n");
        return 1;
    }

    // Convert argument to size_t
    size_t n = (size_t) atoi(argv[1]);

    long * originalArray = allocateArray(n);

    originalArray[0] = 5;
    originalArray[1] = 2;

    long * newArray = mixArray(originalArray, n);

    if (newArray == NULL) {
        return 1;
    }

    printOriginalAndMixed(originalArray, newArray, n);

    free(originalArray);
    free(newArray);

    return 0;
}