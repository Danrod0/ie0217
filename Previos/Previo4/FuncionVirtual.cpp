#include <iostream> 
using namespace std;

class Base {
    public:
        // Función virtual
        virtual void print() {
            cout << "Base Function" << endl;
        }
};

class Derived : public Base {
    public:
        // Anula la función print() de la clase Base
        void print() {
            cout << "Derived Function" << endl;
        }
};

int main() {
    Derived derived1; // Se crea un objeto de la clase Derived

    // Se crea un puntero de tipo Base que apunta al objeto derived1 
    Base* base1 = &derived1;
    
    // Se llama a la función print() a través del puntero base1
    base1->print();

    return 0;
}