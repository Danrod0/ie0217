#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

enum suit { // Enumera los simbolos de una baraja de naipes
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card; // Declara una variable tipo suit

int main()
{
    card = club; // Le da un valor a la variable
    cout << "Size of enum variable " << sizeof(card) << " bytes."; // Imprime el tamano de la variable
    return 0;
}