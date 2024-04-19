#ifndef CONTACTO_HPP
#define CONTACTO_HPP

#include <string>

/**
 * @brief Estructura para los contactos
 * 
 * Se crea la estructura para almacenar
 * los contactos, junto con las declaraciones
 * de las funciones.
 */

// Estructura de datos para almacenar un contacto
struct Contacto {
    std::string nombre;
    std::string telefono;
    Contacto* siguiente; // Puntero al siguiente contacto en la lista enlazada

    // Constructor
    Contacto(const std::string& nombre, const std::string& telefono)
        : nombre(nombre), telefono(telefono), siguiente(nullptr) {}

    // Declaraciones de funciones
    std::string getNombre() const;
    std::string getTelefono() const;
};

#endif // CONTACTO_HPP