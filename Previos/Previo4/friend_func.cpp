#include <iostream> 
using namespace std;

class Distance { 
    private:
        int meter;
        
        // Se declara una función friend para acceder al miembro privado meter
        friend int addFive(Distance);

    public:
        // Constructor para inicializar meter en 0
        Distance() : meter(0) {}
};

// Se define la función friend para agregar 5, o sumar 5, al miembro privado meter de Distance
int addFive(Distance d) {
    // Se accede a miembros privados de la clase Distance desde la función friend
    d.meter += 5;
    return d.meter;
};

int main() {
    Distance D; // Se crea un objeto de la clase Distance
    cout << "Distancia: " << addFive(D); // Se llama a la función addFive y se muestra el resultado
    return 0;
}