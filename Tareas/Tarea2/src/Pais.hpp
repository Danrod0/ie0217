/**
 * @file Pais.cpp
 * @brief Este archivo tiene la definicion de la clase pais
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#ifndef PAIS_HPP
#define PAIS_HPP

#include <iostream>
#include <string>

class Pais {
protected:
    int id; // Identificador del país
    int habitantes; // Número de habitantes del país
    float pib; // Producto Interno Bruto del país

public:
    // Constructor de la clase Pais
    Pais(int id, int habitantes);

    // Destructor virtual de la clase Pais
    virtual ~Pais();

    // Método para obtener el ID del país
    int getId() const;

    // Método para obtener el número de habitantes del país
    int getHabitantes() const;

    // Método virtual puro para determinar si el país es del primer mundo o no
    virtual bool esPrimerMundo() const = 0;

    // Método para generar un PIB aleatorio del país
    float generarPIB() const;

    // Método virtual para imprimir información sobre el país
    virtual void imprimirInformacion() const;

    // Sobrecarga del operador de igualdad para comparar dos países
    bool operator==(const Pais& otro) const;
};

#endif // PAIS_HPP