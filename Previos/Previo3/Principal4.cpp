// C++ Program to display address of each element of an array 
#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std
int main() {
    int var = 2050; // Se declara a una variable inocente
    int* ptr_var; // Se crea un puntero de case sting

    ptr_var = &var; "Se asigna la direccion al puntero"
    
    cout << "var: " << var << ", ptr_var: " << ptr_var << endl; // Imprime en consola
    
    int** ptr_ptr_var;
    ptr_ptr_var = &ptr_var;
    cout << "ptr_ptr_var: " << ptr_ptr_var << endl;

    cout << "&ptr_var: " << &ptr_var << endl;
    
    return 0;
}