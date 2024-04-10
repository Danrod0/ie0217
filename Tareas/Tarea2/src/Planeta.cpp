/**
 * @file Planeta.cpp
 * @brief Este archivo tiene las funciones de la clase Planeta
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#include "Planeta.hpp"
#include <iostream>

using namespace std;

// Constructor por defecto
Planeta::Planeta() : num_continentes(0) {}

// Destructor
Planeta::~Planeta() {
    // Liberar la memoria de los continentes
    for (int i = 0; i < num_continentes; ++i) {
        delete continentes[i];
    }
}

/**
 * @brief Agregar continente
 * 
 * Metodo para agregar un continente al
 * planeta
 * 
 */
// Método para agregar un continente al planeta
void Planeta::agregarContinente(Continentes* continente) {
    if (num_continentes < MAX_CONTINENTES) {
        continentes[num_continentes++] = continente;
    } else {
        cout << "No se pueden agregar más continentes." << endl;
    }
}

/**
 * @brief Imprime informacion
 * 
 * Imprime la informacion del planeta
 * y sus continentes
 * 
 */
// Método para imprimir información sobre el planeta y sus continentes
void Planeta::imprimirInformacion() const {
    cout << "Informacion general:" << endl;
    cout << "Planeta posee " << num_continentes << " continentes." << endl;
    cout << "Informacion sobre los continentes:" << endl;
    for (int i = 0; i < num_continentes; ++i) {
        continentes[i]->imprimirInformacion();
    }
}

/**
 * @brief Cantidad de contientes
 * 
 * Metodo para obtener el numero
 * de continentes
 * 
 * @return num_continentes, devuelve la cantidad de continentes
 * 
 */
// Método para obtener el número de continentes en el planeta
int Planeta::getNumContinentes() const {
    return num_continentes;
}

/**
 * @brief Puntero al arreglo
 * 
 * Metodo para obtener un puntero
 * del arreglo de continentes
 * 
 * @return *continentes, devuelve el puntero
 * 
 */
// Método para obtener un puntero al arreglo de continentes
Continentes* Planeta::getContinentes() const {
    return *continentes;
}

/**
 * @brief Agregar pais a continente.
 * 
 * Metodo para agregar un paisn a un continente
 * en especifico
 * 
 */
// Método para agregar un país en un continente específico
void Planeta::agregarPaisEnContinente(Pais* pais, int indiceContinente) {
    if (indiceContinente >= 0 && indiceContinente < Planeta::num_continentes) {
        Planeta::continentes[indiceContinente]->agregarPais(pais);
    } else {
        cout << "Índice de continente no válido." << endl;
    }
}