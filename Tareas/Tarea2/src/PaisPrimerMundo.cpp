/**
 * @file PaisPrimerMundo.cpp
 * @brief Este archivo tiene las funciones de la clase PaisPrimerMundo
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#include <iostream>
#include "PaisPrimerMundo.hpp"

// Constructor de la clase PaisPrimerMundo
PaisPrimerMundo::PaisPrimerMundo(int id, int habitantes, bool tecnologia_5g, bool centro_investigacion)
    : Pais(id, habitantes), tecnologia_5g(tecnologia_5g), centro_investigacion(centro_investigacion) {}

// Destructor de la clase PaisPrimerMundo
PaisPrimerMundo::~PaisPrimerMundo() {}

/**
 * @brief Saber si es del primer mundo
 * 
 * Es el metodo para determinar
 * si el pais es de primer mundo
 * 
 * @return devuelve un booleano true para decir que es de primer mundo
 * 
 */
// Método para determinar si el país de primer mundo es del primer mundo
bool PaisPrimerMundo::esPrimerMundo() const {
    return true;
}

/**
 * @brief Imprime informacion
 * 
 * Imprime la informacion del pais de primer
 * mundo
 * 
 */
// Método para imprimir información específica de un país de primer mundo
void PaisPrimerMundo::imprimirInformacion() const {
    std::cout << "Pais de primer mundo:" << std::endl;
    Pais::imprimirInformacion();
    std::cout << "Tecnologia 5G: " << (tecnologia_5g ? "Si" : "No") << std::endl;
    std::cout << "Centro de investigacion y desarrollo: " << (centro_investigacion ? "Si" : "No") << std::endl;
}