#include <iostream> 
using namespace std;

class Molde {
    public:
        double largo;
        double ancho;
        double alto;

        // Constructor que inicializa las dimensiones del molde
        Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {
            cout << "Probando si se puede imprimir" << endl;
        }

        // Destructor que se llama al finalizar el alcance del objeto
        ~Molde() {
            cout << "Saludos desde el destructor de la clase Molde" << endl;
        }

        // Función miembro para calcular el área de la base del molde
        double calcularArea() {
            return largo * ancho;
        }

        // Función miembro para calcular el volumen del molde
        double calcularVolumen () {
            return largo * ancho * alto;
        }
};

int main() {
    int variable_entera; // Se define una variable entera

    // Se crea un objeto de la clase Molde con dimensiones específicas
    Molde pared(10.0, 20.0, 35.0);

    /* Se calcula y se imprimen en consola el area y volumen. */
    cout << "El area es: " << pared.calcularArea() << endl; // Se llama a la función miembro para calcular el área
    cout << "El volumen es: " << pared.calcularVolumen () << endl; // Se llama a la función miembro para calcular el volumen

    return 0;
}