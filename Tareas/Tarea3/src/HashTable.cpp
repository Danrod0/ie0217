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

void HashTable::eliminarContacto(const std::string& nombre) {
    int indice = hashFunc(nombre);
    auto& lista = tabla[indice];
    
    // Buscar el contacto en la lista
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if ((*it)->nombre == nombre) {
            std::cout << "El contacto '" << nombre << "' ha sido encontrado." << std::endl;
            std::cout << "Desea eliminarlo solo de la memoria del celular (0) o tambien de la memoria cloud (1)? ";
            int opcion;
            std::cin >> opcion;
            
            if (opcion == 0) {
                // Eliminar el contacto solo de la memoria del celular
                free(*it);
                lista.erase(it);
                std::cout << "Contacto eliminado correctamente de la memoria del celular." << std::endl;
            } else if (opcion == 1) {
                // Eliminar el contacto de ambas memorias: celular y cloud
                Contacto* contacto = *it;
                
                // Eliminar el contacto de la lista
                delete contacto;
                lista.erase(it);
                std::cout << "Contacto eliminado correctamente de las dos memorias." << std::endl;
            } else {
                std::cout << "Opcion no valida. No se realizo ninguna accion." << std::endl;
            }
            
            return;
        }
    }
    
    std::cout << "El contacto no se encontro en la lista." << std::endl;
}
