#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ofstream archivo;
    archivo.open ("example.txt");
    cout << "Ingrese texto para grabar - Sale con :q" << endl;
    char * buffer = new char[500];
    // Leer línea completa, incluyendo espacios
    cin.getline(buffer, 500);
    //cin >> buffer;
    while (strcmp (buffer, ":q") != 0) {
        archivo << buffer << '\n';
        cin.getline(buffer, 500);
        //cin >> buffer;
    }
    archivo.close();
    cout << "Lectura del archivo grabado" << endl;
    string line;
    ifstream iarchivo("example.txt");
    while ( !iarchivo.eof() ) {
          getline (iarchivo,line);
          cout << line << '\n';
    }
    iarchivo.close();
}
