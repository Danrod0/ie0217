#include <iostream> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

int main() {

    // Crea un arreglo de numeros
    int num_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Bucle for basado en rangos
    for (int n : num_array) {
        cout << n << " ";
    }
    
    return 0;
}