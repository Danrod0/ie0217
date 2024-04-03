#include <iostream> 
#include <string> 
using namespace std;

// Se define la clase Animal
class Animal { 
    private:
        string color; // Atributo privado para almacenar el color del animal

    protected: 
        string type; // Atributo protegido para almacenar el tipo de animal

    public:
        // Métodos públicos para acciones que puede realizar el animal
        void run() { cout << "I can run -- BASE!" << endl; } 
        void eat() { cout << "I can eat!" << endl; }
        void sleep() { cout << "I can sleep!" << endl; } 
        
        // Métodos para establecer y obtener el color del animal
        void setColor(string clr) { color = clr; } 
        string getColor() { return color; }
};

// Definición de la clase Dog, que hereda de la clase Animal
class Dog : public Animal {
    public:
        // Método para correr, sobrescrito de la clase base
        void run() { cout << "I can run -- DERIVED!" << endl; } 
        
        // Método para establecer el tipo de perro
        void setType(string tp) { type = tp; }
        
        // Método para mostrar información sobre el perro, incluyendo su tipo y color
        void displayInfo(string c) {
            cout << "I am a " << type << endl;
            cout << "My color is " << c << endl;
        }
        
        // Método para ladrar
        void bark() { cout << "I can bark! Woof woof!!" << endl; }
};

int main() {
    Dog dog1; // Se crea un objeto de la clase Dog
    
    // Se llaman a los métodos de la clase Dog y de la clase Animal
    dog1.run(); // Método run() de la clase Dog
    dog1.eat(); // Método eat() de la clase Animal
    dog1.sleep(); // Método sleep() de la clase Animal
    dog1.setColor("black"); // Método setColor() de la clase Animal
    
    dog1.bark(); // Método bark() de la clase Dog
    dog1.setType("Doberman"); // Método setType() de la clase Dog
    dog1.displayInfo(dog1.getColor()); // Método displayInfo() de la clase Dog

    return 0;
}