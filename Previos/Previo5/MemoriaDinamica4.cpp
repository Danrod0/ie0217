#include <iostream> 
#include <cstdlib> 
using namespace std;

int main() {
    // Asigna memoria de tamano int a un puntero int utilizando malloc
    // malloc asigna un bloque de memoria en el heap
    int* ptr = (int*) malloc(sizeof(int));

    // Asigna el valor 5 a la memoria asignada
    *ptr = 5;

    // Imprime el valor almacenado en la memoria
    cout << *ptr;

    // Libera la memoria asignada con malloc
    free(ptr);
    
    return 0;
}