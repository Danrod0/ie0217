#include <iostream>
#include "EmpleadoAsalariado.hpp" // Incluye la declaracion de la clase EmpleadoAsalariado
#include "EmpleadoPorHoras.hpp" // Incluye la declaracion de la clase EmpleadoPorHoras

int main() {
    // Se crean dos objetos, uno tipo EmpleadoAsalariado y otro EmpleadoPorHoras
    EmpleadoAsalariado emp1("Marito", 30, 2000); 
    EmpleadoPorHoras emp2("Juana", 25, 10, 40);

    // Imprime los datos relacionados a emp1, junto con su pago
    std::cout << "Detalles del empleado asalariado: " << std::endl;
    emp1.mostrarDetalles();
    std::cout << "Pago: $" << emp1.calcularPago() << std::endl;

    // Imprime los datos relacionados a emp2, junto con su pago
    std::cout << "\nDetalles del empleado por horas: " << std::endl;
    emp2.mostrarDetalles();
    std::cout << "Pago: $" << emp2.calcularPago() << std::endl;

    return 0;
}