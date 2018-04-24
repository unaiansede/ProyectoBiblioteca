#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "string.h"

void modificarUsuario(tUsuario* aUsuarios,char* nomfich, char* dni, char* con)
{
    int encontrado,cont=0;
    int i,j=0;
    FILE* f;
    tUsuario modificar;
    encontrado=buscarUsuario(nomfich,dni,con);
    if(encontrado==0){
        //Pedir nuevos datos
        printf("Introduce una nueva contrasenya\n");
        fflush(stdin);
        gets(modificar.con);
        printf("Introduce un nuevo nombre\n");
        fflush(stdin);
        gets(modificar.nom);
        printf("Introduce un nuevo numero de libros\n");
        fflush(stdin);
        modificar.numLibros = getc(stdin) - '0';
        f=fopen(nomfich,"r");
        if(f!=(FILE*)NULL){
            int pos;
            while(fscanf(f,"%s %s %s %d\n",modificar.dni,modificar.nom,modificar.con,&modificar.numLibros)!=EOF)
                cont++;
                fseek(f,0,SEEK_SET); //se posiciona el puntero al principio del fichero mdiante esta funci�n

            aUsuarios = (tUsuario*)malloc(cont*sizeof(tUsuario));
            while(fscanf(f,"%s %s %s %d\n",modificar.dni,modificar.nom,modificar.con,&modificar.numLibros)!=EOF){
                if(strcmp(modificar.dni,dni)==0)
                    pos=i;
                    aUsuarios[i] = modificar;
            }
            fclose(f);
            f=fopen(nomfich,"w");
            if(f!=(FILE*)NULL){
                for(pos;j<4;j++){
                    fprintf(f,"%s %s %s %d\n",modificar.dni,modificar.nom,modificar.con,modificar.numLibros);
                }
                fclose(f);
            }

        }





    }else{
        printf("\nERROR! No se ha encontrado el usuario en el sistema");
    }

}

void eliminarUsuario(tUsuario* aUsuarios, char* nomfich, char* dni)
{
    printf("Introduce el dni de usuario que quieres dar de baja:\n");
    fflush(stdin);
    gets(dni);
    darDeBajaUsuario(nomfich,dni);


}

void crearLibro(Libro* aLibros,char* nomfich)
{
    int encontrado=0;
    FILE* f;
    Libro l;
    l=pedirLibro();
    encontrado=buscarLibro(nomfich,l.isbn,&l);
    if(encontrado!=0){
        printf("\nERROR! Ese libro ya esta registrado en el sistema");
    }else{
         f=fopen(nomfich,"a");
         if(f!=(FILE*)NULL){
            fprintf(f,"%s %s %s\n",l.titulo,l.autor,l.isbn);
            fclose(f);
         }
}

void modificarLibro(Libro* aLibros,char* nomfich, char* isbn)
{
    int encontrado,cont=0;
    int i,j=0;
    FILE* f;
    Libro modificar;
    encontrado=buscarLibro(nomfich,isbn,l);
    if(encontrado==0){
        //Pedir nuevos datos
        printf("Introduce un nuevo titulo\n");
        fflush(stdin);
        gets(modificar.titulo);
        printf("Introduce un nuevo autor\n");
        fflush(stdin);
        gets(modificar.autor);
        printf("Introduce un nuevo isbn\n");
        fflush(stdin);
        gets(modificar.isbn);
        f=fopen(nomfich,"r");
        if(f!=(FILE*)NULL){
            int pos;
            while(fscanf(f,"%s %s %s\n",modificar.titulo,modificar.autor,modificar.isbn)!=EOF)
                cont++;
            fseek(f,0,SEEK_SET); //se posiciona el puntero al principio del fichero mdiante esta funci�n

            aLibros = (Libro*)malloc(cont*sizeof(Libro));
            while(fscanf(f,"%s %s %s\n",modificar.titulo,modificar.autor,modificar.isbn)!=EOF){
                if(strcmp(modificar.isbn,isbn)==0)
                    pos=i;
                aLibros[i] = modificar;
            }
            fclose(f);
            f=fopen(nomfich,"w");
            if(f!=(FILE*)NULL){
                for(pos;j<4;j++){
                    fprintf(f,"%s %s %s\n",modificar.titulo,modificar.autor,modificar.isbn);
                }
                fclose(f);
            }

        }





    }else{
        printf("\nERROR! No se ha encontrado el libroo en el sistema");
    }

}

void eliminarLibro(Libro* aLibros,char* nomfich, char* isbn) {
    FILE *f;
    Libro l;
    int contador = 0;
    int i = 0;
    int pos, j;
    f = fopen(nomfich, "r");
    if (f != (FILE *) NULL) {
        while (fscanf(f, "%s %s %s \n", l.titulo, l.autor, l.isbn) != EOF)
            contador++;
    }
        fseek(f, 0, SEEK_SET);
        aLibros = (Libro *) malloc(contador * sizeof(Libro));
        while (fscanf(f, "%s %s %s %d\n", l.titulo, l.autor, l.isbn) != EOF) {
            if (strcmp(l.isbn, isbn) == 0) {}
            pos = i;
            aLibros[i] = l;
            i++;
        }
        fclose(f);
        for (j = pos; j < i - 1; j++) {
            aLibros[j] = aLibros[j + 1];
            i--;
        }
        f = fopen(nomfich, "w");
        if (f != (FILE *) NULL) {
            for (j = 0; j < i; j++)
                fprintf(f, "%s %s %s %d\n", aLibros[j].titulo, aLibros[j].autor, aLibros[j].isbn);
            fclose(f);
        }

    }
}


