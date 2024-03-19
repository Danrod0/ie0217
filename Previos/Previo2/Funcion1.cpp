#include <iostream>  // Libreria
using namespace std; // Para poder llamar a todo lo que incluye std

// Función para mostrar un número entero y un número de punto flotante
void displayNum(int n1, float n2) {
    cout << "The int number is " << n1; 
    cout << "The double number is " << n2;
}

int main() {
    
    int num1 = 5;
    double num2 = 5.5;
    
    // Llama a la función displayNum pasando num1 y num2 como argumentos
    displayNum(num1, num2);
    
    return 0;
}