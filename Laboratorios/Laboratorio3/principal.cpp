#include "funciones.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    /*
    Utiliza un bucle do while, para
    mantenerse en el menu hasta que se
    seleccione la opcion de salir, ademas
    de un switch case para evaluar las entradas
    dependiendo de cual sea llama a las distintas
    funciones, cuando se utiliza la opcion de
    salir sale del ciclo y llama a la funcion
    para liberar memoria.
    */
   
    Libro* listaLibros = nullptr;
    int opcion;

    do{
        cout << "Seleccione una opcopn: " << endl;
        cout << "1. Agregar un libro " << endl;
        cout << "2. Mostrar todos los libros " << endl;
        cout << "3. Salir " << endl;
        cin >> opcion;

        switch (opcion){
            case AGREGAR_LIBRO:
                agregarLibro(listaLibros);
                break;
            case MOSTRAR_LIBROS:
                mostrarLibros(listaLibros);
                break;
            case SALIR:
                cout << "Saliendo del programa... " << endl;
                break;
            default:
                cout << "Opcion no permitida. " << endl;
                break;
        }
    } while (opcion != SALIR);

    liberarMemoria(listaLibros);

    return 0;
}