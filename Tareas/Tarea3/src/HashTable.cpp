#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable() : tabla(TABLE_SIZE) {}

HashTable::~HashTable() {
    // Libera la memoria cloud de los contactos
    for (auto& lista : tabla) {
        for (auto contactoPtr : lista) {
            delete contactoPtr;
        }
    }
}

int HashTable::hashFunc(const std::string& clave) const {
    // Funcion de hash para generar el indice que se utilizara
    return clave.length() % TABLE_SIZE;
}

void HashTable::agregarContacto(const std::string& nombre, const std::string& telefono) {
    // Crea un nuevo contacto en la memoria cloud
    Contacto* nuevoContacto = new Contacto(nombre, telefono);

    // Calcula el indice en la tabla hash
    int indice = hashFunc(nombre);

    // Agrega el contacto a la lista enlazada asociada al indice
    tabla[indice].push_back(nuevoContacto);
}