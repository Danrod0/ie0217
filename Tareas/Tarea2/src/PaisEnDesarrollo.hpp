/**
 * @file PaisEnDesarrollo.cpp
 * @brief Este archivo tiene la definicion de la clase PaisEnDesarrollo
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#ifndef PAISENDESARROLLO_HPP
#define PAISENDESARROLLO_HPP

#include <iostream>
#include "Pais.hpp"

class PaisEnDesarrollo : public Pais {
public:
    // Constructor de la clase PaisEnDesarrollo
    PaisEnDesarrollo(int id, int habitantes);

    // Destructor de la clase PaisEnDesarrollo
    ~PaisEnDesarrollo();

    // Método para determinar si el país en desarrollo es del primer mundo
    bool esPrimerMundo() const override;

    // Método para imprimir información específica de un país en desarrollo
    void imprimirInformacion() const override;
};

#endif // PAISENDESARROLLO_HPP