// arreglos.cpp - arreglos unidimensionales y bidimensionales
// Compilar: g++ -std=c++17 -Wall arreglos.cpp -o demo3

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5;      // tamano del arreglo 1D
const int F = 2;      // filas de la matriz
const int C = 3;      // columnas de la matriz

// ---------- 1D ----------
// Un arreglo se pasa SIEMPRE por referencia (no se copia); el tamano va aparte
void imprimir1D(const int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int suma(const int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}

int posicionMayor(const int a[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[pos]) pos = i;
    return pos;
}

void invertir(int a[], int n) {           // sin const: modifica el original
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

// ---------- 2D ----------
// En 2D hay que indicar el numero de columnas en el parametro
void imprimir2D(const int m[][C], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < C; j++) cout << setw(4) << m[i][j];
        cout << endl;
    }
}

int sumaFila(const int m[][C], int fila) {
    int s = 0;
    for (int j = 0; j < C; j++) s += m[fila][j];
    return s;
}

void transpuesta(const int m[][C], int t[][F]) {   // t es de C filas x F columnas
    for (int i = 0; i < F; i++)
        for (int j = 0; j < C; j++)
            t[j][i] = m[i][j];
}

int main() {
    // ----- 1D -----
    int a[N] = {4, 9, 2, 7, 5};
    cout << "a = ";            imprimir1D(a, N);
    cout << "suma = "          << suma(a, N) << endl;                  // 27
    int p = posicionMayor(a, N);
    cout << "mayor = " << a[p] << " en la posicion " << p << endl;    // 9, pos 1
    invertir(a, N);
    cout << "invertido = ";    imprimir1D(a, N);                      // 5 7 2 9 4

    // ----- 2D -----
    int m[F][C] = {{1, 2, 3},
                   {4, 5, 6}};
    cout << "\nm:\n";           imprimir2D(m, F);
    for (int i = 0; i < F; i++)
        cout << "suma de la fila " << i << " = " << sumaFila(m, i) << endl;  // 6 y 15

    int t[C][F];
    transpuesta(m, t);
    cout << "\ntranspuesta:\n";
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < F; j++) cout << setw(4) << t[i][j];
        cout << endl;
    }
    return 0;
}
