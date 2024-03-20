#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

#define BOOK_ID_MAX 10 // Define el valor en 10

enum { // crea un enum para enumerar las casas con valores del 0 al 3
    CASA_BADILLA,
    CASA_ALVARADO,
    CASA_SOLANO,
    CASA_MAX
} casas_t; // Define el tipo de enumeracion

int main() {
    
    /* El valor de BOOK_ID_MAX es PRE-procesado. */
    cout << "El valor de Book ID Max es: " << BOOK_ID_MAX << endl; // Imprime en consola
    
    cout << "La cantidad de casas en el condiminio es: " << CASA_MAX << endl;
    
    return 0;
}