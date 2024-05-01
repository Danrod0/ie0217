#include <iostream>

using namespace std;

// Clase template para almacenar un numero de cualquier tipo de datos
template <class T> 
class Number {     
    private:   

        // Variable tipo T
        T num;

    public:
        Number(T n) : num(n) {} 

        // Metodo para obtener el numero almacenado
        T getNum() {
            return num;
        }
};



int main() {

    // Creacion de instancias de la clase Number con diferentes tipos de datos, int y double
    Number<int> numberInt(7);
    Number<double> numberDouble (7.7);


    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;
    
    return 0;
}