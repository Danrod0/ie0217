#include "clases.hpp"

std::string ValidarEntrada::validarDatos(std::string input){ 
   
    if (input == "enteros") {
            return "int";
    } 
        
    else if (input == "flotantes") {
        return "float";
    } 
        
    else if (input == "complejos") {
        return "std::complex";
    } 
  
    else {
        throw std::invalid_argument("Tipo de dato invalido");
    }


}

void ValidarEntrada::validarTamanio(int tamanio){ 
   
    if (tamanio  <= 0 ) {
          throw ("\nEl tamanio de la matriz no puede tener valores negativos o cero\n");  
    } 
        
}