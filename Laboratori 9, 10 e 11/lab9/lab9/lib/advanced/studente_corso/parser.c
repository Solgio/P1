#include "../studente_corso.h"
#include "stdio.h"

// spostare qui l'implementazione delle funzioni `conta_linee`, `leggi_studente`, `scrivi_studente`

// PRE: fp punta all'inizio di un file studenti
int conta_linee(FILE *fp){
    int count=1;
    char chara;
    rewind(fp);
    while((chara=getc(fp))!=EOF)
        {
            if(chara=='\n')
                count++;
        }
           rewind(fp);
    return count;
};
// POST: conta il numero di entries nel file, fp punta di nuovo all'inizio del file

void leggi_studente(FILE *fp, Studente *s){

    fscanf(fp, "%s", s->nome);
    fscanf(fp, "%s", s->cognome);

    for(int i=0; i<N_VOTI; i++){
        fscanf(fp, "%d", &s->voti[i]);
    }
}
// POST: legge da file i dati relativi ad un unico studente e li copia nella variabile studente puntata da s

