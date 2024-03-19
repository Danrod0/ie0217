// Program to compute absolute value 
// Works for both int and float

#include <iostream> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

// Funcion con un parametro tipo flotante
float absolute (float var){
    if (var < 0.0)
        var = -var;
    return var;
}

// Funcion con un parametro tipo entero
int absolute(int var) {
    if (var < 0)
        var = -var;
    return var;
}

int main() {
    // Llama a la función para números enteros y muestra el resultado
    cout << "Absolute value of -5 = " << absolute(-5) << endl;
    
    // Llama a la función para números de punto flotante y muestra el resultado
    cout << "Absolute value of 5.5 = " << absolute(5.5f) << endl; 
    return 0;
}