#include <iostream>
#include <string>
#include "Contacto.hpp"
#include "HashTable.hpp"

using namespace std;

enum opciones {
    AGREGAR_CONTACTO = 1,
    ELIMINAR_CONTACTO,
    IMPRIMIR,
    MOSTRAR_CONTACTOS,
    SALIR,
    OPCIONES_MAX
};

int main() {
    HashTable tabla;

    int opcion;
    string nombre;
    string telefono;

    do {
        cout << "\nBienvenido a la aplicacion de Contactos\n" << endl;
        cout << "1. Agregar un contacto" << endl;
        cout << "2. Eliminar un contacto" << endl;
        cout << "3. Imprimir Hash-Table y Listas Enlazadas" << endl;
        cout << "4. Mostrar todos los contactos" << endl;
        cout << "5. Salir del programa\n" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case AGREGAR_CONTACTO:

                cin.ignore();
                cout << "Ingrese el nombre del contacto: ";
                getline(cin, nombre);
                cout << "Ingrese el numero de telefono del contacto: ";
                cin >> telefono;
                tabla.agregarContacto(nombre, telefono);
                break;

            case ELIMINAR_CONTACTO:

                std::cin.ignore();
                std::cout << "Ingrese el nombre del contacto a eliminar: ";
                std::getline(std::cin, nombre);
                tabla.eliminarContacto(nombre);
                break;

            case IMPRIMIR:

                cout << "Opcion para imprimir" << endl;
                break;

            case MOSTRAR_CONTACTOS:
                cout << "Opcion para mostrar contactos" << endl;

            case SALIR:

                cout << "Saliendo del programa...\n" << endl;
                break;

            default:

                cout << "\nOpcion no valida, por favor intente de nuevo." << endl;
        }
    } while(opcion != SALIR);

    return 0;
}