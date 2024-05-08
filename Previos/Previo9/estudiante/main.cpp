#include <iostream>
#include "estudiante.hpp"

int main(){
    // Se crea un objeto Estudiante con nombre "Juan" y edad 20
    Estudiante estudiante("Juan", 20);

    // Llama al metodo mostrarDatos() para imprimir los datos del estudiante
    estudiante.mostrarDatos();
    
    return 0;
}