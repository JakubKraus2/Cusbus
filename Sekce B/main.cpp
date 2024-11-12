#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkce pro alokaci pole
int alokuj_pole(char** pole, size_t velikost) {
    *pole = (char*)malloc(velikost * sizeof(char));
    if (*pole == NULL) {
        return -1; // Chyba pøi alokaci pamìti
    }
    return 0; // Úspìšná alokace
}

// Funkce pro maskování znakù v poli (vytvoøí nové pole s maskovanými znaky)
int maskuj_znaky(const char* pùvodní_pole, size_t velikost, const char* maskované_znaky, char** nové_pole) {
    *nové_pole = (char*)malloc((velikost + 1) * sizeof(char)); // +1 pro null-terminátor
    if (*nové_pole == NULL) {
        return -1; // Chyba pøi alokaci pamìti
    }

    // Vytvoøíme kopii pùvodního pole s maskováním
    for (size_t i = 0; i < velikost; ++i) {
        // Pokud znak v pùvodním poli je v seznamu maskovaných znakù, nahradíme ho '*'
        if (strchr(maskované_znaky, pùvodní_pole[i])) {
            (*nové_pole)[i] = '*';
        }
        else {
            (*nové_pole)[i] = pùvodní_pole[i];
        }
    }
    (*nové_pole)[velikost] = '\0'; // Null-terminátor pro C øetìzec
    return 0; // Úspìšnì maskováno
}

// Funkce pro výpis pole
void vypis_pole(const char* pole) {
    printf("%s\n", pole);
}

int main() {
    char* pole = NULL;
    size_t velikost = 10;
    const char maskované_znaky[] = "aeiou"; // Maskujeme samohlásky (pøíklad)

    // Alokace pole
    int stav = alokuj_pole(&pole, velikost);
    if (stav != 0) {
        fprintf(stderr, "Chyba pøi alokaci pamìti!\n");
        return 1;
    }

    // Naplníme pole nìjakými znaky
    strcpy(pole, "abcdefghi");

    // Vytvoøení nového pole s maskováním
    char* nové_pole = NULL;
    stav = maskuj_znaky(pole, velikost, maskované_znaky, &nové_pole);
    if (stav != 0) {
        fprintf(stderr, "Chyba pøi maskování znakù!\n");
        free(pole);
        return 1;
    }

    // Výpis pùvodního a vymaskovaného pole
    printf("Pùvodní pole: %s\n", pole);
    printf("Vymaskované pole: ");
    vypis_pole(nové_pole);

    // Uvolnìní pamìti
    free(pole);
    free(nové_pole);

    return 0;
}