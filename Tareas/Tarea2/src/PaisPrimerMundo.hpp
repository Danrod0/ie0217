/**
 * @file PaisPrimerMundo.hpp
 * @brief Este archivo tiene la definicion de la clase PaisPrimerMundo
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include <iostream>
#include "Pais.hpp"

class PaisPrimerMundo : public Pais {
private:
    bool tecnologia_5g; // Variable booleana que indica si el país tiene tecnología 5G
    bool centro_investigacion; // Variable booleana que indica si el país tiene centro de investigación

public:
    // Constructor de la clase
    PaisPrimerMundo(int id, int habitantes, bool tecnologia_5g, bool centro_investigacion);

    // Destructor de la clase
    ~PaisPrimerMundo();

    // Método para verificar si el país es del primer mundo
    bool esPrimerMundo() const override;

    // Método para imprimir información específica del país de primer mundo
    void imprimirInformacion() const override;
};

#endif // PAISPRIMERMUNDO_HPP