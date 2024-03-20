// Factorial of n = 1*2*3*...*n

#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

int factorial (int); // Prototipo de la funcion factorial

int main() {
    int n, result; // Crea las variables necesarias
    
    cout << "Enter a non-negative number: "; // Pide al usuario un numero
    cin >> n; // Guarda el numero en n
    
    result = factorial(n); // LLama a la funcion factorial
    cout << "Factorial of " << n << " = " << result; // Imprime el resultado
    return 0;
}

int factorial (int n) { // Define la funcion factorial
    if (n > 1) {
        return n * factorial(n - 1); // Esto lo hace recursiva, al llamar a la funcion dentro de la funcion
        } else {
            return 1;
        }
}