#include <iostream>
using namespace std;

// Clase template con multiples tipos de datos, donde el tercer tipo de dato tiene un valor predeterminado
template <class T, class U, class V = char>
class ClassTemplate {
    private: 
        T var1;
        U var2;
        V var3;

    public:
        ClassTemplate (T v1, U v2, V v3): var1(v1), var2(v2), var3(v3) {}

        // Metodo para imprimir los valores de las variables miembro
        void printVar() {
            cout << "var1 = " << var1 << endl;
            cout << "var2 = " << var2 << endl;
            cout << "var3 = " << var3 << endl;
        }
};

int main() {

    // Crear una instancia de la clase ClassTemplate con tipos de datos int, double y char
    ClassTemplate<int, double> obj1(7, 7.7, 'c'); 
    cout << "obj1 values: " << endl;
    obj1.printVar();

    // Crear una instancia de la clase ClassTemplate con tipos de datos int, char y bool
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false); 
    cout << "\nobj2 values: " << endl;
    obj2.printVar();
    return 0;
}