#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char,int> palabras;

    string palabraAux;
    cout << "Ingrese un texto: ";
    //cin >> palabraAux;
    getline(cin, palabraAux);

    //Trabajando directamente sobre el string
    for(int i=0;i<palabraAux.length();i++){
        palabras[palabraAux[i]]++;
    }
     cout << "El palabra tiene " << palabras.size()<< " caracteres" << endl;
    for (auto i = palabras.begin(); i != palabras.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}
