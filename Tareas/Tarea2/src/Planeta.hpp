/**
 * @file Planeta.hpp
 * @brief Este archivo tiene la definicion de la clase Planeta
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#ifndef PLANETA_HPP
#define PLANETA_HPP

#include <iostream>
#include <string>
#include "Continentes.hpp"

class Planeta {
private:
    static const int MAX_CONTINENTES = 5; // Número máximo de continentes en el planeta
    Continentes* continentes[MAX_CONTINENTES]; // Arreglo de punteros a objetos Continentes
    int num_continentes; // Número actual de continentes en el planeta

public:
    // Constructor de la clase
    Planeta();

    // Destructor de la clase
    ~Planeta();

    // Método para agregar un continente al planeta
    void agregarContinente(Continentes* continente);

    // Método para imprimir información sobre el planeta y sus continentes
    void imprimirInformacion() const;

    // Método getter para obtener el número de continentes en el planeta
    int getNumContinentes() const;

    // Método getter para obtener un puntero al arreglo de continentes
    Continentes* getContinentes() const;

    // Nuevo método para agregar un país en un continente específico
    void agregarPaisEnContinente(Pais* pais, int indiceContinente);
};

#endif // PLANETA_HPP