#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>

// Definicion de la estructura libro
struct Libro {
    std::string titulo; 
    std::string autor; 
    std::string genero;
    Libro* siguiente; // Se crea un puntero para el siguiente libro en la lista
};

// Se hace una enumeracion para las opcopmes de; ,emi
enum opciones{
    AGREGAR_LIBRO = 1,
    MOSTRAR_LIBROS = 2,
    SALIR = 3,
    OPCIONES_MAX
};

/*
Se declara la funcion agregarLibro
Recibiendo de parametro de entrada
Libro*& lista, lo cual le permite
modificar la lista como tal.
*/ 
void agregarLibro(Libro*& lista);

/*
Se declara la funcion mostrarLibro
Recibiendo de parametro de entrada
Libro* lista, lo cual le permite
ingresar a los valores de la lista.
*/ 
void mostrarLibros(Libro* lista);

/*
Se declara la funcion liberarMemoria
Recibiendo de parametro de entrada
Libro*& lista, lo cual le permite
modificar la lista como tal.
*/ 
void liberarMemoria(Libro*& lista);

#endif // FUNCIONES_HPP