// vectores_y_matrices.cpp  (version resumida)
// Compilar: g++ -std=c++17 -Wall vectores_y_matrices.cpp -o demo

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;

using Vector = vector<double>;
using Matriz = vector<vector<double>>;

// ---------- VECTORES ----------
void imprimirVector(const Vector& v) {
    cout << "[ ";
    for (double x : v) cout << x << " ";
    cout << "]" << endl;
}

Vector sumarVectores(const Vector& a, const Vector& b) {
    Vector r(a.size());
    for (size_t i = 0; i < a.size(); i++) r[i] = a[i] + b[i];
    return r;
}

double productoPunto(const Vector& a, const Vector& b) {
    double suma = 0;
    for (size_t i = 0; i < a.size(); i++) suma += a[i] * b[i];
    return suma;
}

// ---------- MATRICES ----------
Matriz crearMatriz(int filas, int cols) {
    return Matriz(filas, Vector(cols, 0.0));
}

void imprimirMatriz(const Matriz& m) {
    for (const Vector& fila : m) {
        for (double x : fila) cout << setw(5) << x;
        cout << endl;
    }
}

Matriz sumarMatrices(const Matriz& A, const Matriz& B) {
    Matriz C = crearMatriz(A.size(), A[0].size());
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < A[0].size(); j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matriz transpuesta(const Matriz& A) {
    Matriz T = crearMatriz(A[0].size(), A.size());   // dimensiones invertidas
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < A[0].size(); j++)
            T[j][i] = A[i][j];
    return T;
}

Matriz multiplicar(const Matriz& A, const Matriz& B) {
    if (A[0].size() != B.size())
        throw invalid_argument("columnas de A != filas de B");
    Matriz C = crearMatriz(A.size(), B[0].size());
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < B[0].size(); j++)
            for (size_t k = 0; k < B.size(); k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// ---------- MAIN ----------
int main() {
    Vector u = {1, 2, 3}, w = {4, 5, 6};
    cout << "u + w = "; imprimirVector(sumarVectores(u, w));      // [5 7 9]
    cout << "u . w = " << productoPunto(u, w) << endl;            // 32

    Matriz A = {{1, 2, 3}, {4, 5, 6}};
    Matriz B = {{7, 8, 9}, {1, 0, 2}};
    cout << "\nA + B:\n";  imprimirMatriz(sumarMatrices(A, B));
    cout << "\nA^T:\n";    imprimirMatriz(transpuesta(A));
    cout << "\nA * A^T:\n"; imprimirMatriz(multiplicar(A, transpuesta(A)));

    try {
        multiplicar(A, A);                                        // 2x3 por 2x3
    } catch (const invalid_argument& e) {
        cout << "\nError: " << e.what() << endl;
    }
    return 0;
}
