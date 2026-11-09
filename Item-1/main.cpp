#include <iostream>
#include <array>
#include <algorithm>   // sort
using namespace std;

// Imprime todos los elementos del array
void imprimir(const array<int, 20>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // 5 entre 20 y 50 (inicio) | 10 mayores a 50 (medio) | 5 menores a 20 (final)
    array<int, 20> datos = {
        45, 23, 49, 27, 31,                                  // inicio
        61, 53, 87, 55, 99, 57, 71, 63, 51, 75,              // medio
        19, 3, 15, 7, 11                                     // final
    };

    // 1. Imprimir todos
    cout << "1. Todos los elementos:" << endl;
    imprimir(datos);

    // 2. Solo los mayores de 20 y menores de 50
    cout << "2. Mayores de 20 y menores de 50:" << endl;
    for (int x : datos) {
        if (x > 20 && x < 50) {
            cout << x << " ";
        }
    }
    cout << endl;

    // 3. Ordenar e imprimir
    sort(datos.begin(), datos.end());
    cout << "3. Ordenados:" << endl;
    imprimir(datos);

    // 4. Indices impares menores de 10 (1, 3, 5, 7, 9)
    cout << "4. Indices impares menores de 10:" << endl;
    for (int i = 1; i < 10; i += 2) {
        cout << "datos[" << i << "] = " << datos.at(i) << endl;
    }

    return 0;
}