
#ifndef BIBLIOTECA_LIBRO_H
#define BIBLIOTECA_LIBRO_H

typedef struct{
    char titulo[50];
    char isbn[13];
    char autor[20];
}Libro;

void escogerLibro(Libro *aLibros, int tamanyo, char *isbn);
int buscarLibro(char *nomfich, char *isbn, Libro *libro);
Libro pedirLibro();
void registrarLibro(char *nomfich);

#endif //BIBLIOTECA_LIBRO_H
