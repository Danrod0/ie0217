#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

// Definicion de la funcion para intercambiar valores
void swap(int &n1, int &n2) {
    int temp; // Variable temporal, para el intercambio
    temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    
    // Se crean las variables
    int a = 1, b = 2;
    
    cout << "Before swapping" << endl; // Imprime en la consola
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    // Llama a la funcion para intercambiar valores
    swap(a, b);
    
    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    return 0;
}