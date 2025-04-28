#include <iostream>

#include <autor.h>
#include <cancion.h>
#include <disco.h>
#include <catalogo.h>
using namespace std;

int main()
{
    //Autores
    cout<<"Autores"<<endl;
    Autor autor1 = Autor();
    autor1.setNombre("Manuel");

    Autor autor2 = Autor();
    autor2.setNombre("Jose");
    cout << autor2.getNombre() << endl;

    Autor autor3 = Autor();
    autor3.setNombre("Divididos");
    cout << autor3.getNombre() << endl;

    Autor autor4 = Autor();
    autor4.setNombre("Menfis La Blusera");
    cout << autor4.getNombre() << endl;

    //Canciones
    cout<<"Canciones"<<endl;
    Cancion cancion1 = Cancion();
    cancion1.setNombre("Amanecer");
    cancion1.setDuracion(2);
    cancion1.setAutor(autor1);

    Cancion cancion2 = Cancion();
    cancion2.setNombre("La pipina");
    cancion2.setDuracion(3);
    cancion2.setAutor(autor2);

    Cancion cancion3 = Cancion();
    cancion3.setNombre("Cancion Animal");
    cancion3.setDuracion(4);
    cancion3.setAutor(autor2);

    cout << cancion1.getNombre() << " " << cancion1.getDuracion() << " - Autor:" << cancion1.getAutor().getNombre() << endl;
    cout << cancion2.getNombre() << " " << cancion2.getDuracion() << " - Autor:" << cancion2.getAutor().getNombre() << endl;

    Cancion cancion4 = Cancion();
    cancion4.setNombre("Ala delta");
    cancion4.setDuracion(2);
    cancion4.setAutor(autor3);

    Cancion cancion5 = Cancion();
    cancion5.setNombre("La bifurcada");
    cancion5.setDuracion(3);
    cancion5.setAutor(autor4);


    //Discos
    cout << "Discos"<<endl;
    Disco disco1 = Disco();
    disco1.setNombre("Disco 1");
    Disco disco2 = Disco();
    disco2.setNombre("Disco 2");

    cout << disco2.getNombre() << endl;

    //Agrego canciones a discos
    disco1.addCancion(cancion1);
    disco1.addCancion(cancion2);
    disco1.addCancion(cancion3);

    disco2.addCancion(cancion4);
    disco2.addCancion(cancion5);
    disco2.addCancion(cancion1);

    Catalogo catalogo("Musica diversa");
    catalogo.addDisco(disco1);
    catalogo.addDisco(disco2);
    cout<<endl << "Muestra los catalogos"<<endl;
    cout<<"************************"<<endl;
    catalogo.mostrarCatalogo();
    Catalogo catalogo2("nacionales");
    catalogo2.addDisco(disco2);
    cout << ""<<endl;
    catalogo2.mostrarCatalogo();
    return 0;
}
