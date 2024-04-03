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
    Derived derived1; // Se crea un objeto de la clase Derived
    derived1.print(); // Se llama al método print() de la clase Derived
    return 0;
}