#include <iostream> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

// Declaración de la función add()
int add(int a, int b) { 
    return (a + b); // Devuelve la suma
}

int main() {
    
    int sum;
    
    // Llamada a la función add() y guarda el valor devuelto en sum
    sum = add(100, 78);
    
    cout << "100 + 78 = " << sum << endl;
    
    return 0;
}