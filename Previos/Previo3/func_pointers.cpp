#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

// Se crea la funcion para intercambiar valores con punteros
void swap (int* n1, int* n2) {
    int temp; // Variable temporal
    temp=*n1;
    *n1 =*n2;
    *n2 = temp;
}

int main() {
    
    // Se crean las variables
    int a = 1, b = 2;
    
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    // Muestra las direcciones de memoria de las variables 
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    
    swap(&a, &b);
    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = "<< b << endl;
    return 0;
}