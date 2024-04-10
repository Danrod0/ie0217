#include <cstdlib> 
#include <iostream> 
using namespace std;

int main() { 
    int *ptr;

    // Asigna memoria para 5 enteros
    ptr = (int *)calloc(5, sizeof(int));

    // Verifica si la asignacion de memoria fue exitosa
    if (!ptr) {
        cout << "Memory Allocation Failed"; 
        exit(1);
    }  

    // Inicializa los valores del array  
    cout << "Initializing values..." << endl
        << endl;
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2 + 1;
    }

    // Imprime los valores inicializados
    cout << "Initialized values" << endl;
    for (int i = 0; i < 5; i++) {
        /* ptr[i] y *(ptr+i) se pueden usar de forma intercambiable */ 
        cout << *(ptr + i) << endl;
    }

    // Libera la memoria asignada
    free(ptr);
    return 0;
}