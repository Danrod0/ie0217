#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

int main()
{
    // Se crean variables
    int var1 = 3;
    int var2 = 24;
    int var3 = 17;
    
    // Se imprime la direccion de memoria de var1
    cout << "Address of var1: " << &var1 << endl;
    
    // Se imprime la direccion de memoria de var2
    cout << "Address of var2: " << &var2 << endl;
    
    // Se imprime la direccion de memoria de var3
    cout << "Address of var3: " << &var3 << endl;
}