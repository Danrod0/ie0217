#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>

class Libro {
public:
    // Constructor de la clase Libro
    Libro(const std::string& titulo, const std::string& autor); 

    // Metodo para mostrar la informacion del libro
    void mostrarInfo() const;
    
private:
    // Atributos privados de la clase libro
    std::string titulo; 
    std::string autor;
};

#endif