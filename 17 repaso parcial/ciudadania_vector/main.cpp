#include "persona.h"
#include <iostream>
#include <fstream>
#include "gestorciudadania.h"
#include <iostream>

void imprimirArbol(Persona* persona, int nivel = 0) {
    if (!persona) return;
    std::cout << std::string(nivel * 2, ' ') << "Apellido y Nombre: "<< persona->getApellido() <<" " << persona->getNombre()
              << ", DNI: " << persona->getDNI()
              << ", Nacionalidad: " << persona->getNacionalidad() << "\n";
    imprimirArbol(persona->getPadre(), nivel + 1);
    imprimirArbol(persona->getMadre(), nivel + 1);
}

int main() {
    // Crear gestor
    GestorCiudadania gestor;

    // Crear arbol genealogico
    Persona* tatarabuelo1 = new Persona("0001", "Luigi", "Rossi", "Italiana");
    Persona* tatarabuela1 = new Persona("0002", "Pia", "Mulonni", "Italiana");

    Persona* bisabuelo1 = new Persona("1001", "Giuseppe", "Rossi", "Italiana");
    Persona* bisabuela1 = new Persona("1002", "Maria", "Bianchi", "Italiana");
    bisabuelo1->setPadre(tatarabuelo1);
    bisabuelo1->setMadre(tatarabuela1);

    Persona* abuelo1 = new Persona("2001", "Luigi", "Rossi", "Argentina");
    abuelo1->setPadre(bisabuelo1);
    abuelo1->setMadre(bisabuela1);

    Persona* madre = new Persona("3001", "Lucia", "Gomez", "Argentina");
    madre->setPadre(abuelo1);

    Persona* padre = new Persona("3002", "Carlos", "Rossi", "Argentina");

    Persona* persona = new Persona("4001", "Valentino", "Rossi", "Argentina");
    persona->setPadre(padre);
    persona->setMadre(madre);

    imprimirArbol(persona);
    std::cout << std::endl;
    // Verificar ciudadania
    std::cout << "Apto para ciudadania italiana? "
              << (gestor.esAptoParaCiudadania(persona) ? "Si" : "No") << std::endl;
    std::cout << std::endl;
    // Contar antepasados italianos
    std::cout << "Cantidad de antepasados italianos: "
              << gestor.contarAntepasadosItalianos(persona) << std::endl;
    std::cout << std::endl;
    // Buscar antepasado por nombre
    std::string nombreBuscado = "Giuseppe";
    std::cout << "Tiene antepasado llamado " << nombreBuscado << "? "
              << (gestor.tieneAntepasadoConNombre(persona, nombreBuscado) ? "Si" : "No") << std::endl;
    std::cout << std::endl;
    // Guardar archivos
    gestor.guardarTexto(persona, "arbol_genealogico.txt");
    gestor.guardarBinario(persona, "arbol_genealogico.bin");
    std::cout << std::endl;
    /*
     * Varios arboles
    */

    //Ejemplo 1: Persona con 2 abuelos italianos
    Persona* abueloPaterno_ej1 = new Persona("1111", "Antonio", "Ferrari", "Italiana");
    Persona* abuelaPaterna_ej1 = new Persona("1112", "Claudia", "Moretti", "Italiana");

    Persona* padre_ej1 = new Persona("2222", "Marco", "Ferrari", "Argentina");
    padre_ej1->setPadre(abueloPaterno_ej1);
    padre_ej1->setMadre(abuelaPaterna_ej1);

    Persona* madre_ej1 = new Persona("2223", "Laura", "Gomez", "Argentina");

    Persona* persona_ej1 = new Persona("3333", "Nico", "Ferrari", "Argentina");
    persona_ej1->setPadre(padre_ej1);
    persona_ej1->setMadre(madre_ej1);
    imprimirArbol(persona_ej1);

    //Ejemplo 2: Persona con 1 bisabuelo italiano
    Persona* bisabueloMaterno_ej2 = new Persona("4444", "Giovanni", "Russo", "Italiana");

    Persona* abueloMaterno_ej2 = new Persona("5555", "Pedro", "Russo", "Argentina");
    abueloMaterno_ej2->setPadre(bisabueloMaterno_ej2);

    Persona* madre_ej2 = new Persona("6666", "Ana", "Russo", "Argentina");
    madre_ej2->setPadre(abueloMaterno_ej2);

    Persona* padre_ej2 = new Persona("6667", "Luis", "Martinez", "Argentina");

    Persona* persona_ej2 = new Persona("7777", "Sofia", "Martinez", "Argentina");
    persona_ej2->setPadre(padre_ej2);
    persona_ej2->setMadre(madre_ej2);
    imprimirArbol(persona_ej2);

    //Ejemplo 3: Persona con sin descendientes italiano
    Persona* bisabueloMaterno_ej3 = new Persona("8888", "Juan", "Gomez", "Rusa");

    Persona* abueloMaterno_ej3 = new Persona("9999", "Jorge", "Andino", "Argentina");
    abueloMaterno_ej3->setPadre(bisabueloMaterno_ej3);

    Persona* madre_ej3 = new Persona("9090", "Maru", "Perez", "Argentina");
    madre_ej3->setPadre(abueloMaterno_ej3);

    Persona* padre_ej3 = new Persona("8989", "Cristian", "Martinez", "Argentina");

    Persona* persona_ej3 = new Persona("9898", "Marta", "Martinez", "Argentina");
    persona_ej3->setPadre(padre_ej3);
    persona_ej3->setMadre(madre_ej3);
    imprimirArbol(persona_ej3);

    // Agregar todos los árboles al gestor
    gestor.agregarPersona(persona);
    gestor.agregarPersona(persona_ej1);
    gestor.agregarPersona(persona_ej2);
    gestor.agregarPersona(persona_ej3);
    std::cout << std::endl;
    // Evaluar todos los árboles
    gestor.evaluarCiudadania();
    std::cout << std::endl;
    // Liberar memoria
    for (Persona* p : {persona, persona_ej1, persona_ej2}) delete p;

    return 0;
}
