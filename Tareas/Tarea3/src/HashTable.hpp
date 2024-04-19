#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>
#include <list>
#include <string>
#include "Contacto.hpp"

const int TABLE_SIZE = 50;


/**
 * @brief Crea la clase Hashtable
 * 
 * Se crea la clase tipo HashTable
 * junto con la firma de sus funciones
 */
class HashTable {
private:
    std::vector<std::list<Contacto*>> tabla;

    // Funcion hash para obtener el indice en la tabla
    int hashFunc(const std::string& clave) const;

public:
    HashTable();
    ~HashTable(); // Destructor para liberar la memoria cloud
    void agregarContacto(const std::string& nombre, const std::string& telefono);
    void eliminarContacto(const std::string& nombre);
    void imprimir() const;
    std::vector<Contacto*> obtenerContactosCelular() const;
};

#endif // HASHTABLE_HPP