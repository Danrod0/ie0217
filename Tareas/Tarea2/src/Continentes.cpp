/**
 * @file Continentes.cpp
 * @brief Este archivo tiene las funciones de la clase continentes
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#include "Continentes.hpp" // Incluye la declaración de la clase Continentes
#include <iostream>


// Constructor predeterminado de Continentes
Continentes::Continentes() : nombre(""), num_paises(0), num_primer_mundo(0), num_en_desarrollo(0) {
    paises = new Pais*[MAX_PAISES]; // Inicializa el arreglo dinámico de punteros a objetos Pais
}

// Constructor de Continentes con nombre especificado
Continentes::Continentes(std::string nombre) : nombre(nombre), num_paises(0), num_primer_mundo(0), num_en_desarrollo(0) {
    paises = new Pais*[MAX_PAISES]; // Inicializa el arreglo dinámico de punteros a objetos Pais
}

// Destructor de Continentes
Continentes::~Continentes() {
    // Elimina cada país en el arreglo dinámico de paises
    for (int i = 0; i < num_paises; ++i) {
        delete paises[i];
    }
    // Libera la memoria del arreglo de punteros a objetos Pais
    delete[] paises;
}

/**
 * @brief Agregar paises a continentes
 * 
 * Esta funcion se encarga de agregar paises
 * a los contiententes que ya cuentan con nombre
 * y actualiza el conjunto de paises de desarrollo
 * y primer mundo.
 * 
 * @param pais , es un puntero que apunta al pais.
 * 
 */

// Agrega un país al continente
void Continentes::agregarPais(Pais* pais) {
    if (num_paises < MAX_PAISES) {
        // Agrega el país al arreglo de paises
        paises[num_paises++] = pais;
        // Actualiza el recuento de países de primer mundo y en desarrollo
        if (pais->esPrimerMundo()) {
            num_primer_mundo++;
        } else {
            num_en_desarrollo++;
        }
    } else {
        std::cout << "No se pueden agregar mas paises al continente " << nombre << "." << std::endl;
    }
}

/**
 * @brief Imprime info de los continentes
 * 
 * Se encarga de imprimir la informacion de los continentes
 * pertinente de los continentes, como la cantidad de
 * paises, la cantidad de paises en desarrollo
 * o de primer mundo
 * 
 */
// Imprime información sobre el continente y sus países
void Continentes::imprimirInformacion() const {
    std::cout << nombre << " posee " << num_paises << " paises, " << num_primer_mundo << " son de primer mundo y " << num_en_desarrollo << " estan en desarrollo." << std::endl;
}


/**
 * @brief Obtener cantridad de paises
 * 
 * Devuelve la cantidad de paises que se
 * encuentran en un continente.
 * 
 * @return Devuelve la cantidad de paises en el continente
 */
// Devuelve el número de países en el continente
int Continentes::getNumPaises() const {
    return num_paises;
}

/**
 * @brief Devuelve arreglo de paises
 * 
 * Esta funcion crea un puntero al arreglo
 * y se encarga de retornarlo.
 * 
 * @return Devuelve el arreglo de punteros a objetos pais
 */
// Devuelve el arreglo de punteros a objetos Pais
Pais** Continentes::getPaises() const {
    return paises;
}

/**
 * @brief Elimina un pais del continente
 * 
 * Esta funcion es la que se encarga de eliminar
 * paises, obtiene el id, busca el mismo y lo
 * elimina del continente.
 * 
 * @param idPais , recibe el id del pais
 * 
 */
// Elimina un país del continente según su ID
void Continentes::eliminarPais(int idPais) {
    for (int i = 0; i < num_paises; ++i) {
        if (paises[i]->getId() == idPais) {
            // Elimina el país encontrando y reorganiza el arreglo
            delete paises[i];
            for (int j = i; j < num_paises - 1; ++j) {
                paises[j] = paises[j + 1];
            }
            num_paises--;
            // Actualiza el recuento de países de primer mundo y en desarrollo
            if (paises[i]->esPrimerMundo()) {
                num_primer_mundo--;
            } else {
                num_en_desarrollo--;
            }
            std::cout << "Pais con ID " << idPais << " eliminado del continente " << nombre << "." << std::endl;
            return;
        }
    }
    std::cout << "Pais con ID " << idPais << " no encontrado en el continente " << nombre << "." << std::endl;
}