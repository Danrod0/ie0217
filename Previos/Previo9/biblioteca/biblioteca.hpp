#ifndef BIBLIOTECA_HPP 
#define BIBLIOTECA_HPP

#include <vector>
#include "libro.hpp"

class Biblioteca {
public:

    // Metodo para agregar un libro al catalogo de la biblioteca
    void agregarLibro(
        const std::string& titulo, 
        const std::string& autor
    );

    // Metodo para mostrar el catalogo de la biblioteca
    void mostrarCatalogo();

private:
    // Vector que almacenara los libros en el catalogo
    std::vector<Libro> catalogo;
};

#endif