#include <iostream> 
using namespace std;

// Se define la clase Base
class Base { 
    public:
        // Método print de la clase Base
        void print() {
            cout << "Base Function" << endl;
        }
};

// Se define la clase Derived, que hereda de la clase Base
class Derived : public Base {
    public:
        // Método print de la clase Derived, que sobrescribe el método de la clase Base
        void print() {
            cout << "Derived Function" << endl;
        }
};

int main() {
    Derived derived1, derived2; // Se crean de dos objetos de la clase Derived
    derived1.print(); // Se llama al método print() de la clase Derived para el objeto derived1

    // Acceso al método print() de la clase Base mediante la clase base
    derived2.Base::print();

    return 0;
}