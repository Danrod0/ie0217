#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std
int main() {
    int var = 5; // Crea una variable
    
    // Crea un puntero a un entero
    int* pointVar;
    
    // Guarda la direccion de var
    pointVar = &var;
    
    // Imprime en consola var
    cout << "var = " << var << endl;
    
    // Imprime la direccion de var
    cout << "Address of var (&var) = " << &var << endl
        <<endl;
    
    // Imprime el valor del puntero en consola
    cout << "pointVar = " << pointVar << endl;
    
    // Imprime el contedio de la direccion a la que apunta el puntero
    cout << "Content of the address pointed to by pointVar (*pointVar) = " << *pointVar << endl;
    
    return 0;
}