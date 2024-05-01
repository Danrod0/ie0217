#include <iostream>
using namespace std;

int main() {
    double numerator, denominator, divide;

    // Solicitar al usuario el numerador
    cout << "Enter numerator: ";
    cin >> numerator;

    // Solicitar al usuario el denominador
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        // Verificar si el denominador es cero
        if (denominator == 0)
            throw 0; // Lanzar una excepcion de tipo entero si el denominador es cero

        // Realizar la division si el denominador no es cero
        divide = numerator / denominator;
        cout << numerator << " / " << denominator << " = " << divide << endl;
    }

    // Se captura la excepcion de tipo entero que se lanza cuando el denominador es cero
    catch (int num_exception) {
        cout << "Error: Cannot divide by " << num_exception << endl;
    }
    
    return 0;
}