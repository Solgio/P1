// io
void stampa_array(int*, int);
void leggi_array(int*, int);
void stampa_array_double(double*, int);
void leggi_array_double(double*, int);

//read_only
/* 
    PRE: A e B hanno dimensione dim
    POST: Restituisce 1 se per ogni i. 0<=i<dim, A[i]=B[i]
                      0 altrimenti
*/
int confronta_array(int* A, int* B, int dim);

/*
    confronta_array() per tipi double
    
    PRE: A e B hanno dimensione dim, toll>=0
    POST: Restituisce 1 se per ogni i. 0<=i<dim, |A[i]-B[i]|<toll
                      0 altrimenti
*/
int confronta_array_double(double *X, double *Y, int dim, double toll);
