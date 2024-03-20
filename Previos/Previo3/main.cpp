#include <iostream> // Libreria
#include "sum.hpp" // Incluye el archivo de cabecera creado
using namespace std; // Permite usar los elementos de std

int main() {
    int num1 = 5;
    int num2 = 3;
    int result = sum (num1, num2); // Llama a la funcion sum
    
    cout << "El resultado de " << num1 << "+" << num2 << " es igual a " << result << endl; // Imprime en consola
    
    return 0;
}
