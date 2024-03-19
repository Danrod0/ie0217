// C++ Program to print numbers from 1 to 5

#include <iostream> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

int main() { 
    int i = 1;
    
    // Bucle while que se ejecuta mientras 'i' sea menor o igual a 5
    while (i <= 5) {
        cout << i << " "; // Imprime el valor de 'i'
        ++i;
    }
    
    return 0;
}