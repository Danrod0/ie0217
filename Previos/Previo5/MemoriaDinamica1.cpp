#include <iostream> 
using namespace std;

int main() {

    // Declara un puntero a entero 
    int* pointInt;

    // Declara un puntero a flotante 
    float* pointFloat;

    // Asigna memoria dinámicamente 
    pointInt = new int; 
    pointFloat = new float;

    // Asigna un valor a la memoria 
    *pointInt = 45;
    *pointFloat = 45.45f;

    // Imprime el valor del entero y del flotante 
    cout << *pointInt << endl; 
    cout << *pointFloat << endl;

    // Libera la memoria asignada
    delete pointInt;
    delete pointFloat;
    
    return 0;
}