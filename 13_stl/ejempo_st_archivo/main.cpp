#include <iostream>

#include <alumno.h>
#include <curso.h>
#include <alumnonormal.h>
#include <alumnovocacional.h>
#include <alumnolibre.h>
#include <alumnoespecial.h>

using namespace std;

int main()
{
    Curso *curso = new Curso("curso");
    Alumno * gPtr;
//
    AlumnoNormal *leo= new AlumnoNormal(25907286,"leo","brambi",10,50,30,20);
    AlumnoNormal *jose= new AlumnoNormal(25907281,"jose","deser",100,50,60,70);
    curso->addAlumno(leo);
    curso->addAlumno(jose);
    AlumnoVocacional *manu= new AlumnoVocacional(25907282,"manu","gino",70);
    AlumnoVocacional *pepe= new AlumnoVocacional(25907283,"pepe","mujica",40);

    curso->addAlumno(manu);
    curso->addAlumno(pepe);

    AlumnoLibre *pepa= new AlumnoLibre(25907284,"pepa","pig",70,80);
    AlumnoLibre *rober= new AlumnoLibre(25907285,"rober","deniro",80,50);

    curso->addAlumno(pepa);
    curso->addAlumno(rober);
    cout << "################ Polimorfismo ##################" << endl;


    for(int i=0;i<curso->getCantidad();i++){
        gPtr = (curso->getAlumno(i));
        cout <<  gPtr->getNombres() << ", " << gPtr->getApellido() << ":  " << (gPtr->getCondicion()) << endl;//area() <<endl;
    };


  // Realice un listado de los emails otorgados por la facultad, estos se conforman
  // con la primera letra del nombre, el apellido y finaliza con “@uader.edu.ar”
    cout << "######## Lista de emails ########" << endl;
    for(int i=0;i<curso->getCantidad();i++){
        std::string  email = (curso->getAlumno(i))->getEmail();
        cout <<  email <<endl;

    };

    //Punto 2
    cout << "#############       Alumno Especial        ###################" << endl;
    AlumnoEspecial *alespe1= new AlumnoEspecial(25907284,"pepa","pig");
    alespe1->addNota(50);
    alespe1->addNota(40);
    alespe1->addNota(60);
    alespe1->addNota(60);
    cout << *(alespe1) << " Promedio " << alespe1->getPromedio() << " - " << alespe1->getCantidad() << endl;
    AlumnoEspecial *alespe2= new AlumnoEspecial(25907285,"rober","deniro");
    alespe2->addNota(70);
    alespe2->addNota(80);
    alespe2->addNota(60);
    alespe2->addNota(65);
    alespe2->addNota(90);
    cout << *(alespe2) << " Promedio " << alespe2->getPromedio() << " - " << alespe2->getCantidad() << endl;
    alespe2->delNota(4);
    cout << *(alespe2) << " Promedio Nuevo " << alespe2->getPromedio() << " - " << alespe2->getCantidad() << endl;

    //Agrego alumnos especiales
    curso->addAlumno(alespe1);
    curso->addAlumno(alespe2);

    cout << "contidads : "<< curso->getCantidad() << endl;
    //Punto 3
    cout << "################Listado notas (Sobrecarga <<) ##################" << endl;
    for(int i=0;i<curso->getCantidad();i++){
        gPtr = (curso->getAlumno(i));
        cout <<  *(gPtr) << endl;
    };
    cout << "################ Listado Ordenado ##################" << endl;
    curso->ordenar('A');
    for(int i=0;i<curso->getCantidad();i++){
        gPtr = (curso->getAlumno(i));
        cout <<  *(gPtr) << endl;
    };
    cout << "=========================================" << endl;
    curso->ordenar('D');
    for(int i=0;i<curso->getCantidad();i++){
        gPtr = (curso->getAlumno(i));
        cout <<  *(gPtr) << endl;
    };
    cout << "################ Buscar ##################" << endl;
    gPtr = curso->buscarNombre("pepa");
    cout << *gPtr << endl;
    cout << "################ Grabar TXT ##################" << endl;
    curso->grabarTxt();
    cout << "################ Grabar OBJ TXT ##################" << endl;
    curso->grabarTxtObj();
    cout << "################ Leer OBJ TXT ##################" << endl;
    curso->limpiar();
    cout << "Cantidad luego de limpiar: "<< curso->getCantidad() << endl;
    curso->leerTxtObj();
    curso->ordenar('A');
    cout << "Cantidad luego de leer: "<< curso->getCantidad() << endl;
    for(int i=0;i<curso->getCantidad();i++){
        gPtr = (curso->getAlumno(i));
        cout <<  *(gPtr) << endl;
    };

    return 0;
}
