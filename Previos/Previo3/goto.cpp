#include <iostream> // Libreria
using namespace std; // Permite usar los elementos de std

int main()
{
    
    float num, average, sum = 0.0; // Crea 3 variables
    int i, n; // Crea las variables para controlar los bucles
    
    cout << "Maximum number of inputs: "; // Imprime en consola solicitando la cantidad de inputs
    cin >> n; // Asigna el valor ingresado por el usuario a la variable n
    
    for(i = 1; i <= n; ++i) // Bucle for para solicitar numeros al usuario
    {
        cout << "Enter n" << i << ": ";  // Solicita al usuario el numero
        cin >> num; // Asigna el valor ingresado en num
        
        if (num < 0.0) // si el numero es negativo salta ditecto a jump
        {
            goto jump;
        }
        sum += num; // Agrega el numero a la suma
    }

jump: // Etiqueta
    average = sum / (i - 1); // Calcula el promedio
    cout << "\nAverage = " << average; // Imprime en consola
    return 0;
}