#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

enum seasons {spring = 34, summer = 4, autumn = 9, winter = 32}; // Enumera las temporadas del anno

int main() {
    seasons s; // Crea una variable tipo seassons
    
    s = summer; // Le asigna un valor a la variable
    cout << "Summer = " << s << endl; // Imprime en consola
    
    return 0;
}