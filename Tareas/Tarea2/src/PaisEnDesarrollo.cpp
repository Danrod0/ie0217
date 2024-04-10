/**
 * @file PaisEnDesarrollo.cpp
 * @brief Este archivo tiene las funciones de la clase PaisEnDesarrollo
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#include <iostream>
#include "PaisEnDesarrollo.hpp"

// Constructor de la clase PaisEnDesarrollo
PaisEnDesarrollo::PaisEnDesarrollo(int id, int habitantes) : Pais(id, habitantes) {}

// Destructor de la clase PaisEnDesarrollo
PaisEnDesarrollo::~PaisEnDesarrollo() {}

/**
 * @brief Saber si es del primer mundo
 * 
 * Es el metodo para determinar
 * si el pais es de primer mundo
 * 
 * @return devuelve un booleano false para decir que no es de primer mundo
 * 
 */
// Método para determinar si el país en desarrollo es del primer mundo
bool PaisEnDesarrollo::esPrimerMundo() const {
    return false; // Los países en desarrollo no son del primer mundo
}

/**
 * @brief Imprime info
 * 
 * Imprime info del pais en desarrollo
 * 
 */
// Método para imprimir información específica de un país en desarrollo
void PaisEnDesarrollo::imprimirInformacion() const {
    std::cout << "Pais en desarrollo:" << std::endl;
    Pais::imprimirInformacion(); // Llama al método de la clase base para imprimir la información básica
}