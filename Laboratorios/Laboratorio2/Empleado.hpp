#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

class Empleado { // Se declara la clase empleado
    protected: // Se establecen los atributos protegidos, solo la mimsa clase o las clases amigas pueden acceder
        std::string nombre;
        int edad;
        double salario;

    public: // Se establecen los metodos publicos

        Empleado(std::string _string, int _edad, double _salario); // Se crea el constructor de la clase empleado

        virtual ~Empleado(){} // Se crea el destructor

        /*
         Metodo virtual puro, significa que en todas las clases basadas en esta, este metodo debe existir
        */
        virtual double calcularPago() const = 0; 

        virtual void mostrarDetalles() const; // Se declara metodo virtual para mostrar los detalles del empleado
};



#endif // EMPLEADO_HPP