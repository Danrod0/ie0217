#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std
int main() {
    int var = 5; // Crea una variable
    int* pointVar; // Declara un puntero a un entero
    
    // Guarda la direccion de var en el puntero
    pointVar = &var;
    
    // Imprime en consola var
    cout << "var = " << var << endl;
    
    // Imprime el valor del puntero en consola
    cout << "*pointVar = " << *pointVar << endl;
    
    cout << "Changing value of var to 7:" << endl;
    
    // Cambia el valor a 7
    var = 7;
    
    // Imprime en consola var
    cout << "var = " << var << endl;
    
    // Imprime el valor del puntero en consola
    cout << "*pointVar = " << *pointVar << endl;
    
    cout << "Changing value of *pointVar to 16:" << endl;
    
    // Cambia el valor a 16
    *pointVar = 16;
    
    // Imprime en consola var
    cout << "var = " << var << endl;
    
    // Imprime el valor del puntero en consola
    cout << "*pointVar = " << *pointVar << endl;
    return 0;
}