#include <iostream>

using namespace std;

int main() {
    int opcion;

    do {
        cout << "Bienvenido al juego del Ahorcado" << endl;
        cout << "1. Elegir la dificultad del juego" << endl;
        cout << "2. Iniciar el juego" << endl;
        cout << "3. Agregar palabras al diccionario" << endl;
        cout << "4. Ver diccionario de palabras" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Probando opcion 1" << endl;
                break;
            case 2:
                cout << "Probando opcion 2" << endl;
                break;
            case 3:
                cout << "Probando opcion 3" << endl;
                break;
            case 4:
                cout << "Probando opcion 4" << endl;
                break;
            case 5:
                cout << "Muchas gracias por jugar"<< endl;
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, por favor intente de nuevo." << endl;
        }
    } while(opcion != 5);

    return 0;
}
