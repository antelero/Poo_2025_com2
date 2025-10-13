#ifndef POST_H
#define POST_H

#include <string>
#include <vector>
using namespace std;

// Estructura del registro en archivo binario
struct PostRecord {
    char numero[10];
    char url[250];
    char autor[200];
    char fecha[9]; //Agregue una porque sino no tenia capacidad para guardar el \0
};

class Post {
private:
    string numero;
    string url;
    string autor;
    string fecha;
    vector<string> comentarios;

public:
    Post(const string &numero, const string &url,
         const string &autor, const string &fecha);

    string getNumero() const;
    string getUrl() const;
    string getAutor() const;
    string getFecha() const;
    int getCantidadComentarios() const;

    void cargarComentarios();
    void mostrar() const;
};

#endif
