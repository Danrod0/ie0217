#include "Contacto.hpp"

/**
 * @brief Obtiene nombre
 * 
 * Obtiene el nombre del contacto a guardar
 * 
 */
// Devuelve el nombre del contacto
std::string Contacto::getNombre() const {
    return nombre;
}

/**
 * @brief Obtiene el telefono
 * 
 * Obtiene el telefono del contacto a guardar
 * 
 */
// Devuelve el numero de telefono del contacto
std::string Contacto::getTelefono() const {
    return telefono;
}