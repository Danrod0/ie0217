/**
 * @file  main.cpp
 * @brief Este archivo se encuentra el menu
 * y los pasos para validar un correo
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 16/5/2024
 * 
 * Licencia: MIT
 */

#include "Email.hpp"

#include <iostream>

using namespace std;

enum opciones  { // Enumera las opciones del menu
    CORREO = 1,
    SALIR
}; 

int main(){ 

    int opcion; // Variable para la opcion ingresada por el usuario

    ValidadorEmail validadorDeCorreos; // Objeto de la clase ValidadorEmail
    
    string correo; // Variable para almacenar el correo electronico

    cout << "Bienvenido a nuestro validador de correos" << endl;

    do{ 
        cout << "Por favor, seleccione una opcion." << endl;
        cout << "1. Ingresar correo electronico a validar" << endl;
        cout << "2. Salir" << endl;
        cin >> opcion;

        switch (opcion){ // Iniciar un switch para manejar las opciones
        case CORREO:
            cout << "Por favor, coloque el correo electronico: " << endl;
            cin >> correo;
            if (validadorDeCorreos.validarCorreo(correo) == true){ // Validar el correo electrónico
                cout << "El correo electronico cuenta con un formato correcto" << endl; // Mensaje si el correo es valido
            }
            else { 
                 cout << "El correo electronico NO cuenta con un formato correcto" << endl; // Mensaje si el correo es invalido
            }
            break;
      
        case SALIR:
             cout << "Saliendo del programa... \n" << endl;
             cout << "Muchas gracias por preferirnos!! \n" << endl;
            break;

        default:
            break;
        }
    }while(opcion != SALIR);

    return(0);
}
