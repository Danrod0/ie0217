/**
 * @file  funciones.cpp
 * @brief En este archivo se definen las funciones
 * que fueron declaradas en el archivo funciones.hpp
 * las cuales tienen que ver con la seleccion del
 * operador
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 08/05/2024
 * 
 * Licencia: MIT
 */

#include "funciones.hpp" // Incluimos el archivo de encabezado que contiene las declaraciones de las funciones


/**
* @brief seleccionarOperacion permite al usuario elegir entre tres operadores para 
* operaciones de matrices: suma, resta y multiplicación. Solicita la entrada del usuario 
* y devuelve el operador seleccionado si es valido, lanzando una excepcion si no lo es. 
* Si no se selecciona un operador valido, devuelve un valor predeterminado.
* 
*/

// Se define la funcion para seleccionar un operador
std::string seleccionarOperacion(){ 
    // Definimos un vector de operadores validos por defecto
    std::vector<std::string> operadoresDefault = {"+","-","*"};
    std::string operador; // Variable para almacenar el operador seleccionado por el usuario

    // Solicitamos al usuario que ingrese el operador a utilizar
    std::cout << "Ingrese el operador que va a utilizar" << std::endl;
    std::cout << "Ingrese \"+\" para sumar matrices" << std::endl;
    std::cout << "Ingrese \"-\" para restar matrices" << std::endl;
    std::cout << "Ingrese \"*\" para multiplicar matrices" << std::endl;
    std::cout << "Ingrese el operador a utilizar: ";
    std::cin >> operador;

    // Verificamos si el operador seleccionado por el usuario es valido
    if (operador == "+"){ 
        std::cout << "Usted selecciono realizar suma de matrices" << std::endl;
        std::cout << std::endl;
        return operador;
    }

    else if (operador == "-"){ 
        std::cout << "Usted selecciono realizar resta de matrices" << std::endl;
        std::cout << std::endl;
        return operador;
    }

    else if (operador == "*"){ 
        std::cout << "Usted selecciono realizar multiplicación de matrices" << std::endl;
        std::cout << std::endl;
        return operador;
    }

    else if (std::cin.fail() || (std::find(operadoresDefault.begin(), operadoresDefault.end(), operador) == operadoresDefault.end())) {
        // Si la entrada del usuario no coincide con ningun operador valido, lanzamos una excepcion
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("Por favor introducir un operador permitido (+,-,*)");   
    }
    return "Default"; // Devolvemos un valor predeterminado en caso de que no se haya seleccionado un operador valido
}
