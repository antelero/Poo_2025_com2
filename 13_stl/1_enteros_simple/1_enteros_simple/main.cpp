#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
1. Realice un programa que genere 200 números enteros, los imprima y luego ordene dicha
lista sin tener en cuenta los 10 primeros, ni los últimos 50 y los vuelva a imprimir. Por
ultimo ordene de forma descendiente e imprima la lista.
*/
int main()
{
    vector<int> enteros;
    srand(time(NULL));
    cout << "Genero 200 elementos al azar"<< endl;
    for(int i = 0; i < 200; ++i){
        enteros.push_back(rand()%100);
    }
    cout << "Imprimo los elementos al azar"<< endl;
    std::random_shuffle(enteros.begin(), enteros.end());
    for(int i=0; i< enteros.size(); i++)
        cout << enteros[i] << " ";
    cout << endl;
    cout << "Ordeno los elementos "<< endl;
    sort(enteros.begin()+10,enteros.end()-50);
    cout << "Imprimo los elementos ordenados"<< endl;
    for(int i=0; i< enteros.size(); i++)
        cout << enteros[i] << " ";

    cout << endl;
    cout << "Ordeno todes los elementos descendiente"<< endl;
    sort(enteros.rbegin(),enteros.rend());
    cout << "Imprimo los elementos ordenados"<< endl;
    for(int i=0; i< enteros.size(); i++)
        cout << enteros[i] << " ";

    cout << endl;
    return 0;
}
