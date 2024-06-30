#include "../studente_corso.h"
#include "../../basic/array.h"
#include <stdio.h>

float calcola_media(Studente s)
{
    int somma = 0;
    int voti_validi = 0;

    for (int i = 0; i < N_VOTI; i++)
    {
        int voto = s.voti[i];
        if (voto >= 0 && voto <= 30)
        {
            somma += voto;
            voti_validi++;
        }
    }

    if (voti_validi <= 0)
    {
        return 0.0;
    }

    return somma / (float)voti_validi;
}

void stampa_studente(Studente s)
{
    printf("Nome: %s\nCognome: %s\nVoti: ", s.nome, s.cognome);
    stampa_array(s.voti, N_VOTI);
    printf("\n");
}
