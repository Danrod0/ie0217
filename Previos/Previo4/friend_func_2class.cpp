#include <iostream> 
using namespace std;

class ClassB; // Se declara de manera anticipada la ClassB para permitir su uso en ClassA

class ClassA { 
    public:
        // Constructor para inicializar numA en 12
        ClassA() : numA(12) {}
    private:
        int numA; 
        // Se declara una función friend para acceder a los miembros privados de ClassB
        friend int add(ClassA, ClassB);
};

class ClassB {
    public:
        // Constructor para inicializar numB en 1
        ClassB() : numB(1) {}
    private:
        int numB;
        // Se declara una función friend para acceder a los miembros privados de ClassA
        friend int add(ClassA, ClassB);
};

// Se define la función friend para sumar los miembros privados de ClassA y ClassB
int add(ClassA objectA, ClassB objectB) { 
    return (objectA.numA + objectB.numB); // Acceso a los miembros privados de ambas clases
}

int main() {
    ClassA objectA; // Se crea un objeto de ClassA
    ClassB objectB; // Se crea un objeto de ClassB
    cout << "Suma: " << add(objectA, objectB); // Se llama a la función add y se muestra el resultado
    return 0;
}
