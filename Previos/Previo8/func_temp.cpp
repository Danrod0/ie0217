#include <iostream>

using namespace std;

// Funcion de template para sumar dos numeros de cualquier tipo de datos
template <typename T>
T add(T num1,T num2){ 

    return(num1 + num2);
}


int main() {

    int result1; 
    double result2;

    // Llamando a los parametros con int
    result1= add<int>(2, 3);
    cout << "2 + 3 = "<< result1 << endl;

    // LLamando a los parametros con double
    result2 = add<double> (2.2, 3.3); 
    cout << "2.2 + 3.3 = "<< result2 << endl;

    return 0;
}