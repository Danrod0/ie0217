#include <iostream> 
using namespace std;

class A {
    public:
        void display() {
            cout<<"Base class content."; // Imprime el contenido de la clase base
        }
};

class B : public A {}; // Clase B hereda de clase A

class C : public B {}; // Clase C hereda de clase B

int main() { 
    C obj; // Se crea un objeto de la clase C
    obj.display(); // Se llama al método display()
    return 0;
}