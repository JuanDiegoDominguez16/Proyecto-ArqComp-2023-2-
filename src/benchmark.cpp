#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Declaraciones
void transposeNaive(
    const vector<vector<int>>& matrix,
    vector<vector<int>>& result);

void transposeTiled(
    const vector<vector<int>>& matrix,
    vector<vector<int>>& result);

// Inicialización
void initializeMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j;
        }
    }
}

// Validación
bool validateTranspose(
    const vector<vector<int>>& original,
    const vector<vector<int>>& transpose)
{
    int n = original.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(transpose[j][i] != original[i][j]) {
                return false;
            }

        }
    }

    return true;
}

int main()
{
    int n = 1024;

    cout << "Tamano matriz: "
         << n << "x" << n
         << "\n\n";

    vector<vector<int>> matrix(
        n,
        vector<int>(n)
    );

    initializeMatrix(matrix);

    //------------------------------------
    // Algoritmo A
    //------------------------------------

    vector<vector<int>> resultA(
        n,
        vector<int>(n)
    );

    auto startA =
        high_resolution_clock::now();

    transposeNaive(matrix, resultA);

    auto endA =
        high_resolution_clock::now();

    auto timeA =
        duration_cast<nanoseconds>(
            endA - startA
        );

    bool validA =
        validateTranspose(
            matrix,
            resultA
        );

    //------------------------------------
    // Algoritmo B
    //------------------------------------

    vector<vector<int>> resultB(
        n,
        vector<int>(n)
    );

    auto startB =
        high_resolution_clock::now();

    transposeTiled(matrix, resultB);

    auto endB =
        high_resolution_clock::now();

    auto timeB =
        duration_cast<nanoseconds>(
            endB - startB
        );

    bool validB =
        validateTranspose(
            matrix,
            resultB
        );

    //------------------------------------
    // Evitar eliminación por optimización
    //------------------------------------

    volatile int sink =
        resultA[0][0] +
        resultB[0][0];

    //------------------------------------
    // Resultados
    //------------------------------------

    cout << "=== RESULTADOS ===\n\n";

    cout << "Algoritmo A (Naive)\n";
    cout << "Tiempo (ns): "
         << timeA.count()
         << "\n";
    cout << "Valido: "
         << validA
         << "\n\n";

    cout << "Algoritmo B (Tiled 2x2)\n";
    cout << "Tiempo (ns): "
         << timeB.count()
         << "\n";
    cout << "Valido: "
         << validB
         << "\n\n";

    if(timeA.count() > timeB.count())
    {
        cout << "El algoritmo B fue mas rapido.\n";
    }
    else if(timeB.count() > timeA.count())
    {
        cout << "El algoritmo A fue mas rapido.\n";
    }
    else
    {
        cout << "Ambos tuvieron el mismo tiempo.\n";
    }

    return sink;
}