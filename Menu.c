#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include "Menu.h"
#include "usuario.h"
#include "usuario.c"

void Menu(){
    printf("\n -----------------------------------------------------------");
    printf("\n Bienvenido a la libreria digital");
    printf("\n -----------------------------------------------------------");
    Opciones();

}
void Opciones(){
    printf("\n Seleccione una opcion");
    char c;
    bool f=false;
do{
printf("\n Opciones:");
printf("\n 1.Usuarios");
printf("\n 2.Administradores");
printf("\n 3.Libros");
printf("\n 9 Salir del programa");
scanf("%c",&c);

    switch(c){
        case '1':
        MUsuarios();
        f=true;
        break;



        case '2':
        MAdministradores();
        f=true;
        break;
        case '3':
        MLibros();
        f=true;
        break;



        case '9':
        printf("\n Adios");
        f=true;
        break;


    }

}while (f==false);
}

void MUsuarios(){
char c;
bool f=false;
printf("\n -----------------------------------------------------------");
printf("\n Bienvenido al menu de Usuarios");
printf("\n -----------------------------------------------------------");
    while(f==false){
    printf("\n 1 Para crear un usuario");
    printf("\n 2 Para iniciar sesion");
    printf("\n 9 Para salir");
    fflush(stdin);
    scanf("%c",&c);
        tUsuario user;

        switch(c){
            case '1':
                user= pedirUsuario();
                f=true;
                break;

            case'2':
                printf("\n Numero DNI");
                scanf("%s",&user.dni);
                printf("\n Contrasenya");
                scanf("%s",&user.con);
                char *nomfich="usuario.txt";
                buscarUsuario(*nomfich,user.dni,user.con);
                f=true;
                break;

            case '9':
            printf("\n Adios");
            f=true;
            break;

        }


    }
}
void MAdministradores(){
char e;
bool f=false;
printf("\n Bienvenido al menu de Administradores");
    do{
    printf("\n 1 Para crear un libro");
    printf("\n 9 Para salir");
    scanf("%e",&e);
        switch(e){
        case '1':
        printf("\n Libro");
        f=true;
        break;
        case '9':
        printf("\n Adios");
        f=true;
        break;
        }
    }while(f==false);
}
void MLibros(){
printf("\n Libros");
}
void InicioSesion(){
char Nombre[20];
char Contrasenya[20];
bool f=false;

    do{
    printf("\n Nombre de usuario:");
    scanf("%s",&Nombre);
    printf("\n %s",Nombre);
    printf("\n Contrasenya:");
    scanf("%s",&Contrasenya);
    printf("\n %s",Contrasenya);
    f=true;
    }while(f==false);
}
