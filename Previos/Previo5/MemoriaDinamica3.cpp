#include <iostream> 
using namespace std;

// Crea la clase Student
class Student { 
    // Define el atributo de la clase Student
    private: 
        int age;

    public:
        // Constructor que inicializa age en 12
        Student() : age(12) {}
        
        // Metodo para obtener la edad
        void getAge() {
            cout << "Age = " << age << endl;
        }
};

int main() {

    // Declaracion dinamica de un puntero Student
    Student* ptr = new Student();

    // Llama a la funcion getAge() del objeto
    ptr->getAge();

    // Libera la memoria asignada para el objeto
    delete ptr;

    return 0;
}