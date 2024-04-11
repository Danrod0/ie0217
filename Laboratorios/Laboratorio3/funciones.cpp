#include "funciones.hpp" // Incluye el archivo de cabecera 
#include <iostream>
#include <string>

using namespace std;



void agregarLibro(Libro*& lista){
    /*
    Es la funcion para agregar un libro
    a la lista, primero crea un nuevo
    libro y solicita al usuario que ingrese
    los detalles del mismo.
    */

    Libro* nuevoLibro = new Libro; // reserva el espacio en la memoria dinamica

    cout << "Ingrese el titulo del libro: " << endl;
    cin.ignore();
    getline(cin, nuevoLibro->titulo);

    cout << "Ingrese el autor del libro: " << endl;
    getline(cin, nuevoLibro->autor);

    cout << "Ingrese el genero del libro: " << endl;
    getline(cin, nuevoLibro->genero);

    nuevoLibro->siguiente = lista; // Establece el siguiente como el primero de la lista

    lista = nuevoLibro; // actualiza la lista para agregar el nuevo libro

    cout << "Libro agregado correctamente " << endl;

}


void mostrarLibros(Libro* lista) {
    /*
    Es la funcion para mostrar todos
    los libros de la lista, primero
    verifica que el puntero no sea nulo,
    si no lo es, empieza a imprimir
    la lista con un bucle while hasta que
    el puntero vuelva a ser nulo.
    */
   
    if (lista == nullptr){
        cout << "La libreria no tiene libros. " << endl;
        return;
    }

    cout << "Lista de libros: " << endl;
    while (lista != nullptr){
        cout << "Titulo: " << lista->titulo << endl;
        cout << "Autor: " << lista->autor << endl;
        cout << "Genero: " << lista->genero << endl << endl;
        lista = lista->siguiente;
    }
}


void liberarMemoria(Libro*& lista){
    /*
    Se crea la funcion para liberar
    memoria, se utiliza un bucle while
    para verificar cuando ya se haya 
    terminado de liberar memoria, mientras
    no, va a agarrar el primer elemento
    de la lista apuntado con un puntero
    y lo guardara en una variable temporal
    luego hara que la lista pase al siguiente
    elemento y elimina la variable temporal
    y asi hasta que el siguente elemento sea
    null.
    */

    while(lista != nullptr){
        Libro* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
}