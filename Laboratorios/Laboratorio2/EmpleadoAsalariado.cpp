#include "EmpleadoAsalariado.hpp" // Incluye la declaracion de la clase EmpleadoAsalariado

// Se implementa el constructor de EmpleadoAsalariado, inicializando los atributos heredados
EmpleadoAsalariado::EmpleadoAsalariado(std::string _nombre, int _edad, double _salario)
    : Empleado (_nombre, _edad, _salario) {} // Se llama al constructor de la clase base

double EmpleadoAsalariado::calcularPago() const { // Implementacion del metodo calculaPago
    return salario; // Devuelve el atributo sin modificaciones
}
