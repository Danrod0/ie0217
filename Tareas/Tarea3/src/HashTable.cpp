#include "HashTable.hpp"
#include <iostream>

/**
 * @brief Constructor
 * 
 * Inicializa la tabla hash con un tamano 
 * (TABLE_SIZE) y cada elemento de la tabla 
 * es una lista enlazada que almacena 
 * punteros a objetos Contacto.
 */
HashTable::HashTable() : tabla(TABLE_SIZE) {} // Constructor de la clase HashTable

/**
 * @brief Destructor
 * 
 * Libera la memoria asignada de manera dinamica
 * para los contactos almacenados en la tabla 
 * hash. Itera sobre cada lista enlazada en la 
 * tabla y elimina cada contacto.
 */
HashTable::~HashTable() {
    // Destructor que libera la memoria ocupada por los contactos almacenados en la tabla
    for (auto& lista : tabla) {
        for (auto contactoPtr : lista) {
            delete contactoPtr;
        }
    }
}

/**
 * @brief Indice
 * 
 * Calcula un indice para la tabla hash basado 
 * en la longitud del nombre del contacto
 */
int HashTable::hashFunc(const std::string& clave) const {
    // Funcion de hash para generar el indice que se utilizara
    return clave.length() % TABLE_SIZE;
}

/**
 * @brief Funcion agregarContacto
 * 
 * Crea un nuevo objeto Contacto, 
 * ya creado, calcula su indice 
 * en la tabla hash y lo agrega 
 * a la lista enlazada correspondiente.
 */
void HashTable::agregarContacto(const std::string& nombre, const std::string& telefono) {
    // Crea un nuevo contacto en la memoria cloud
    Contacto* nuevoContacto = new Contacto(nombre, telefono);

    // Calcula el indice en la tabla hash
    int indice = hashFunc(nombre);

    // Agrega el contacto a la lista enlazada asociada al indice
    tabla[indice].push_back(nuevoContacto);
}

/**
 * @brief Funcion eliminarContacto
 * 
 *  Busca el contacto con el nombre 
 *  especificado en la tabla hash, 
 *  ademas permite al usuario elegir si desea 
 *  eliminar el contacto solo de la memoria 
 *  del celular o tambien de la memoria 
 *  cloud, y luego lo elimina de la lista 
 *  enlazada.
 */
void HashTable::eliminarContacto(const std::string& nombre) {
    // Busca el contacto por nombre y permite al usuario elegir si eliminarlo solo de la memoria del celular o tambien de la nube.
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

/**
 * @brief Funcion para imprimir el Hash
 * 
 * Imprime el contenido de la tabla hash 
 * y las listas enlazadas asociadas a cada 
 * indice.
 */
void HashTable::imprimir() const {
    // Imprime el contenido de la tabla hash y las listas enlazadas asociadas a cada indice.
    std::cout << "Imprimiendo Hash-Table y Listas Enlazadas:" << std::endl;
    for (size_t i = 0; i < tabla.size(); ++i) {
        std::cout << "Indice " << i << ": ";
        for (const auto& contactoPtr : tabla[i]) {
            std::cout << contactoPtr->nombre << " - " << contactoPtr->telefono << " | ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Funcion para obtener el contacto
 * 
 * Retorna un vector que contiene todos los contactos 
 * almacenados en la tabla hash.
 */
std::vector<Contacto*> HashTable::obtenerContactosCelular() const {
    // Retorna un vector que contiene todos los contactos almacenados en la tabla hash.
    std::vector<Contacto*> contactos;
    for (const auto& lista : tabla) {
        for (const auto& contactoPtr : lista) {
            contactos.push_back(contactoPtr);
        }
    }
    return contactos;
}