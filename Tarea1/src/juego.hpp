#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <string>

using namespace std;

struct Ahorcado {
    string palabraAdivinar;
    string estadoPalabra;
    int intentosMaximos;
    int intentosRealizados;
};

#endif // JUEGO_HPP