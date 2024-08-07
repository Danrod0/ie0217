/**
 * @file funciones.hpp
 * @brief Este archivo tiene las declaraciones de las funciones
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 3/4/24
 * 
 * Licencia: MIT
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "juego.hpp"

/*
Aca se declaran todas las funciones a utilizar en el programa
*/

using namespace std;

void agregarPalabra(string diccionario[], int &cantidadDiccionario);

void mostrarDiccionario(const string diccionario[], const int cantidadDiccionario);

void iniciarJuego(Ahorcado &juego, string* diccionario, const int cantidadDiccionario, int intentos);

bool adivinarLetra(Ahorcado &juego, char letra);

bool juegoTerminado(Ahorcado &juego);

#endif // FUNCIONES_HPP