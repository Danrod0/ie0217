#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "juego.hpp"

using namespace std;

void agregarPalabra(string diccionario[], int &cantidadDiccionario);

void mostrarDiccionario(const string diccionario[], const int cantidadDiccionario);

void iniciarJuego(Ahorcado &juego, string* diccionario, const int cantidadDiccionario, int intentos);


#endif // FUNCIONES_HPP