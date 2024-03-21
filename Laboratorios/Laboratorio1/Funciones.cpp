#include "Funciones.hpp"

void agregarContacto(Contacto listaContactos[], int &numContactos){ // Define la funcion de agregar contactos

    Contacto nuevoContacto; // Inicializa una variable tipo contacto

    std::cout << "Ingrese el nombre del contacto: ";
    std::cin >> nuevoContacto.nombre;
    std::cout << "Ingrese el numero de telefono: ";
    std::cin >> nuevoContacto.telefono;

    listaContactos[numContactos++] = nuevoContacto; // Aca agrega el contacto
}

void mostrarContactos(const Contacto listaContactos[], int numContactos){ // Define la funcion para mostrar contactos
    std::cout << "Lista de contactos:\n";
    for (int i = 0; i < numContactos; ++i){ // Realiza un ciclo for para imprimir cada contacto uno por uno
        std::cout << "Nombre: " << listaContactos[i].nombre << ", Telefono: " << listaContactos[i].telefono << "\n";
    }
}

void buscarContacto(const Contacto listaContactos[], int numContactos){ // Define la funcion para buscar un contacto
    std::string nombreBusqueda; // Inicializa una variable tipo string
    std::cout << "Ingrese el nombre a buscar: ";
    std::cin >> nombreBusqueda;
    bool encontrado = false; // Inicializa un booleano en false
    for (int i = 0; i < numContactos; i++){ // Realiza un ciclo for para recorrer la lista de contactos
        if(listaContactos[i].nombre == nombreBusqueda){ // Utiliza un if para buscar el contacto, comparando el nombre de cada uno de los elementos de las lista con la variable tipo string
            std::cout << "Nombre: " << listaContactos[i].nombre << ", Telefono: " << listaContactos[i].telefono << "\n";
            encontrado = true; // cambia la variable booleana a true
            break;
        }
    }
    if (!encontrado){ // Si no encuentra el contacto, o sea si se mantiene en false la variable booleana, imprime en pantalla el siguiente mensaje
        std::cout << "Contacto no encontrado. \n";
    }
}