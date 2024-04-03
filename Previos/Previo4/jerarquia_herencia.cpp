#include <iostream> 
using namespace std;

class Animal {
    public:
        void info() { cout << "I am an animal." << endl; } // Se crea la funcion miembro de la clase base
};

class Dog : public Animal {
    public:
        void bark() { cout << "I am a Dog. Woof woof." << endl; } // Se crea la funcion miembro de la clase derivada Dog
};

class Cat : public Animal {
    public:
        void meow() { cout << "I am a Cat. Meow." << endl; } // Se crea la funcion miembro de la clase derivada Cat
};

int main() {
    // Se crea un objeto de la clase Dog
    Dog dog1;
    cout << "Dog Class: " << endl;
    dog1.info(); // Se llama a la función miembro de la clase base 
    dog1.bark();

    // Se crea un objeto de la clase Cat
    Cat cat1;
    cout << "\nCat Class: " << endl;
    cat1.info(); // Se llama a la función miembro de la clase base 
    cat1.meow();

    return 0;
}