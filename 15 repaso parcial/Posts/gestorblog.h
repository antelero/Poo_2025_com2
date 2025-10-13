#ifndef GESTORBLOG_H
#define GESTORBLOG_H
#include <cstring>
#include "post.h"
#include <vector>
#include <string>

using namespace std;

class GestorBlog {
private:
    vector<Post> posts;

public:
    void generarDummyPosts();
    void cargarPosts();
    void ordenarPorComentarios();
    void mostrarPosts() const;
};

#endif
