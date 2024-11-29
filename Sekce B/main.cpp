#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkce pro alokaci pole
int alokuj_pole(char** pole, size_t velikost) {
    *pole = (char*)malloc(velikost * sizeof(char));
    if (*pole == NULL) {
        return -1; // Chyba p�i alokaci pam�ti
    }
    return 0; // �sp�n� alokace
}

// Funkce pro maskov�n� znak� v poli (vytvo�� nov� pole s maskovan�mi znaky)
int maskuj_znaky(const char* p�vodn�_pole, size_t velikost, const char* maskovan�_znaky, char** nov�_pole) {
    *nov�_pole = (char*)malloc((velikost + 1) * sizeof(char)); // +1 pro null-termin�tor
    if (*nov�_pole == NULL) {
        return -1; // Chyba p�i alokaci pam�ti
    }

    // Vytvo��me kopii p�vodn�ho pole s maskov�n�m
    for (size_t i = 0; i < velikost; ++i) {
        // Pokud znak v p�vodn�m poli je v seznamu maskovan�ch znak�, nahrad�me ho '*'
        if (strchr(maskovan�_znaky, p�vodn�_pole[i])) {
            (*nov�_pole)[i] = '*';
        }
        else {
            (*nov�_pole)[i] = p�vodn�_pole[i];
        }
    }
    (*nov�_pole)[velikost] = '\0'; // Null-termin�tor pro C �et�zec
    return 0; // �sp�n� maskov�no
}

// Funkce pro v�pis pole
void vypis_pole(const char* pole) {
    printf("%s\n", pole);
}

int main() {
    char* pole = NULL;
    size_t velikost = 10;
    const char maskovan�_znaky[] = "aeiou"; // Maskujeme samohl�sky (p��klad)

    // Alokace pole
    int stav = alokuj_pole(&pole, velikost);
    if (stav != 0) {
        fprintf(stderr, "Chyba p�i alokaci pam�ti!\n");
        return 1;
    }

    // Napln�me pole n�jak�mi znaky
    strcpy(pole, "abcdefghi");

    // Vytvo�en� nov�ho pole s maskov�n�m
    char* nov�_pole = NULL;
    stav = maskuj_znaky(pole, velikost, maskovan�_znaky, &nov�_pole);
    if (stav != 0) {
        fprintf(stderr, "Chyba p�i maskov�n� znak�!\n");
        free(pole);
        return 1;
    }

    // V�pis p�vodn�ho a vymaskovan�ho pole
    printf("P�vodn� pole: %s\n", pole);
    printf("Vymaskovan� pole: ");
    vypis_pole(nov�_pole);

    // Uvoln�n� pam�ti
    free(pole);
    free(nov�_pole);

    return 0;
}