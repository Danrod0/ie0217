#include <iostream> // Libreria
using namespace std; // Para poder llamar a todo lo que incluye std

int main() {
    int num;
    
    cout << "Enter an integer: ";
    cin >> num; // Lee el número ingresado por el usuario

    // Condición if externa
    if (num != 0) {
        
        // Condición if interna
        if (num > 0) {
            cout << "The number is positive." << endl;
        }
        // Condición else interna
        else {
            cout << "The number is negative." << endl;
        }
    }
    // Condición else externa
    else {
        cout << "The number is 0 and it is neither positive nor negative." << endl;
    }
    
    cout << "This line is always printed." << endl; // Imprime esta línea siempre, ya que esta fuera de los if
    
    return 0;
}