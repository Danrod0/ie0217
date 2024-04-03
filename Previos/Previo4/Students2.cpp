#include <iostream> 
using namespace std;

// Se define la clase Student
class Student { 
public:
    double marks1, marks2; // Variables miembro para almacenar las calificaciones
};

// Se crea la funcion para crear un objeto Student y establecer sus calificaciones
Student createStudent() { 
    // Se crea un objeto Student
    Student student;

    // Se dan las calificaciones del estudiante
    student.marks1 = 96.5; 
    student.marks2 = 75.0;

    // Se imprimen las calificaciones establecidas
    cout << "Marks 1 = " << student.marks1 << endl; 
    cout << "Marks 2 = " << student.marks2 << endl;

    // Se devuelve el objeto Student creado
    return student;
};

int main() {
    Student student1; // Se declara un objeto Student

    // Se llama a la función createStudent para inicializar el objeto student1 con las calificaciones
    student1 = createStudent();

    return 0;
}