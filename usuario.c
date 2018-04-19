#include <stdio.h>
#include <mem.h>
#include <malloc.h>
#include "usuario.h"

tUsuario pedirUsuario(){
    tUsuario u;

    printf("\nIntroduce el nombre de usuario: ");
    fflush(stdin);
    gets(u.nom);
    printf("\nIntroduce la contrasenya del usuario: ");
    fflush(stdin);
    gets(u.con);
    printf("\nIntroduce el dni del usuario: ");
    fflush(stdin);
    gets(u.dni);
    u.numLibros = 0;

    return u;
}

int buscarUsuario(char *nomfich, char *dni, char *con){
    /*La funcion devuelve:
        - 0, si el dni no existe
        - 1, si el dni existe pero la contrasenya no es correcta
        - 2, si el dni existe y ademas la contrasenya es correcta
    */
    FILE *f;
    int enc=0;
    tUsuario u;

    f=fopen(nomfich,"r");
    if(f!=(FILE*)NULL){
            while(enc==0 && fscanf(f,"%s %s %s %d\n",u.dni,u.nom,u.con,&u.numLibros)!=EOF){
                if(strcmp(u.dni,dni)==0){
                    if(strcmp(u.con,con)==0){
                        enc=2;
                    }else{
                        enc=1;
                    }
                }
            }
            fclose(f);
    }
    return enc;
}
void registrarUsuario(char *nomfich){
    int enc;
    FILE *f;
    tUsuario u;

    u=pedirUsuario();
    enc=buscarUsuario(nomfich,u.dni,u.con);
    if(enc!=0){
        printf("\nERROR! Ese usuario ya esta registrado en el sistema");
    }else{
        f=fopen(nomfich,"a");
        if(f!=(FILE*)NULL){
            fprintf(f,"%s %s %s %d\n",u.dni,u.nom,u.con,u.numLibros);
            fclose(f);
        }
    }
}

void darDeBajaUsuario(char *nomfich, char *dni){

    FILE *f;
    int cont=0,i=0,pos,j;
    tUsuario u,*aUsuarios;

    f=fopen(nomfich,"r");
    if(f!=(FILE*)NULL){
        while(fscanf(f,"%s %s %s %d\n",u.dni,u.nom,u.con,&u.numLibros)!=EOF)
            cont++;
fseek(f,0,SEEK_SET); //se posiciona el puntero al principio del fichero mdiante esta funcion

        aUsuarios = (tUsuario*)malloc(cont*sizeof(tUsuario));
        while(fscanf(f,"%s %s %s %d\n",u.dni,u.nom,u.con,&u.numLibros)!=EOF){
if(strcmp(u.dni,dni)==0)
                pos=i;
            aUsuarios[i] = u;
            i++;
        }
        fclose(f);
        for(j=pos;j<i-1;j++)
            aUsuarios[j] = aUsuarios[j+1];
        i--;

        f=fopen(nomfich,"w");
        if(f!=(FILE*)NULL){
            for(j=0;j<i;j++)
                fprintf(f,"%s %s %s %d\n",aUsuarios[j].dni,aUsuarios[j].nom,aUsuarios[j].con,aUsuarios[j].numLibros);
            fclose(f);
        }

    }
}
