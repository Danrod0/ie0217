#include <iostream>
#include "funciones.hpp"
#include <string>

using namespace std;

void agregarPalabra(string diccionario[], int &cantidadDiccionario) {

    string palabra;

    cout << "\nIngrese la palabra que desea agregar al diccionario: ";
    cin >> palabra;

    diccionario[cantidadDiccionario++] = palabra;
}