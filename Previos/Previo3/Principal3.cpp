#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

int main() {
    float arreglo[3]; // Crea un arreglo de 3 elementos tipo flotante
    
    // Crea un puntero de punto flotante
    float *puntero;
    
    cout << "Displaying address using arrays: " << endl; // Imprime en la consola
    
    // Usa el ciclo for para imprimir las direcciones de memoria de los elementos del array
    for (int i = 0; i < 3; ++i) {
        cout << "&arreglo[" << i << "] = " << &arreglo[i] << endl;
    }
    
    // Asigna la direccion de memoria del primer elemento al puntero
    puntero = arreglo;
    
    cout << "\nDisplaying address using pointers: " << endl;
    
    // Usa el ciclo for para imprimir las direcciones de memoria de los elementos del array
    // utilizando la notacion de punteros
    for (int i = 0; i < 3; ++i) {
        cout << "puntero + " << i << " = " << puntero + i << endl;
    }
    
    return 0;
}