/**
 * @file main.cpp
 * @brief Este archivo tiene la funcion main del programa con el menu inicial
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 3/4/24
 * 
 * Licencia: MIT
 */

#include <iostream>
#include <string>
#include "funciones.hpp"
#include "juego.hpp"

using namespace std;

/**
 * @brief Es la funcion main del programa.
 * 
 * Se realiza una estructura do-while para el menu de inicio
 * donde se utiliza un switch case para las opciones del menu
 * en el caso 1 se utiliza otro switch case para definir la
 * dificultad que el usuario desea utilizar.
 * En el caso de la opcion 2 se maneja la ejecución principal 
 * del juego del Ahorcado. Comienza iniciando una partida y 
 * mostrando la palabra oculta. Luego, solicita al usuario 
 * que ingrese letras para adivinar la palabra, actualizando 
 * el estado de la palabra y mostrando los intentos restantes. 
 * Después de cada intento, informa si la letra ingresada fue 
 * correcta o incorrecta. Finalmente, muestra un mensaje de 
 * felicitaciones si el jugador adivina la palabra o "Game over" 
 * si se quedan sin intentos.
 * En el caso de la opcion 3, se llama a la funcion para agregar
 * una palabra al diccionario.
 * En el caso de la opcion 4 se llama a la funcion para observar
 * el diccionario en consola.
 * Por utlimo el caso 5 termina el programa.
 * 
 * 
 * @return Retorna 0
 */

int main() {

    /*
    Primero se inicializa y definen todas las variables a
    utilizar a lo largo del programa.
    */

    int opcion;
    int intentos = 7;
    int dificultad = 1;
    string diccionario[1000] = {"curso", "ingenieria", "electrica", "juego", "ansiedad"};
    int cantidadDiccionario = 5;
    bool acierto; 
    string palabraIntento;
    char letra;
    Ahorcado juego;


    /*
    Se realiza una estructura do-while para el menu de inicio
    donde se utiliza un switch case para las opciones del menu
    en el caso 1 se utiliza otro switch case para definir la
    dificultad que el usuario desea utilizar.
    En el caso de la opcion 2 se maneja la ejecución principal 
    del juego del Ahorcado. Comienza iniciando una partida y 
    mostrando la palabra oculta. Luego, solicita al usuario 
    que ingrese letras para adivinar la palabra, actualizando 
    el estado de la palabra y mostrando los intentos restantes. 
    Después de cada intento, informa si la letra ingresada fue 
    correcta o incorrecta. Finalmente, muestra un mensaje de 
    felicitaciones si el jugador adivina la palabra o "Game over" 
    si se quedan sin intentos.
    En el caso de la opcion 3, se llama a la funcion para agregar
    una palabra al diccionario.
    En el caso de la opcion 4 se llama a la funcion para observar
    el diccionario en consola.
    Por utlimo el caso 5 termina el programa.
    */
    do {
        cout << "\nBienvenido al juego del Ahorcado\n" << endl;
        cout << "1. Elegir la dificultad del juego" << endl;
        cout << "2. Iniciar el juego" << endl;
        cout << "3. Agregar palabra al diccionario" << endl;
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