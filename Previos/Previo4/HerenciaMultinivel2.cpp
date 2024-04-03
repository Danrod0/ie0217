#include <iostream> 
using namespace std;

class Mammal { 
    public:
        Mammal() {
            cout << "Mammals can give direct birth." << endl; // Mensaje de la clase Mammal
        }
};

class WingedAnimal { 
    public:
        WingedAnimal() {
            cout << "Winged animal can flap." << endl; // Mensaje de la clase WingedAnimal
        }
};

class Bat : public Mammal, public WingedAnimal {}; // Clase Bat hereda de Mammal y WingedAnimal

int main() {
    Bat b1; // Se crea un objeto de la clase Bat
    return 0;
}