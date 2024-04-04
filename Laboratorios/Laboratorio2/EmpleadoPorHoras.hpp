#ifndef EMPLEADOPORHORAS_HPP
#define EMPLEADOPORHORAS_HPP

#include "Empleado.hpp" // Incluye la declaracion de la clase Empleado

class EmpleadoPorHoras : public Empleado { // Se declara la clase EmpleadoPorHoras que hereda de la clase Empleado
    private:
        int horasTrabajadas; // Se crea el atributo para guardar las hojas trabajadas

    public:
        // Se crea el constructor de la clase EmpleadoPorHoras, que inicia los atributos heredados junto con el propio
        EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int _horasTrabajadas);
        double calcularPago() const override; // Override para el metodo virtual
};


#endif // EMPLEADOPORHORAS_HPP