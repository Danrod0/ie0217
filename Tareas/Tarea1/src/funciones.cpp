/**
 * @file funciones.cpp
 * @brief Este archivo tiene las definiciones de las funciones
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 3/4/24
 * 
 * Licencia: MIT
 */
#include <iostream>
#include "funciones.hpp"
#include <string>
#include "juego.hpp"
#include <ctime>

using namespace std;

/**
 * @brief Agrega palabras al diccionario.
 * 
 * Esta funcion solicita al usuario que ingrese la palabra que desea agregar
 * al diccionario, seguidamente guarda esta palabra en una variable para
 * ingresarla al diccionario.
 * 
 * @param diccionario[] , es el array de palabras
 * @param cantidadDiccionario , es la cantidad de objetos que pueden haber en el array
 * 
 */

void agregarPalabra(string diccionario[], int &cantidadDiccionario) {

    /*
    Esta funcion solicita al usuario que ingrese la palabra que desea agregar
    al diccionario, seguidamente guarda esta palabra en una variable para
    ingresarla al diccionario.

    Recibe dos parametros de entrada, el diccionario, que es una variable
    tipo array, y cantidadDiccionario que es una variable tipo entera
    modificable.
    */

    string palabra;

    cout << "\nIngrese la palabra que desea agregar al diccionario: ";
    cin >> palabra;

    diccionario[cantidadDiccionario++] = palabra;
}


/**
 * @brief Muestra las palabras del diccionario.
 * 
 * Esta funcion utiliza un ciclo for para imprimir en consola los elementos
 * de la variable diccionario, la cual recibe la funcion y es de tipo array.
 * 
 * @param diccionario[] , es el array de palabras
 * @param cantidadDiccionario , es la cantidad de objetos que pueden haber en el array
 * 
 */

void mostrarDiccionario(const string diccionario[], const int cantidadDiccionario) {

    /*
    Esta funcion utiliza un ciclo for para imprimir en consola los elementos
    de la variable diccionario, la cual recibe la funcion y es de tipo array.
    */

    cout << "\nDiccionario de palabras:" << endl;
    for (int i = 0; i < cantidadDiccionario; ++i) {
        cout << diccionario[i] << endl;
    }
}


/**
 * @brief inicia el juego de ahorcado.
 * 
 * Esta funcion es la que se utiliza para iniciar el juego, o sea dar parametros
 * a la estructura. Utiliza la funcion time para generar un numero random basado
 * en el tiempo, con esto selecciona de manera aleatoria una palabra del diccionario
 * para utilizarla como la palabra a adivinar, ademas de generar la palabra con
 * los guiones bajos. Recibe de parametro el juego, la estructura, el diccionario
 * pero como puntero, la cantidad de datos que pueden haber en el diccionario
 * y la cantidad de intento (dificultad)
 * 
 * @param juego , es la estructura del juego
 * @param diccionario[] , es el array de palabras en modo puntero
 * @param cantidadDiccionario , es la cantidad de objetos que pueden haber en el array
 * @param intentos , es la cantidad maxima de intentos
 * 
 */

void iniciarJuego(Ahorcado &juego, string* diccionario, const int cantidadDiccionario, int intentos) {

    /*
    Esta funcion es la que se utiliza para iniciar el juego, o sea dar parametros
    a la estructura. Utiliza la funcion time para generar un numero random basado
    en el tiempo, con esto selecciona de manera aleatoria una palabra del diccionario
    para utilizarla como la palabra a adivinar, ademas de generar la palabra con
    los guiones bajos. Recibe de parametro el juego, la estructura, el diccionario
    pero como puntero, la cantidad de datos que pueden haber en el diccionario
    y la cantidad de intento (dificultad)
    */
    
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


/**
 * @brief Adivina la letra en el juego de ahorcado
 * 
 * Esta funcion es la que se encarga de adivinar las letras de la
 * palabra seleccionada aleatoriamente. Se encuentra iterando 
 * sobre la palabra a adivinar desde el inicio, si encuentra
 * la letra ingresada por el usuario, la cambia en la palabra 
 * actual, si no la encuentra aumenta el contador de intentos.
 * recibe como parametros de entrada la letra, y el juego.
 * 
 * @param juego , es la estructura del juego.
 * @param char , es la letra ingrersada por el usuario.
 * 
 * @return devuelve un valor de true o false dependiendo si encuentra la letra
 */

bool adivinarLetra(Ahorcado &juego, char letra) {

    /*
    Esta funcion es la que se encarga de adivinar las letras de la
    palabra seleccionada aleatoriamente. Se encuentra iterando 
    sobre la palabra a adivinar desde el inicio, si encuentra
    la letra ingresada por el usuario, la cambia en la palabra 
    actual, si no la encuentra aumenta el contador de intentos.
    recibe como parametros de entrada la letra, y el juego.
    */

    bool acierto = false;
    for (size_t i = 0; i < juego.palabraAdivinar.length(); ++i) {
        if (*(juego.palabraAdivinar.begin() + i) == letra) {
            *(juego.estadoPalabra.begin() + i) = letra;
            acierto = true;
        }
    }
    if (!acierto) {
        juego.intentosRealizados++;
    }
    return acierto;
}


/**
 * @brief termina el juego.
 * 
 * Esta función verifica si el juego ha terminado. Si el número de 
 * intentos realizados es igual o mayor que los intentos máximos 
 * permitidos, solicita al usuario que ingrese la palabra completa. 
 * Si la palabra completa ingresada coincide con la palabra a adivinar, 
 * imprime un mensaje indicando que la palabra es correcta. En caso 
 * contrario, imprime un mensaje de "Game over", recibe como parametro
 * el juego.
 * 
 * @param juego , es la estructura del juego.
 * 
 * @return devuelve true o false dependiendo de si termino el juego o no
 */

bool juegoTerminado(Ahorcado &juego) {

    /*
    Esta función verifica si el juego ha terminado. Si el número de 
    intentos realizados es igual o mayor que los intentos máximos 
    permitidos, solicita al usuario que ingrese la palabra completa. 
    Si la palabra completa ingresada coincide con la palabra a adivinar, 
    imprime un mensaje indicando que la palabra es correcta. En caso 
    contrario, imprime un mensaje de "Game over", recibe como parametro
    el juego.
    */

    if (juego.intentosRealizados >= juego.intentosMaximos) {
        cout << "Se han agotado todos los intentos" << endl;
        cout << "Ingrese la palabra completa para intentar adivinarla: ";
        string palabraCompleta;
        cin >> palabraCompleta;
        if (palabraCompleta == juego.palabraAdivinar) {
            cout << "Palabra correcta, Has adivinado la palabra." << endl;
            return true;
        } else {
            cout << "Game over, La palabra era: " << juego.palabraAdivinar << endl;
            return true;
        }
    }
    return (juego.estadoPalabra == juego.palabraAdivinar);
}