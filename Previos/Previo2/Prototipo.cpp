// using function definition after main() function 
// function prototype is declared before main()

#include <iostream> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

// Declaración del prototipo de la función, o sea la funcion antes del main, sin completarla.
int add(int, int);

int main() { 
    int sum;
    
    // Llamada a la función add() y guarda el valor devuelto en sum
    sum = add(100, 78);
    
    cout << "100 + 78 = " << sum << endl;
    
    return 0;
}

// Definición de la función add()
int add(int a, int b) {
    return (a + b);
}