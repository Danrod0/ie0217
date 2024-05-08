#include "biblioteca.hpp"

int main() {
    Biblioteca biblioteca; // Creamos un objeto de la clase Biblioteca

    // Agregamos algunos libros al catalogo utilizando el metodo agregarLibro
    biblioteca.agregarLibro ("El Gran Gatsby", "F. Scott Fitzgerald"); 
    biblioteca.agregarLibro("1984", "George Orwell");

    // Mostramos el catalogo de la biblioteca utilizando el metodo mostrarCatalogo
    biblioteca.mostrarCatalogo();
    
    return 0;
}