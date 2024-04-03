#include <iostream> 
using namespace std;

class ClassB; // Se declara de manera anticipada ClassB para permitir su uso en ClassA

class ClassA { 
    private: 
        int numA;

        // Declaracion fiend con ClassB
        friend class ClassB;
    
    public:
        // Constructor para inicializar numA en 12 
        ClassA() : numA(12) {}
};

class ClassB {
    private:
        int numB;

    public:
        // Constructor para inicializar numB en 1 
        ClassB() : numB(1) {}

        // Funcion miembro para sumar numA de ClassA y numB de ClassB 
        int add() {
            ClassA objectA;
            return objectA.numA + numB; // Se accede a numA de ClassA, por el comando friend, y se suma con numB de ClassB
        }
};

int main() {
    ClassB objectB;
    cout << "Sum: " << objectB.add(); // Se llama a la función add() de ClassB y se muestra el resultado
    return 0;
}
