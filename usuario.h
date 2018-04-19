#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct usuario{
    char nom[20];
    char con[20];
    char dni[10];
    int numLibros;
}tUsuario;

tUsuario pedirUsuario();
int buscarUsuario(char *nomfich, char *dni, char *con);
void registrarUsuario(char *nomfich);
void darDeBajaUsuario(char *nomfich, char *dni);


#endif // USUARIO_H_INCLUDED
