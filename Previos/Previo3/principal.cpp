#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

#define MI_PRIMER_DEFINE 925 // Define el valor en 925

enum seasons { // Crea una enumeracion para las estaciones
    spring = 34, 
    summer = 4, 
    autumn = 9, 
    winter = 32
}

enum enumcito { // Crea un enum para enumerar cosas a partir de 40
    carro = 40, 
    casa, 
    arbol, 
    patio
};

int main() {
    seasons s; // Crea una variable tipo seasons
    s = winter; // Le da un valor
    cout << "Summer = " << s << endl; // Imprime en consola
    cout << "Define: " << MI_PRIMER_DEFINE << endl; // Imprime en consola

    cout << "Arbol: " << arbol << endl; // Imprime en consola
    
    return 0;
}
