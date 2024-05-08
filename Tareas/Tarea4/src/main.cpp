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

Matriz<int> matrizInt1;
Matriz<float> matrizFloat1;
Matriz<std::complex<float>> matrizComplex1;
Matriz<int> matrizInt2;
Matriz<float> matrizFloat2;
Matriz<std::complex<float>> matrizComplex2;

int main(){ 

    ValidarEntrada verificador;

    int opcion;
    std::string tipoDato;
    std::string datoVerificado = "int";
    int filas1;
    int columnas1;
    int filas2;
    int columnas2;

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

                cout << "\n Por favor ingrese la cantidad de filas de la matriz 1: ";
            cin >> filas1;

            try{ 
                verificador.validarTamanio(filas1);       
            }
            catch (const char* msg){
            cout << msg << endl;
            break;
            }

            cout << "\n Por favor ingrese la cantidad de columnas de la matriz 1: ";
            cin >> columnas1;

            try{ 
                    verificador.validarTamanio(columnas1);        
            }    
            catch (const char* msg){
            cout << msg << endl;
            break;
            }

            try{ 
                if (datoVerificado == "int"){
                    matrizInt1 = Matriz<int>(filas1, columnas1, datoVerificado);    
                }    

                else if  (datoVerificado == "float"){
                    matrizFloat1 = Matriz<float>(filas1, columnas1, datoVerificado);    
                }    

                else if  (datoVerificado ==  "std::complex"){
                   matrizComplex1 = Matriz<std::complex<float>>(filas1, columnas1, datoVerificado);    
                }  
            }           
            catch (const std::invalid_argument& e){
            std::cerr << "Error: " << e.what() << '\n';
            break;
            }

            cout << "\n Por favor ingrese la cantidad de filas de la matriz 2: ";
            cin >> filas2;

            try{ 
                    verificador.validarTamanio(filas2);        
            }       
            catch (const char* msg){
            cout << msg << endl;
            break;
            }

            cout << "\n Por favor ingrese la cantidad de columnas de la matriz 2: ";
            cin >> columnas2;

            try{ 
                    verificador.validarTamanio(columnas2);        
            }  
            catch (const char* msg){
            cout << msg << endl;
            break;
            }

            try{ 
                if (datoVerificado == "int"){
                    matrizInt2 = Matriz<int>(filas2, columnas2, datoVerificado);    
                }    

                else if  (datoVerificado == "float"){
                    matrizFloat2 = Matriz<float>(filas2, columnas2, datoVerificado);    
                }    

                else if  (datoVerificado ==  "std::complex"){
                    matrizComplex2 = Matriz<std::complex<float>>(filas2, columnas2, datoVerificado);    
                }  
            }   
             catch (const std::invalid_argument& e){
                std::cerr << "Error: " << e.what() << '\n';
                break;
            }

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