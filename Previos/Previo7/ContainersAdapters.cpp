#include <iostream> 
#include <stack> // Incluye la liberia stack
using namespace std;

int main() {

    // Crea una pila de enteros
    stack<int> numbers;

    // Inserta elementos en la pila
    numbers.push(1); 
    numbers.push(100); 
    numbers.push(10);
    
    cout << "Numbers are: ";

    // Accede a los elementos sacando y mostrando el elemento superior
    // hasta que la pila esté vacia
    while(!numbers.empty()) { 
        // Muestra el elemento superior
        cout << numbers.top() << ", ";

        // Saca el elemento superior de la pila
        numbers.pop();
    }

    return 0;
}