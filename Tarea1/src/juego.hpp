#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <string>

using namespace std;

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