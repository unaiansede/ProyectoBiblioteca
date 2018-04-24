#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "libro.h"
#include "usuario.h"

typedef struct{
    char nick[20];
    char pass[20];
}Administrador;

void modificarUsuario(tUsuario* aUusuarios,char* nomfich,char* dni,char* con);
void eliminarUsuario(tUsuario* aUusuarios,char* nomfich,char* dni);
void crearLibro(Libro* aLibros,char* nomfich);
void modificarLibro(Libro* aLibros);
void eliminarLibro(Libro* aLibros,char*nomfich,char* isbn);

#endif // ADMIN_H_INCLUDED
