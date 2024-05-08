/**
 * @file  clases.cpp
 * @brief En este archivo se definen todas las clases
 * y funciones que no se manejan con templates.
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 08/05/2024
 * 
 * Licencia: MIT
 */

#include "clases.hpp" // Incluimos el archivo de encabezado que contiene la definicion de la clase

/**
* @brief La funcion validarDatos dentro de la clase ValidarEntrada toma una cadena de
* entrada input y verifica si corresponde a tipos de datos especificos. Si input es "enteros", 
* devuelve "int"; si es "flotantes", devuelve "float"; si es "complejos", devuelve "std::complex"; de lo 
* contrario, lanza una excepcion indicando que el tipo de dato es invalido.
* 
* @param input es un parametro de tipo std::string que representa la entrada de datos que ingresa
* el usuaruo que sera validado en la funcion
* 
*/

// Definicion de la funcion para validar el tipo de datos de entrada
std::string ValidarEntrada::validarDatos(std::string input){ 
   
    if (input == "enteros") {
            return "int"; // Devuelve "int" si la entrada es "enteros"
    } 
        
    else if (input == "flotantes") {
        return "float"; // Devuelve "float" si la entrada es "flotantes"
    } 
        
    else if (input == "complejos") {
        return "std::complex"; // Devuelve "std::complex" si la entrada es "complejos"
    } 
  
    else {
        throw std::invalid_argument("Tipo de dato invalido"); // Lanza una excepcion si la entrada no coincide con los tipos esperados
    }


}

/**
* @brief La funcion validarTamanio dentro de la clase ValidarEntrada toma un parametro 
* entero tamanio y verifica si es menor o igual a cero. Si es asi, lanza una excepcion 
* indicando que el tamaño de la matriz no puede ser negativo o cero.
* 
* @param tamanio es un parametro entero que representa el tamaño de la matriz que se 
* validara en la funcion
* 
*/

// Definicion de la funcion para validar el tamaño de la matriz
void ValidarEntrada::validarTamanio(int tamanio){ 
   
    if (tamanio  <= 0 ) {
            // Lanza una excepcion si el tamaño es negativo o cero
          throw ("\nEl tamanio de la matriz no puede tener valores negativos o cero\n");  
    } 
        
}