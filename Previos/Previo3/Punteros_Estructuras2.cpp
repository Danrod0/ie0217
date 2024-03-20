#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

struct Distance { // Crea la estructura distancia
    int feet;
    float inch;
};

int main() {
    Distance *ptr, d; // Declara un puntero y una instancia tipo Distance
    
    ptr = &d; // Asigna el puntero a la direccion de d
    
    cout << "Enter feet: "; // Solicita al usuario los pies
    cin >> (*ptr).feet; // Utiliza el puntero para acceder a feet de la estructura y guardar el valor
    cout << "Enter inch: "; // Solicita al usuario las pulgadas
    cin >> (*ptr).inch; // Utiliza el puntero para acceder a inch de la estructura y guardar el valor

    cout << "Displaying information." << endl; // Imprime la informacion
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << "inches";
    
    return 0;
}