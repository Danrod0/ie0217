#include <iostream>

enum opciones{
    AGREGAR_CONTACTO = 1,
    ELIMINAR_CONTACTO,
    IMPRIMIR,
    MOSTRAR_CONTACTOS,
    SALIR,
    OPCIONES_MAX
};


int main() {

    int opcion;
    
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
                cout << "Opcion para agregar contacto" << endl;
                break;
            case ELIMINAR_CONTACTO:
                cout << "Opcion para eliminar contacto" << endl;
                break;
            case IMPRIMIR:
                cout << "Opcion para imprimir" << endl;
                break;
            case MOSTRAR_CONTACTOS:
                cout << "Opcion para mostrar contactos" << endl;
                break;
            case SALIR:
                cout << "Saliendo del programa...\n" << endl;
                break;
            default:
                cout << "\nOpcion no valida, por favor intente de nuevo." << endl;
        }
    } while(opcion != SALIR);

    return 0;
}