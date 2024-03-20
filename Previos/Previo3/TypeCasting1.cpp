// Working of implicit type-conversion

#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

int main() {
    // Asigna un valor entero a num_int
    int num_int = 9;
    
    // Declara una variable de tipo double
    double num_double;
    
    // Conversión implícita: asigna el valor entero a una variable double
    num_double = num_int;
    
    cout << "num_int = " << num_int << endl; // Imprime en consola
    cout << "num_double = " << num_double << endl;
    
    return 0;
}
