#include <iostream>
#include <string>
#include "Contacto.hpp"
#include "HashTable.hpp"

using namespace std;

// Enumeracion para representar las opciones del menu
enum opciones {
    AGREGAR_CONTACTO = 1,
    ELIMINAR_CONTACTO,
    IMPRIMIR,
    MOSTRAR_CONTACTOS,
    SALIR,
    OPCIONES_MAX
};

/**
 * @brief Funcion main
 * 
 * Se crea la funcion main, la cual
 * cuenta con un bucle Do-While
 * para mantener el menu.
 */
int main() {
    HashTable tabla; // Se crea una instancia de HashTable para almacenar los contactos

    int opcion;
    string nombre;
    string telefono;

    // Bucle do-While para el menu principal
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

                cin.ignore(); // Limpia el buffer del teclado
                cout << "Ingrese el nombre del contacto: ";
                getline(cin, nombre); // Lee el nombre del contacto
                cout << "Ingrese el numero de telefono del contacto: ";
                cin >> telefono;
                tabla.agregarContacto(nombre, telefono); // Agrega el contacto a la tabla
                break;

            case ELIMINAR_CONTACTO:

                cin.ignore(); // Limpia el buffer del teclado
                cout << "Ingrese el nombre del contacto a eliminar: ";
                getline(std::cin, nombre);
                tabla.eliminarContacto(nombre); // Elimina el contacto de la tabla
                break;

            case IMPRIMIR:

                tabla.imprimir(); // Imprime la estructura de la tabla hash
                break;

            case MOSTRAR_CONTACTOS: {

                    // Se obtienen los contactos almacenados en la memoria del celular
                    std::vector<Contacto*> contactosCelular = tabla.obtenerContactosCelular();

                    // Se utiliza el algoritmo de ordenamiento de burbuja para ordenar los contactos
                    // en orden alfabetico.
                    for (size_t i = 0; i < contactosCelular.size() - 1; ++i) {
                        for (size_t j = 0; j < contactosCelular.size() - i - 1; ++j) {
                            if (contactosCelular[j]->getNombre() > contactosCelular[j + 1]->getNombre()) {
                                // Aca intercambia los elementos si están en el orden incorrecto
                                std::swap(contactosCelular[j], contactosCelular[j + 1]);
                            }
                        }
                    }

                    // Aca se imprimen los contactos ya ordenados
                    cout << "Contactos almacenados en la memoria del celular:" << std::endl;
                    for (const auto& contactoPtr : contactosCelular) {
                        cout << "Nombre: " << contactoPtr->getNombre() << ", Telefono: " << contactoPtr->getTelefono() << std::endl;
                    }
                }
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