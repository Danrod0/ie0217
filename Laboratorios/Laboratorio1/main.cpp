#include <iostream>
#include "Contacto.hpp"
#include "Funciones.hpp"

#define MAX_CONTACTOS 100 // Define el valor de MAX_CONTACTOS en 100

enum Opciones { // Crea una lista de defines, donde los enumera a partir del 1
    AGREGAR = 1,
    MOSTRAR,
    BUSCAR,
    SALIR
};

int main(){
    Contacto listaContactos[MAX_CONTACTOS]; // Crea una lista tipo contacto

    int numContactos = 0;
    int opcion;

    do { // Presenta el menu
        std::cout << "\nMenu: \n";
        std::cout << "1. Agregar Contacto\n";
        std::cout << "2. Mostrar Contacto\n";
        std::cout << "3. Buscar Contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) { // Crea una estructura switch para definir quue se hace con el menu
            case AGREGAR:
                agregarContacto(listaContactos, numContactos);
                break;
            case MOSTRAR:
                mostrarContactos(listaContactos, numContactos);
                break;
            case BUSCAR:
                buscarContacto(listaContactos, numContactos);
                break;
            case SALIR:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo...\n";
                break;
        }

    } while (opcion != SALIR); // Hasta que no se de la opcion de salir, va a mantener el bucle

    return 0;
}