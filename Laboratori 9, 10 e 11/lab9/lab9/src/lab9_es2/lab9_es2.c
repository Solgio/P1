#include <advanced/studente_corso.h>
#include <stdio.h>
#include <stdlib.h>

// PER LA CONSEGNA MOODLE:
// riportare le implementazioni di `conta_linee` e `leggi_studente` di seguito,
// se svolto offline invece le implemetnazioni possono essere spostate in libreria

// PRE: fp punta all'inizio di un file studenti
int conta_linee(FILE *fp);
// POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file

void leggi_studente(FILE *fp, Studente *s);
// POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s

void scrivi_studente(FILE *fp, Studente s);
// POST: scrive su file i dati di un unico studente

int main(void)
{
    FILE *fp;
    fp = fopen("studenti.txt", "r");
    if (fp == NULL)
    {
        printf("Il file non può essere aperto\n");
    }
    else
    {
        // LETTURA DA FILE

        int n_stud = conta_linee(fp);
        Studente s[n_stud];

        for (int i = 0; i < n_stud; i++)
        {
            leggi_studente(fp, s + i);
        }

        fclose(fp);

        printf("Trovati %d studenti\n", n_stud);

        // SCRITTURA SU FILE

        fp = fopen("studenti_suff.txt", "w");
        int n_suff = 0;

        for (int i = 0; i < n_stud; i++)
        {
            if (calcola_media(s[i]) >= 18)
            {
                scrivi_studente(fp, s[i]);
                n_suff++;
            }
        }

        fclose(fp);

        printf("Scritti su file %d studenti sufficienti\n", n_suff);
    }

    return 0;
}
