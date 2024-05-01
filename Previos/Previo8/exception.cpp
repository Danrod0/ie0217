#include <iostream> 
#include <stdexcept>
using namespace std;


int main() {

    int numerador, denominador, resultado;
    
    // Se solicita al usuario el numerador y el denominador
    cout << "Ingrese el numerador: "; 
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try {
        // Se verifica si el denominador es cero
        if (denominador == 0) {
            // Se lanza una excepcion de tipo runtime_error
            throw runtime_error("Error: el denominador no puede ser cero.");
        }

        // Se calcula el resultado de la division
        resultado = numerador / denominador;
        cout<<"El resultado es: " << resultado << endl;
    }   
    
    // Se captura la excepcion
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
