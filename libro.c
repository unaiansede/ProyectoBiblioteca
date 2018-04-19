#include "libro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pide al usuario escoger un libro y guarda el isbn de dicho libro en *isbn
void escogerLibro(Libro *aLibros, int tamanyo, char *isbn){
    int i;
    int *seleccion = malloc(sizeof(int));

    for(i = 0; i<tamanyo;i++){
        printf("%i. Titulo:%s Autor: %s \n",i,aLibros[i].titulo,aLibros[i].autor);
    }
    do {
        printf("Seleccione un libro: ");
        fflush(stdin);
        scanf("%i", seleccion);
    } while(*seleccion >=tamanyo);

    strcpy(isbn,aLibros->isbn);
}

int buscarLibro(char *nomfich, char *isbn, Libro *libro){
    /*La función devuelve:
        - 0, si el libro no existe
        - 1, si el libro existe, y lo guarda en *libro
    */
    FILE *f;
    int enc=0;
    Libro l;

    f=fopen(nomfich,"r");
    if(f!=(FILE*)NULL){
        while(enc==0 && fscanf(f,"%s %s %s \n",l.titulo,l.autor,l.isbn)!=EOF){
            if(strcmp(l.isbn,isbn)==0){
                enc = 1;
            }
        }
        fclose(f);
    }
    strcpy(l.isbn,libro->isbn);
    strcpy(l.titulo,libro->titulo);
    strcpy(l.autor,libro->autor);

    return enc;
}

Libro pedirLibro(){
    Libro l;

    printf("\nIntroduce el titulo del libro: ");
    fflush(stdin);
    gets(l.titulo);
    printf("\nIntroduce el autor del libro: ");
    fflush(stdin);
    gets(l.autor);
    printf("\nIntroduce el ISBN: ");
    fflush(stdin);
    gets(l.isbn);

    return l;
}

void registrarLibro(char *nomfich){
    int enc;
    FILE *f;
    Libro l;

    l = pedirLibro();
    enc=buscarLibro(nomfich,l.isbn,&l);

    if(enc == 1){
        printf("\nERROR! Ese libro ya existe en la base de datos");
    } else{
        f=fopen(nomfich,"a");
        if(f!=(FILE*)NULL){
            fprintf(f,"%s %s %s\n",l.titulo,l.autor,l.isbn);
            fclose(f);
        }
    }
}

