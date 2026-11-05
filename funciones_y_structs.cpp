// funciones_y_structs.cpp
// Compilar: g++ -std=c++17 -Wall funciones_y_structs.cpp -o demo2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- STRUCT (registro) ----------
struct Estudiante {
    string nombre;
    int edad;
    vector<double> notas;
};

// ---------- FUNCIONES ----------

// Por valor: recibe una copia, no cambia el original
int cuadrado(int x) {
    return x * x;
}

// Por referencia: SI cambia el original
void subirEdad(int& edad) {
    edad++;
}

// Recibe un struct por referencia constante (sin copiar, sin modificar)
double promedio(const Estudiante& e) {
    if (e.notas.empty()) return 0;
    double suma = 0;
    for (double n : e.notas) suma += n;
    return suma / e.notas.size();
}

void imprimir(const Estudiante& e) {
    cout << e.nombre << " (" << e.edad << " anios) - promedio: "
         << promedio(e) << endl;
}

// Recibe el struct por referencia (sin const) para modificarlo
void agregarNota(Estudiante& e, double nota) {
    e.notas.push_back(nota);
}

// Devuelve un struct nuevo
Estudiante crearEstudiante(string nombre, int edad) {
    Estudiante e;
    e.nombre = nombre;
    e.edad = edad;
    return e;
}

// Recorre un vector de structs y devuelve la posicion del mejor promedio
int mejorEstudiante(const vector<Estudiante>& lista) {
    int mejor = 0;
    for (size_t i = 1; i < lista.size(); i++) {
        if (promedio(lista[i]) > promedio(lista[mejor])) mejor = i;
    }
    return mejor;
}

// ---------- MAIN ----------
int main() {
    // 1. Funciones: valor vs referencia
    int n = 4;
    cout << "cuadrado(4) = " << cuadrado(n) << endl;   // 16
    int edad = 20;
    subirEdad(edad);
    cout << "edad despues de subirEdad: " << edad << endl;   // 21

    // 2. Un struct
    Estudiante ana = crearEstudiante("Ana", 19);
    agregarNota(ana, 4.0);
    agregarNota(ana, 5.0);
    agregarNota(ana, 3.0);
    imprimir(ana);                                      // promedio 4

    // 3. Vector de structs
    vector<Estudiante> curso;
    curso.push_back(ana);

    Estudiante luis = crearEstudiante("Luis", 21);
    agregarNota(luis, 5.0);
    agregarNota(luis, 4.5);
    curso.push_back(luis);

    Estudiante sofia = {"Sofia", 20, {3.5, 4.0, 3.0}};  // inicializacion directa
    curso.push_back(sofia);

    cout << "\nCurso:" << endl;
    for (const Estudiante& e : curso) imprimir(e);

    int m = mejorEstudiante(curso);
    cout << "\nMejor promedio: " << curso[m].nombre << endl;

    return 0;
}
