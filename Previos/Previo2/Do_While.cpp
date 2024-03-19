// C++ Program to print numbers from 1 to 5

#include <iostream> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

int main() { 
    int i = 1;
    
    // Ciclo do...while de 1 a 5
    do {
        cout << i << " "; // Imprime el valor de i
        ++i; // Incrementa el valor de i en 1.
    }
    while (i <= 5); // Continúa ejecutando el ciclo mientras i sea menor o igual a 5.
    
    return 0;
}