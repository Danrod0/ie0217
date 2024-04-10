/**
 * @file Pais.cpp
 * @brief Este archivo tiene las funciones de la clase Pais
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#include "Pais.hpp"
#include <iostream>
#include <cstdlib>

// Constructor de la clase Pais que inicializa el ID y el número de habitantes
Pais::Pais(int id, int habitantes) : id(id), habitantes(habitantes), pib(0) {}

// Destructor de la clase Pais
Pais::~Pais() {}

/**
 * @brief Da el id
 * 
 * obtiene el id del pais
 * 
 * @return id , devuelve el id del pais
 * 
 */
// Método para obtener el ID del país
int Pais::getId() const {
    return id;
}

/**
 * @brief Obtiene el numero de habitantes
 * 
 * Metodo para obtener el numero de habitantes
 * del pais
 * 
 * @return habitantes , devuelve la cantidad de habitantes
 * 
 */
// Método para obtener el número de habitantes del país
int Pais::getHabitantes() const {
    return habitantes;
}


/**
 * @brief Generacion PIB
 * 
 * Genera un PIN para un pais, de
 * manera aleatoria.
 * 
 * @return devuelve un PIB aleatorio
 * 
 */
// Método para generar un PIB aleatorio y asignarlo al país
float Pais::generarPIB() const {
    // Genera un PIB aleatorio entre 1 y 1000
    return (rand() % 1000) + 1;
}

/**
 * @brief Imprimir informacion
 * 
 * Imprime las informacion de cada pais
 * 
 */
// Método para imprimir información sobre el país
void Pais::imprimirInformacion() const {
    std::cout << "ID del país: " << id << std::endl;
    std::cout << "Habitantes: " << habitantes << std::endl;
    std::cout << "PIB: " << pib << std::endl;
}


// Sobrecarga del operador de igualdad para comparar dos países
bool Pais::operator==(const Pais& otro) const {
    // Compara el ID y el número de habitantes
    return id == otro.id && habitantes == otro.habitantes;
}