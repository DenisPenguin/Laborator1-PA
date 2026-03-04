#include <stdio.h>
#include <string.h>

// am identificat un posibil edge case atunci cand lista de hobby-uri nu este de lungime exacta cu numarul maxim de
// elemente din vector
// spre exemplu daca avem doar 3 hobby-uri, in urma sortarii vom avea o lista de tipul
// {"", "", "Jocuri", "Programare", "Proiectare"}
// pentru a acoperi si acest caz, vom numara cate elemente non-0 avem in vector

typedef struct {
    char nume[50];
    char prenume[50];
    char oras[50];
    char liceu[50];
    char hobby[10][50];
} Elev;

// prototipuri functii
void afisare(Elev *e, int n);
void sortare(Elev *e, int n);

int main(void) {
    Elev elev = {
        "STEFAN",
        "Denis-Marius",
        "Ploiesti",
        "Colegiul National Ion Luca Caragiale",
        {"Proiectare", "Programare", "Jocuri", "Filme", "Muzica"}
    };
    printf("Inainte de sortare:\n");
    // pentru a rezolva edge case-ul mentionat, aflam numarul de elemente de lungime non-0 din vector
    // pentru a afla numarul de elemente totale din vector, luam marimea totala in bytes a vectorului si o impartim la
    // marimea in bytes a unui element oarecare din vector
    int n = 0;
    for (int i = 0, k = sizeof(elev.hobby) / sizeof(elev.hobby[0]); i < k; i++) {
        if (strlen(elev.hobby[i]) > 0) {
            n++;
        }
    }
    // pentru a nu pierde timp cu copiatul structurii intre apeluri, in loc de a transmite intreaga structura catre functii
    // transmitem doar un pointer catre aceasta
    afisare(&elev, n);
    sortare(&elev, n);
    printf("Dupa sortare:\n");
    afisare(&elev, n);
    return 0;
}

void afisare(Elev *e, const int n) {
    printf("Nume: %s\n", e->nume);
    printf("Prenume: %s\n", e->prenume);
    printf("Oras: %s\n", e->oras);
    printf("Liceu: %s\n", e->liceu);
    printf("Hobby-uri: ");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%s, ", e->hobby[i]);
        } else {
            printf("%s\n", e->hobby[i]);
        }
    }
}

void sortare(Elev *e, const int n) {
    // vom folosi bubble sort pentru sortare, deoarece avem un numar mic de elemente in vector nu avem neaparat nevoie de eficienta
    // pentru scalabilitate am putea modifica algoritmul in quicksort, sau am putea folosi o functie standard a limbajului
    int s;
    char temp[50];
    do {
        s = 0;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(e->hobby[i], e->hobby[i + 1]) > 0) {
                strcpy(temp, e->hobby[i]);
                strcpy(e->hobby[i], e->hobby[i + 1]);
                strcpy(e->hobby[i + 1], temp);
                s++;
            }
        }
    } while (s != 0);
}
