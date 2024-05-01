#include <iostream>
using namespace std;

int main(){ 
    
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;

    // Solicitar al usuario el indice del array
    cout << "Enter array index: ";
    cin >> index;

    try { 
        
        // Se verifica si el indice esta dentro de los limites del array
        if (index >= 4)
            throw "Error: Array out of bounds!";

        // Solicitar al usuario el numerador y el denominador
        cout << "Enter numerator: ";
        cin >> numerator;

        cout << "Enter denominator: ";
        cin >> denominator;

        // Se verifica si el denominador es cero
        if(denominator == 0)
            throw 0;

        // Realizar la division y asignar el resultado al indice del array
        arr[index] = numerator / denominator;
        cout << arr[index] << endl;

    }

    // Se capturan las excepciones
    catch (const char* msg){
        cout << msg << endl;
    }

    catch (int num){
        cout << "Error: Cannot divide by " << num << endl;
    }

    catch (...){
        cout << "Unexpected exception " << endl;
    }

    return 0;
}