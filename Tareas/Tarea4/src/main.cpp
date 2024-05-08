#include <iostream>
#include "clases.hpp"
#include "funciones.hpp"

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
OperacionesBasicas<int> operadorInt;
OperacionesBasicas<float> operadorFloat;
OperacionesBasicas<std::complex<float>> operadorComplex;

int main(){ 

    ValidarEntrada verificador;

    int opcion;

    
    std::string tipoDato;
    std::string datoVerificado = "int";
    int filas1;
    int columnas1;
    int filas2;
    int columnas2;
    std::string operadorVerificado = "+";

    do{ 

        cout << "Bienvenido a la calculadora de matrices!!" << endl << endl;
        cout << "Por favor seleccione una opcion de nuestro menu" << endl;
        cout << "1. Generar matrices manualmente (seleccionar dimensiones e ingresar valores)" << endl;
        cout << "2. Seleccionar el tipo de datos de la matriz (Default: enteros)." << endl;
        cout << "3. Seleccionar la operacion a realizar." << endl;
        cout << "4. Llenar las matrices con datos aleatorios (debe usar primero la opcion 1, seguidamente este para su correcto funcionamiento)." << endl;
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

            cout << "\n Tipos de datos compatibles con el programa: \nenteros, flotantes y complejos\n" << endl;
            cout << "Seleccione el tipo de dato deseado (ingrese una de las opciones anteriormente nombradas): ";
            cin >> tipoDato;

            try{ 
                datoVerificado = verificador.validarDatos(tipoDato);
            }

            catch(const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << '\n';
                break;
            }
            cout << datoVerificado << endl;
            break;

        case SELECCION_OPERACION: 

            try{
                operadorVerificado = seleccionarOperacion();
            }
            catch(const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << '\n';
                cout << endl;
                break;
            }
            
            break;
        
        case DATOS_ALEATORIOS:

            cout << "Se llenaran las matrices con datos aleatorios \n" << endl;
            if (datoVerificado == "int"){
                    matrizInt1.llenarMatrizRandom();    
                    matrizInt2.llenarMatrizRandom();
                }    

                else if  (datoVerificado == "float"){
                    matrizFloat1.llenarMatrizRandom();    
                    matrizComplex2.llenarMatrizRandom();
                }    

                else if  (datoVerificado ==  "std::complex"){
                   matrizComplex1.llenarMatrizRandom();
                   matrizComplex2.llenarMatrizRandom();    
                }  

            break;

        case IMPRIMIR_MATRICES:

            cout << "Se imprimiran las matrices guardadas en el sistema " << endl;

            if (datoVerificado == "int"){ 
                cout << "Matriz 1 " << endl;
                matrizInt1.imprimirMatriz();
                cout << endl;
                cout << "\nMatriz 2 " << endl;
                matrizInt2.imprimirMatriz();
            } 
            
            else if (datoVerificado == "float"){ 
                cout << "Matriz 1 " << endl;
                matrizFloat1.imprimirMatriz();
                cout << endl;
                cout << "\nMatriz 2 " << endl;
                matrizFloat2.imprimirMatriz();
            } 
            
            else if (datoVerificado == "std::complex"){ 
                cout << "Matriz 1 " << endl;
                matrizComplex1.imprimirMatriz();
                cout << endl;
                cout << "\nMatriz 2 " << endl;
                matrizComplex2.imprimirMatriz();
            } 

            break;

        case REALIZAR_OPERACION:

            cout << "Se realizara la operacion seleccionada \n" << endl;

            if (operadorVerificado == "+"){  
                if (datoVerificado == "int"){ 
                    try{ 
                        matrizInt1 + matrizInt2;
                    }
                   catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }                    
                } 
                               
                else if (datoVerificado == "float"){ 
                    try{
                        matrizFloat1 + matrizFloat2;
                    }
                    catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    } 
                } 

                else if (datoVerificado == "std::complex"){ 
                    try{
                        matrizComplex1 + matrizComplex2;
                    }
                   catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }
                } 
            }
            
            if (operadorVerificado == "-"){  
                if (datoVerificado == "int"){ 
                    try{
                        matrizInt1 - matrizInt2;
                    }
                   catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }
                } 

                else if (datoVerificado == "float"){ 
                    try{
                        matrizFloat1 - matrizFloat2;
                    } 
                    catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }
                } 

                else if (datoVerificado == "std::complex"){ 
                    try{
                        matrizComplex1 - matrizComplex2;
                    }
                   catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }
                } 
            }
            
            if (operadorVerificado == "*"){  
                if (datoVerificado == "int"){ 
                    try{
                        matrizInt1 * matrizInt2;
                    }
                   catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }
                } 

                else if (datoVerificado == "float"){ 
                    try{
                        matrizFloat1 * matrizFloat2;
                    }
                    catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }
                } 

                else if (datoVerificado == "std::complex"){ 
                    try{
                        matrizComplex1 * matrizComplex2;
                    } catch(const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                        break;
                    }  
                } 
            }
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