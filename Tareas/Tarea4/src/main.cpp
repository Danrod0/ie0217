#include <iostream>

using namespace std;

enum opciones  { 

    GENERAR_MATRIZ = 1,
    DATOS,
    SELECCION_OPERACION,
    DATOS_ALEATORIOS,
    IMPRIMIR_MATRICES,
    REALIZAR_OPERACION,
    SALIR

}; 


int main(){ 

    int opcion;

    do{ 

        cout << "Bienvenido a la calculadora de matrices!!" << endl << endl;
        cout << "Por favor seleccione una opcion de nuestro menu" << endl;
        cout << "1. Generar matrices manualmente." << endl;
        cout << "2. Seleccionar el tipo de datos de la matriz." << endl;
        cout << "3. Seleccionar la operacion a realizar." << endl;
        cout << "4. Llenar las matrices con datos aleatorios." << endl;
        cout << "5. Imprimir las matrices ingresadas." << endl;
        cout << "6. Realizar la operacion seleccionada." << endl;
        cout << "7. Salir." << endl << endl;
        cout << "Ingrese su opcion: " << endl;
        cin >> opcion;

        switch (opcion) {

        case GENERAR_MATRIZ:

            break;
        
        case DATOS:

            break;

        case SELECCION_OPERACION: 
            
            break;
        
        case DATOS_ALEATORIOS:

            break;

        case IMPRIMIR_MATRICES:

            break;

        case REALIZAR_OPERACION:

            break;

        case SALIR:
             cout << "Saliendo del programa... Muchas gracias por elegirnos \n" << endl;
            break;

        default:

            break;
        }
    }while(opcion != SALIR);

    return(0);
}