#include <iostream>
#include <array>
#include <string>
#include <fstream>   // leer archivos
#include <ctime>     // obtener el año actual
#include <iomanip>   // setw, setprecision
using namespace std;

// Un estudiante agrupa tres datos
struct Estudiante {
    string nombre;
    int anioNacimiento;
    double gpa;
};

int main() {
    // Solo 2 inicializados; los otros 8 quedan vacios (""; 0; 0.0)
    array<Estudiante, 10> estudiantes = {{
        {"Juan", 2000, 3.4},
        {"Maria", 2005, 2.8}
    }};

    // 1. Tercer y cuarto elemento (indices 2 y 3) desde el teclado
    for (int i = 2; i < 4; i++) {
        cout << "Estudiante " << i + 1 << endl;
        cout << "  Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "  Anio de nacimiento: ";
        cin >> estudiantes[i].anioNacimiento;
        cout << "  Promedio (GPA): ";
        cin >> estudiantes[i].gpa;
    }

    // 2. Quinto y sexto elemento (indices 4 y 5) desde arrays basicos
    string nombres[3] = {"Gaby", "Patty", "Diana"};
    int nacimientos[3] = {2002, 2004, 2006};
    double gpas[3] = {3.8, 3.0, 2.9};

    for (int i = 0; i < 2; i++) {
        estudiantes[4 + i] = Estudiante{nombres[i], nacimientos[i], gpas[i]};
    }

    // 3. Los restantes (indices 6 a 9) desde datos.txt
    ifstream archivo("datos.txt");
    if (!archivo) {
        cerr << "No se pudo abrir datos.txt" << endl;
        return 1;
    }
    string nombre;
    int anio;
    double gpa;
    int pos = 6;
    while (pos < 10 && archivo >> nombre >> anio >> gpa) {
        estudiantes[pos] = Estudiante{nombre, anio, gpa};
        pos++;
    }
    archivo.close();

    // 4. Imprimir todo con edad y beca
    time_t ahora = time(nullptr);
    int anioActual = localtime(&ahora)->tm_year + 1900;

    cout << "\n" << left << setw(12) << "Nombre" << setw(8) << "Edad"
         << setw(8) << "GPA" << "Beca" << endl;
    cout << string(36, '-') << endl;

    for (const Estudiante& e : estudiantes) {
        int edad = anioActual - e.anioNacimiento;
        bool beca = e.gpa >= 3.5;
        cout << left << setw(12) << e.nombre
             << setw(8) << edad
             << setw(8) << fixed << setprecision(1) << e.gpa
             << (beca ? "Si" : "No") << endl;
    }

    return 0;
}