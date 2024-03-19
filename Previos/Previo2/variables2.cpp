#include <iostream> // Libreria
using namespace std; // Para poder llamar a todo lo que incluye std

// Crea una variable global
int g;

int main() {
    // Crea variables locales
    int a, b;
    
    // Inicializa las variables
    a =10;
    b = 20;
    g = a + b;
    
    cout << g; // Imprime en consola

    return 0;
}