#include "EmpleadoPorHoras.hpp" // Incluye la declaracion de la clase EmpleadoPorHoras

// Se implementa el constructor de EmpleadoPorHoras, se inician los atributos heredados
EmpleadoPorHoras::EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int _horasTrabajadas)
    : Empleado(_nombre, _edad, _salario), horasTrabajadas(_horasTrabajadas) {} // Se llama al constructor de la clase base y las horas trabajadas

// Se implementa el metodo calcularPago
double EmpleadoPorHoras::calcularPago() const{
    return salario * horasTrabajadas; // Devuelve la multiplicacion del salario por las horas trabajadas
}