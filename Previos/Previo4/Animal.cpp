#include <iostream> 
using namespace std;

class Animal {

    /*
    Se crea una clase animal, la cual cuenta con dos atributos
    edad y nombre, y dos metodos, setEdad y getEdad. Siendo
    edad privado, por lo que solo puede ser accesado desde
    animal.
    */

    public:
        void setEdad(int age) {
            edad = age;
        }
        int getEdad() {
            return edad;
        }

    protected:
        string nombre;

    private:
        int edad;
};

class Perro : public Animal {

    /*
    Se crea una clase perro, la cual hereda de la clase
    animal. Contando con dos atributos, setNombre y
    getNombre.
    */

    public:
        void setNombre(string n) { 
            nombre = n;
        }
        string getNombre() {
            return nombre;
        }
};

int main() {
    
    /*
    Se crea un objeto miPerro de la clase Perro. Se llama 
    a los métodos setNombre() y setEdad() para establecer 
    el nombre y la edad del perro. Luego, se llama a los 
    métodos getNombre() y getEdad() para obtener y mostrar 
    el nombre y la edad del perro.
    */
    
    Perro miPerro;
    miPerro.setNombre("Toby"); 
    miPerro.setEdad(3);

    cout << "Mi perro se llama " << miPerro.getNombre() << endl; 
    cout << "y tiene " << miPerro.getEdad() << " anios." << endl;

    return 0;
}