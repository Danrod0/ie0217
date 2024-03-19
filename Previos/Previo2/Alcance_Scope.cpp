#include <iostream> // Libreria
using namespace std; // Para poder llamar a todo lo que incluye std

void test()
{
    
    // var es una variable estática que conserva su valor entre llamadas
    static int var = 0;
    ++var; // Incrementa var en 1
    
    cout << var << endl; // Imprime el valor de var seguido de un salto de línea
}

int main()
{

    test(); // Llama a la función test()
    test(); // Llama a la función test()

    return 0;
}