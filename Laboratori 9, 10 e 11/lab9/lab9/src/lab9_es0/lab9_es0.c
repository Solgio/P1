#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

// questo esercizio non richiede di scrivere codice, le funzioni sugli studenti
// sono già state implementate per voi. verificate che funzionino correttamente
// eseguendo il codice di test qui sotto
int main(void)
{
    // test calcola media

    Studente s1 = {"Mario", "Rossi", {-1, -1, -1, -1, -1}};
    Studente s2 = {"Giorgio", "Bianchi", {10, -1, 12, -1, -1}};
    Studente s3 = {"Lucia", "Verdi", {10, 10, 13, 16, 16}};

    printf("%f\n", calcola_media(s1)); // 0.0
    printf("%f\n", calcola_media(s2)); // 11.0
    printf("%f\n", calcola_media(s3)); // 13.0

    // test stampa studente

    stampa_studente(s1);
    // Nome: Mario
    // Cognome: Rossi
    // Voti: [-1,-1,-1,-1,-1]

    return 0;
}
