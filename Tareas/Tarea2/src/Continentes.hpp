/**
 * @file Continentes.hpp
 * @brief Este archivo tiene la definicion de la clase continentes
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#ifndef CONTINENTES_HPP
#define CONTINENTES_HPP

#include <iostream>
#include <string>
#include "Pais.hpp"

class Continentes {
private:
    std::string nombre;
    Pais** paises;
    int num_paises;
    int num_primer_mundo;
    int num_en_desarrollo;
    static const int MAX_PAISES = 10;

public:
    Continentes();  // Constructor
    Continentes(std::string nombre);
    ~Continentes();

    void agregarPais(Pais* pais); // Método para agregar un país al continente
    void imprimirInformacion() const; // Método para imprimir información sobre el continente
    int getNumPaises() const; // Método para obtener el número de países en el continente
    Pais** getPaises() const; // Método para obtener el arreglo de países del continente
    void eliminarPais(int idPais); // Método para eliminar un país del continente
};

#endif // CONTINENTES_HPP