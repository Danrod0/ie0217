#include "Email.hpp"

#include <iostream>

using namespace std;

enum opciones  { 
    CORREO = 1,
    SALIR
}; 

int main(){ 

    int opcion;

    ValidadorEmail validadorDeCorreos;
    
    string correo;

    cout << "Bienvenido a nuestro validador de correos" << endl;

    do{ 
        cout << "Por favor, seleccione una opcion." << endl;
        cout << "1. Ingresar correo electronico a validar" << endl;
        cout << "2. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case CORREO:
            cout << "Por favor, coloque el correo electronico: " << endl;
            cin >> correo;
            cout << "Correo ingresado correctamente" << endl;
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
