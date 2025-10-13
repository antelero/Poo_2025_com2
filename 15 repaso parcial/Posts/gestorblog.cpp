#include "gestorblog.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

void GestorBlog::generarDummyPosts()
{

    // Crear algunos registros de prueba
    vector<PostRecord> registros = {
        {"1", "http://blog.com/post1", "Autor Uno", "20250101"},
        {"2", "http://blog.com/post2", "Autor Dos", "20250102"},
        {"3", "http://blog.com/post3", "Autor Tres", "20250103"}
    };

    // Guardar en archivo binario post.dat
    ofstream out("posts.dat", ios::binary);
    if (!out.is_open()) {
        cerr << "No se pudo crear el archivo " << "posts.dat" << endl;
        return;
    }

    for (auto &r : registros) {
        PostRecord record{};
        memset(&record, 0, sizeof(PostRecord));
        strncpy(record.numero, r.numero, sizeof(record.numero)-1);
        strncpy(record.url, r.url, sizeof(record.url)-1);
        strncpy(record.autor, r.autor, sizeof(record.autor)-1);
        strncpy(record.fecha, r.fecha, sizeof(record.fecha)-1);

        out.write(reinterpret_cast<char*>(&record), sizeof(PostRecord));
    }
    out.close();

    cout << "Archivo " << "posts.dat" << " generado correctamente." << endl;

    // Generar comentarios en archivos texto
    vector<vector<string>> comentarios = {
        {"Muy buen post", "Me gusto mucho", "Excelente explicación"},
        {"No estoy de acuerdo", "Faltan ejemplos"},
        {"Genial aporte"}
    };

    for (size_t i = 0; i < comentarios.size(); i++) {
        string filename = "comentario_" + to_string(i+1) + ".txt";
        ofstream fout(filename);
        if (fout.is_open()) {
            for (const auto &c : comentarios[i]) {
                fout << c << "\n";
            }
            fout.close();
            cout << "Archivo " << filename << " generado." << endl;
        }
    }
}

void GestorBlog::cargarPosts() {
    ifstream file("posts.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << "posts.dat" << endl;
        return;
    }

    PostRecord record;
    while (file.read(reinterpret_cast<char*>(&record), sizeof(PostRecord))) {
        string numero(record.numero, strnlen(record.numero, sizeof(record.numero)));
        string url(record.url, strnlen(record.url, sizeof(record.url)));
        string autor(record.autor, strnlen(record.autor, sizeof(record.autor)));
        string fecha(record.fecha, strnlen(record.fecha, sizeof(record.fecha)));

        Post p(numero, url, autor, fecha);
        p.cargarComentarios();
        posts.push_back(p);
    }

    file.close();
}

void GestorBlog::ordenarPorComentarios() {
    sort(posts.begin(), posts.end(),
         [](const Post &a, const Post &b) {
             return a.getCantidadComentarios() > b.getCantidadComentarios();
         });
}

void GestorBlog::mostrarPosts() const {
    for (const auto &p : posts) {
        p.mostrar();
    }
}
