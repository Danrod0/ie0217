#ifndef EMPLEADOASALARIADO_HPP
#define EMPLEADOASALARIADO_HPP

#include "Empleado.hpp" // Incluye la declaración de la clase base Empleado

class EmpleadoAsalariado : public Empleado{ // Se define la clase EmpleadoAsalariado que hereda de Empleado

    public:
        EmpleadoAsalariado(std::string _nombre, int _edad, double _salario); // Se crea el constructor que inicializa los atributos de la clase base
        double calcularPago() const override; // Override para definir el metodo virtual puro
        
};


#endif // EMPLEADOASALARIADO_HPP