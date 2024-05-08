#ifndef ESTUDIANTE_HPP 
#define ESTUDIANTE_HPP

#include <string>

// Declaracion de la clase Estudiante
class Estudiante {
public:

    // Constructor de la clase Estudiante
    Estudiante (const std::string& nombre, int edad); 

    // Metodo para mostrar los datos del estudiante
    void mostrarDatos();

private:
    // Atributos privados de la clase estudiante
    std::string nombre;
    int edad;
    int edad2;
};

#endif