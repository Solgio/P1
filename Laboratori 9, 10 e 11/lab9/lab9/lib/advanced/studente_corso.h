#include <stdio.h>

#define N_VOTI 5

typedef struct studente
{
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
} Studente;


//----studente.c---//
// PRE: s è uno studente valido (voti compresi tra 0 e 30 oppure uguali a -1)
float calcola_media(Studente s);
// POST calcolare la media dei voti conseguiti (esami svolti)

void stampa_studente(Studente s);
// Funzione di utilità per stampare a schermo tutti i dati dello studente. Seguire l'esempio riportato di seguito.
/* Esempio di stampa
 * Nome: Michele
 * Cognome: Poggi
 * Voti: [1,2,3,4,5]
 */

//----parser.c----//
int conta_linee(FILE *fp);
// POST: conta il numero di righe nel file

void leggi_studente(FILE *fp, Studente *s);
// POST: legge da file i dati relativi ad un unico studente

void scrivi_studente(FILE *fp, Studente s);
// POST: scrive su file i dati di un unico studente