/**
 * @file juego.cpp
 * @brief Este archivo tiene la estructura del juego
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 3/4/24
 * 
 * Licencia: MIT
 */

#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <string>

using namespace std;


/**
 * @brief Es la estructura del juego.
 * 
 * Esta es la estructura del juego, contiene los parametros del mismo.
 * 
 */

struct Ahorcado {

    /*
    Se define la estructura del juego, o sea, los
    parametros que tendra, donde existen dos string
    la palabra a adivinar, y su version actual que
    contiene los guiones bajos, ademas de la cantidad
    de intentos maximos e intentos realizados.
    */

    string palabraAdivinar;
    string estadoPalabra;
    int intentosMaximos;
    int intentosRealizados;
};

#endif // JUEGO_HPP