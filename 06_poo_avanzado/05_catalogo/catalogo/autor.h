#ifndef AUTOR_H
#define AUTOR_H


class Autor
{
private:
    char * nombre;
public:
    Autor();
    void setNombre(char *nombre);
    char * getNombre();
};

#endif // AUTOR_H
