#include <iostream> 
#include "persona.hpp" // Se incluye el archivo de encabezado persona.hpp, que contiene la declaración de la clase Persona

using namespace std;

int main() {
    // Crea un objeto de la clase Persona llamado p con nombre Juan y edad 25
    Persona p("Juan", 25);

    // Imprime el nombre y la edad del objeto p usando las funciones miembro getNombre() y getEdad()
    cout << "Nombre: " << p.getNombre() << endl; 
    cout << "Edad: " << p.getEdad() << endl;

    // Cambia la edad del objeto p a 26 usando la función miembro setEdad()
    p.setEdad(26);

    // Imprime la nueva edad del objeto p usando la función miembro getEdad()
    cout << "Nueva edad: " << p.getEdad() << endl; 
    return 0;
}