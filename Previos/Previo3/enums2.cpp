#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; // Enumera los dias de la semana

int main()
{
    week today; // Crea una variable tipo week
    today = Wednesday; // Le da un valor a la variable
    cout << "Day" << today+1; // Imprime el dia en consola
    return 0;
}