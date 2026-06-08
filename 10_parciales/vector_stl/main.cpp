#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*
    vector<int> nros;
    cout << " " << nros.size() << " " << nros.capacity()<< " " << endl;
    nros.push_back(1);
    nros.push_back(2);
    nros.push_back(3);
    cout << " " << nros.size() << " " << nros.capacity()<< " " << endl;

    for (int i=0; i<nros.size();i++)
        cout << " " << nros[i]<< endl;


    for(auto it=nros.begin();it != nros.end();++it)
        cout << " " << *it;
    cout << endl;


    for(auto it=nros.rbegin();it != nros.rend();++it)
        cout << " " << *it;
    cout << endl;cout << endl;
    */
    vector<string> cadenas;
    cadenas.push_back("Vivir");
    cadenas.push_back("solo");
    cadenas.push_back("cuesta");
    cadenas.push_back("vida");
    cadenas.push_back("!");
    cout << " " << cadenas.size() << " " << cadenas.capacity()<< " " << endl;
    for(auto it=cadenas.begin();it != cadenas.end();++it)
        cout << " " << *it;
    cout << endl;

    for(auto it=cadenas.rbegin();it != cadenas.rend();++it)
        cout << " " << *it;
    cout << endl;

    sort(cadenas.begin(),cadenas.end());
    for(auto it=cadenas.begin();it != cadenas.end();++it)
        cout << " " << *it;
    cout << endl;

    sort(cadenas.begin(),cadenas.end());
    for(auto it=cadenas.rbegin();it != cadenas.rend();++it)
        cout << " " << *it;
    cout << endl;

    auto x = find(cadenas.begin(),cadenas.end(),"Vivir");
    if (x != cadenas.end()) {
            // Si el iterador no llegó al final, es porque lo encontró
            cout << "¡Encontrado! La palabra '" << *x << "' esta en el vector." << endl;

            // Si quieres saber la posición (índice), restas el inicio:
            int posicion = distance(cadenas.begin(), x);
            cout << "Se encuentra en la posicion (indice): " << posicion << endl;
        } else {
            cout << "La palabra no existe en el vector." << endl;
        }
    return 0;
}
