#include <iostream> 
#include "libro.hpp"

// Constructor de la clase Libro
Libro::Libro(
    const std::string& titulo, const std::string& autor
) : titulo(titulo), autor(autor) {} // Inicializamos los miembros titulo y autor con los parametros pasados

// Metodo para mostrar la informacion del libro
void Libro::mostrarInfo() const {
    std::cout << "Titulo: " << titulo << ", Autor: " << autor << std::endl;
}
