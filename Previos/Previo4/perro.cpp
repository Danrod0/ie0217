#include <iostream> 
using namespace std;

// Se define la clase Animal
class Animal { 
public:
    // Método para que el animal coma
    void eat() {
        cout << "I can eat!" << endl;
    }

    // Método para que el animal duerma
    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// Se define la clase Dog que hereda de la clase Animal
class Dog : public Animal {
public:
    // Método para que el perro ladre
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    // Creación de un objeto de la clase Dog
    Dog dog1;

    // Llamada a métodos de la clase base Animal
    dog1.eat();
    dog1.sleep();

    // Llamada a método de la clase derivada Dog
    dog1.bark();

    return 0;
}