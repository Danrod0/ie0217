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

void mostrarDiccionario(const string diccionario[], const int cantidadDiccionario) {
    cout << "\nDiccionario de palabras:" << endl;
    for (int i = 0; i < cantidadDiccionario; ++i) {
        cout << diccionario[i] << endl;
    }
}