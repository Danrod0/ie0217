#include "funciones.hpp"

std::string seleccionarOperacion(){ 

    std::vector<std::string> operadoresDefault = {"+","-","*"};
    std::string operador;

    std::cout << "Ingrese el operador que va a utilizar" << std::endl;
    std::cout << "Ingrese \"+\" para sumar matrices" << std::endl;
    std::cout << "Ingrese \"-\" para restar matrices" << std::endl;
    std::cout << "Ingrese \"*\" para multiplicar matrices" << std::endl;
    std::cout << "Ingrese el operador a utilizar: ";
    std::cin >> operador;

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

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("Por favor introducir un operador permitido (+,-,*)");   
    }
    return "Default";
}
