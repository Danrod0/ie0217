#include <iostream>
#include "funciones.hpp"
#include <string>
#include "juego.hpp"
#include <ctime>

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

void iniciarJuego(Ahorcado &juego, string* diccionario, const int cantidadDiccionario, int intentos) {
    
    srand(time(nullptr));

    
    int indicePalabra = rand() % cantidadDiccionario;
    juego.palabraAdivinar = diccionario[indicePalabra];

    
    juego.estadoPalabra = "";
    for (size_t i = 0; i < juego.palabraAdivinar.length(); ++i) {
        juego.estadoPalabra += "_";
    }
    
    juego.intentosMaximos = intentos; 
   
    juego.intentosRealizados = 0;
}

bool adivinarLetra(Ahorcado &juego, char letra) {
    bool acierto = false;
    for (size_t i = 0; i < juego.palabraAdivinar.length(); ++i) {
        if (*(juego.palabraAdivinar.begin() + i) == letra) {
            *(juego.estadoPalabra.begin() + i) = letra;
            acierto = true;
        }
    }
    juego.intentosRealizados++;
    return acierto;
}