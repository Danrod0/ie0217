#include <iostream> 
#include "biblioteca.hpp"

void Biblioteca::agregarLibro( 
    const std::string& titulo, 
    const std::string& autor
) {
    // Agrega un nuevo libro al final del catalogo
    catalogo.emplace_back(titulo, autor);
}

void Biblioteca::mostrarCatalogo() { 
    // Itera sobre el catalogo y muestra la informacion de cada libro
    for (const auto& libro : catalogo) { 
        libro.mostrarInfo(); // Llama al metodo mostrarInfo() de cada libro
    }
}