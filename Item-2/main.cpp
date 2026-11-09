#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // Sudamerica tiene 12 paises, pero solo inicializamos 10.
    // Las posiciones 10 y 11 quedan como strings vacios "".
    array<string, 12> paises = {
        "Argentina", "Bolivia", "Brasil", "Chile", "Colombia",
        "Ecuador", "Guyana", "Paraguay", "Peru", "Surinam"
    };

    // 1. Insertar los restantes con at() y con []
    paises.at(10) = "Uruguay";   // at() verifica que el indice sea valido
    paises[11] = "Venezuela";    // [] no verifica, es mas rapido

    // 2. Solo los que inician con C o P
    cout << "Paises que inician con C o P:" << endl;
    for (const string& pais : paises) {
        if (pais[0] == 'C' || pais[0] == 'P') {
            cout << " - " << pais << endl;
        }
    }

    // 3. Primer y ultimo elemento
    cout << "\nPrimero: " << paises.front() << endl;
    cout << "Ultimo: " << paises.back() << endl;

    // 4. Ordenar e imprimir todos
    sort(paises.begin(), paises.end());
    cout << "\nPaises ordenados alfabeticamente:" << endl;
    for (const string& pais : paises) {
        cout << " - " << pais << endl;
    }

    return 0;
}