#include <iostream> 
#include "estudiante.hpp" 

// Definicion del constructor de la clase Estudiante
Estudiante::Estudiante(
    const std::string& nombre, int edad
) : nombre (nombre), edad (edad) {}

// Definicion del metodo mostrarDatos() de la clase Estudiante
void Estudiante::mostrarDatos() {
    std::cout << "Nombre: " << nombre;
    std::cout << ", Edad: " << edad << std::endl;
}
