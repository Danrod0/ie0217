#include <iostream> 
#include <cstdlib>
using namespace std;

int main() {
    float *ptr, *new_ptr;

    // Asigna memoria para 5 floats
    ptr = (float*) malloc(5 * sizeof(float)); 
    if (ptr == NULL) {
        cout << "Memory Allocation Failed"; 
        exit(1);
    }
    
    /* Inicializa el bloque de memoria */ 
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 1.5;
    }
    
    /* Realoca memoria */
    new_ptr = (float*) realloc(ptr, 10 * sizeof(float)); 
    if (new_ptr == NULL) {
        cout << "Memory Re-allocation Failed"; 
        exit(1);
    }
    
    /* Inicializa el bloque de memoria realloc */ 
    for (int i = 5; i < 10; i++) {
        new_ptr[i] = i * 2.5;
    }

    // Imprime los valores
    cout << "Printing Values" << endl;
    for (int i = 0; i < 10; i++){
        cout << new_ptr[i] << endl;
    }

    // Libera la memoria asignada
    free(new_ptr);

    return 0;
}