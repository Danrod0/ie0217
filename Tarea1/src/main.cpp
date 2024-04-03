#include <iostream>
#include <string>
#include "funciones.hpp"
#include "juego.hpp"

using namespace std;

int main() {
    int opcion;
    int intentos = 7;
    int dificultad = 1;
    string diccionario[1000] = {"curso", "ingenieria", "electrica", "juego", "ansiedad"};
    int cantidadDiccionario = 5;
    bool acierto; 
    string palabraIntento;
    char letra;
    Ahorcado juego;

    do {
        cout << "\nBienvenido al juego del Ahorcado\n" << endl;
        cout << "1. Elegir la dificultad del juego" << endl;
        cout << "2. Iniciar el juego" << endl;
        cout << "3. Agregar palabras al diccionario" << endl;
        cout << "4. Ver diccionario de palabras" << endl;
        cout << "5. Salir del programa\n" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\nSeleccione la dificultad:\n" << endl;
                cout << "1. Facil (7 intentos)" << endl;
                cout << "2. Intermedio (5 intentos)" << endl;
                cout << "3. Dificil (3 intentos)\n" << endl;
                cout << "Ingrese la opcion de dificultad: ";
                cin >> dificultad;

                switch(dificultad) {
                    case 1:
                        intentos = 7;
                        break;
                    case 2:
                        intentos = 5;
                        break;
                    case 3:
                        intentos = 3;
                        break;
                    default:
                        cout << "\nOpcion de dificultad no valida." << endl;
                        break;
                }
                break;
            case 2:
                iniciarJuego(juego, diccionario, cantidadDiccionario, intentos);
                cout << "Palabra actual: " << juego.estadoPalabra << endl;
                while (!juegoTerminado(juego)) {
                    cout << "Intentos restantes: " << juego.intentosMaximos - juego.intentosRealizados << endl;
                    cout << "Ingrese una letra para adivinar: ";
                    char letra;
                    cin >> letra;
                    bool acierto = adivinarLetra(juego, letra);
                    cout << "Palabra actual: " << juego.estadoPalabra << endl;
                    if (acierto) {
                        cout << "Letra correcta" << endl;
                    } else {
                        cout << "Letra incorrecta" << endl;
                    }
                }
                if (juego.estadoPalabra == juego.palabraAdivinar) {
                    cout << "Felicidades, Has adivinado la palabra." << endl;
                } else {
                    cout << "Game over, Has agotado todos los intentos. La palabra era: " << juego.palabraAdivinar << endl;
                }
                break;
            case 3:
                agregarPalabra(diccionario, cantidadDiccionario);
                break;
            case 4:
                mostrarDiccionario(diccionario, cantidadDiccionario);
                break;
            case 5:
                cout << "\nMuchas gracias por jugar"<< endl;
                cout << "Saliendo del programa...\n" << endl;
                break;
            default:
                cout << "\nOpcion no valida, por favor intente de nuevo." << endl;
        }
    } while(opcion != 5);

    return 0;
}