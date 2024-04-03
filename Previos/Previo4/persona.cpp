#include "persona.hpp" // Incluye el archivo de encabezado persona.hpp

using namespace std;

// Se define el constructor de la clase Persona
Persona::Persona(string nombre, int edad) { 
    // Inicializa los atributos nombre y edad con los valores proporcionados
    this->nombre = nombre;
    this->edad = edad;
}

// Método para obtener el nombre de la persona
string Persona::getNombre() {
    return nombre; // Devuelve el nombre almacenado en el atributo nombre
}

// Método para obtener la edad de la persona
int Persona::getEdad() { 
    return edad; // Devuelve la edad almacenada en el atributo edad
}

// Método para establecer la edad de la persona
void Persona::setEdad(int edad) {
    this->edad = edad; // Actualiza la edad con el valor proporcionado
}