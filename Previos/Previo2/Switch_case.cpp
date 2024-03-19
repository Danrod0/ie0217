#include <iostream> // Libreria
using namespace std; // Para poder llamar a todo lo que incluye std

int main() { 
    char oper;
    float num1, num2;
    cout << "Enter an operator (+, -, *, /): "; // Solicita al usuario que ingrese un operador
    cin >> oper;
    cout << "Enter two numbers: " << endl; // Solicita al usuario que ingrese dos numeros
    cin >> num1 >> num2;
    
    // Switch para realizar la operación correspondiente según el operador ingresado por el usuario
    switch (oper) {
        case '+': // oper == +
            cout << num1<< " + " << num2 << " = " << num1 + num2;
            break;
        case '-': // oper == -
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*': // oper == *
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/': // oper == /
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
        // Si el operador no coincide con ninguno de los casos anteriores
        cout << "Error! The operator is not correct";
        break;
    }
    
    return 0;
}