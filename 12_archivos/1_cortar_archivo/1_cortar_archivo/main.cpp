#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

void cortar(char* nombre, int cant);
int contar(char* nombre);

int main()
{
    cortar("numeros.txt", 5);
    return 0;
}

void cortar(char* nombre, int cant){
    ifstream origen;
    int count = contar(nombre);
    cout << "Lineas: " << count << endl;
    if (count >= cant) {
        int n = count / cant;
        cout << "Lineas por archivo: " << n << endl;
        origen.open(nombre);
        if(origen.is_open()){
            int nroArchivo = 0;
            ofstream destino;
            string line;
            int currentLine = 0;
            while (getline(origen, line)){
                if ((currentLine % n) == 0) {
                    if (nroArchivo > 0)
                        destino.close();
                    std::string sstm = nombre;
                    sstm +=std::to_string(nroArchivo);


                    // Mostrar el resultado
                    std::cout << sstm <<  std::endl;

                    destino.open(sstm.c_str());
                    nroArchivo++;
                }
                destino << line << endl;
                currentLine++;
            }
            if (nroArchivo > 0)
                destino.close();
            cout << "Se grabaron " << nroArchivo  << " archivos" << endl;
        } else {
            cout << "No se pudo leer el archivo" << endl;
        }
    } else {
        cout << "Error: el archivo tiene " << count
             << " lineas, no se puede dividir en " << cant << " partes." << endl;
    }
}

/*
void cortar(char* nombre, int cant){
    ifstream origen;
    int count = contar(nombre);
    cout << "Lineas: " << count << endl;
    if (count >= cant) {
        int n = count / cant;
        cout << "Lineas por archivo: " << n << endl;
        origen.open(nombre);
        if(origen.is_open()){
            int nroArchivo = 0;
            ofstream destino;
            string line;
            int currentLine = 0;
            while (getline(origen, line)){
                if ((currentLine % n) == 0) {
                    if (nroArchivo > 0)
                        destino.close();
                    ostringstream sstm;
                    sstm << nombre << nroArchivo;
                    string newName = sstm.str();
                    cout << newName << endl;
                    destino.open(newName.c_str());
                    nroArchivo++;
                }
                destino << line << endl;
                currentLine++;
            }
            if (nroArchivo > 0)
                destino.close();
            cout << "Se grabaron " << nroArchivo  << " archivos" << endl;
        } else {
            cout << "No se pudo leer el archivo" << endl;
        }
    } else {
        cout << "Error: el archivo tiene " << count
             << " lineas, no se puede dividir en " << cant << " partes." << endl;
    }
}
*/
int contar(char* nombre){
    ifstream origen;
    origen.open(nombre);
    int count = 0;
    if(origen.is_open()){
        string line;
        while (getline(origen, line)){
            count++;
        }
        origen.close();
    }
    return count;
}
