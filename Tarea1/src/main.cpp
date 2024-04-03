#include <iostream>


using namespace std;

int main() {
    int opcion;
    int intentos;

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
                cin >> intentos;

                switch(intentos) {
                    case 1:
                        cout << "Probando opcion 1 de la dificultad" << endl;
                        break;
                    case 2:
                        cout << "Probando opcion 2 de la dificultad" << endl;
                        break;
                    case 3:
                        cout << "Probando opcion 3 de la dificultad" << endl;
                        break;
                    default:
                        cout << "\nOpcion de dificultad no valida." << endl;
                        break;
                }
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
                cout << "\nMuchas gracias por jugar"<< endl;
                cout << "Saliendo del programa...\n" << endl;
                break;
            default:
                cout << "\nOpcion no valida, por favor intente de nuevo." << endl;
        }
    } while(opcion != 5);

    return 0;
}
