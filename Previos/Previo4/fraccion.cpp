#include <iostream> 
using namespace std;

class Fraccion {
    int numerador, denominador;
    public:
        // Constructor para inicializar la fraccion con el numerador y el denominador
        Fraccion(int n, int d) : numerador(n), denominador(d) {}

        // Se hace la sobrecarga del operador de suma
        Fraccion operator+ (const Fraccion &f) {
            // Se calcula la suma de las fracciones
            Fraccion resultado(
                numerador * f.denominador + f.numerador * denominador, 
                denominador * f.denominador
            );
            return resultado;
        }
        
        // Se imprime la fraccion en la consola
        void imprimir() {
            cout << numerador << "/" << denominador << endl;
        }
};

int main() {

    // Se crean dos objetos tipo fraccion
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);
    
    // Se suman las fracciones
    Fraccion f3 = f1 + f2;
    
    // Se imprime el resultado de la suma
    f3.imprimir();

    return 0;
}