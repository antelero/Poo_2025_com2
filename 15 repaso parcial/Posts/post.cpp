#include "post.h"
#include <iostream>
#include <fstream>
using namespace std;

Post::Post(const string &numero, const string &url,
           const string &autor, const string &fecha)
    : numero(numero), url(url), autor(autor), fecha(fecha) {}

string Post::getNumero() const { return numero; }
string Post::getUrl() const { return url; }
string Post::getAutor() const { return autor; }
string Post::getFecha() const { return fecha; }
int Post::getCantidadComentarios() const { return comentarios.size(); }

void Post::cargarComentarios() {
    string filename = "comentario_" + numero + ".txt";
    ifstream file(filename);
    comentarios.clear();
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            if (!linea.empty()) {
                comentarios.push_back(linea);
            }
        }
        file.close();
    }
}

void Post::mostrar() const {
    cout << "Post " << numero << " (" << fecha << ") - " << autor
         << " [" << comentarios.size() << " comentarios]" << endl;
}
