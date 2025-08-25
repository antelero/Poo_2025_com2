#include <iostream>
#include <cstring>

#include <vector>

#include <list>

#include <map>


using namespace std;

int main()
{
    vector<int> vec;
    cout << " " << vec.size() << " " << vec.capacity()<< " " << endl;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << " " << vec.size() << " " << vec.capacity()<< " " << endl;
    //vector<int>::iterator it;
    //Impresion recorriendo como arreglo
    for (int i=0; i<vec.size(); i++)
        cout << vec[i]<< " ";
    cout << endl;
    //De inicio a fin
    for (auto it = vec.begin();it != vec.end(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the
    };
    cout << endl;
    //De inicio a fin
    for (auto it = vec.rbegin();it != vec.rend(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the
    };
    cout << endl;

    list<int> lis;
    lis.push_back(2);
    lis.push_back(3);
    lis.push_back(4);
    lis.push_back(5);
    lis.push_front(1);
    //De inicio a fin
    for (auto it = lis.begin();it != lis.end(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the
    };
    cout << endl;
    //De inicio a fin
    for (auto it = lis.rbegin();it != lis.rend(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the
    };
    cout << endl;
    std::cout << "Frente "<< lis.front()<< " "; // T &
    std::cout << "Fondo "<< lis.back() << " ";// T &

    cout << endl;

    map<string,int> calif;
    calif["Fundamentos"]=9;
    calif["POO"]=7;
    calif["Matemática Básica"]=8;
    calif["Fisica I"]=7;
    calif["Álgebra"]=7;
    calif["Ingeniería de Software"]=7;
    string materia;
    getline(cin,materia);
    if (calif.find(materia)==calif.end())
        cout<<"No se registra nota para esa materia. " << materia<< endl;
    else
        cout<<"La nota " << materia << " es: "<<calif[materia]<< endl;

    cout<<"Ejemplo de texto y mapa "<< endl;
    char frase[] = "hola mundo hola mundo mundo ejemplo con mapa";
    std::map<std::string, int> contador;
    char* palabra = std::strtok(frase, " "); //strtok divide la cadena usando el espacio como delimitador
    while (palabra != nullptr) {
        std::cout << palabra << "| "  ;
        contador[palabra]++;
        palabra = std::strtok(nullptr, " ");
    }
    cout << endl;
    // Mostrar resultados
    for (const auto& par : contador) {
        std::cout << par.first << ": " << par.second << std::endl;
    }

    return 0;
}
