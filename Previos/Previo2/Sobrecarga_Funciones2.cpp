#include <iostream>  // Libreria
using namespace std; // Para poder llamar a todo lo que incluye std

// Funcion para dos parametros, un entero y un double
void display(int var1, double var2) {
    cout << "Integer number: " << var1;
    cout << " and double number: " << var2 << endl;
}

// Funcion para un parametro tipo doble
void display (double var) {
    cout << "Double number: " << var << endl;
}

// Funcion para un parametro tipo entero
void display(int var) {
    cout << "Integer number: " << var << endl;
}

int main() {
    int a = 5;
    double b = 5.5;
    
    // Llama a la función display con un solo parámetro de tipo entero
    display(a);
    
    // Llama a la función display con un solo parámetro de tipo doble
    display (b);
    
    // Llama a la función display con dos parámetros: un entero y un doble 
    display (a, b);
    
    return 0;
}