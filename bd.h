#ifndef PROYECTOBIBLIOTECA_BD_H
#define PROYECTOBIBLIOTECA_BD_H

class bd{
    public:
        int insertarUsuario(sqlite3 *bd, char name[]);
};

#endif //PROYECTOBIBLIOTECA_BD_H
