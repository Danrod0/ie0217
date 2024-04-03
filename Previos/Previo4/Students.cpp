#include <iostream> 
using namespace std;

// Se define la clase Student
class Student {
public:
    double marks; // Variable miembro para almacenar las calificaciones del estudiante

    // Constructor que inicializa las calificaciones del estudiante
    Student(double m) {
        marks = m;
    }
};

// Se crea la funcion para calcular el promedio de las calificaciones de dos estudiantes
void calculateAverage(Student s1, Student s2) {
    double average = (s1.marks + s2.marks) / 2; // Se calcula el promedio de las calificaciones

    // Se imprime el promedio de las calificaciones
    cout << "Average Marks = " << average << endl;
}

int main() {
    // Se crean dos objetos de la clase Student con diferentes calificaciones
    Student student1(88.0), student2(56.0);

    // Se llama a la función para calcular el promedio de las calificaciones de los estudiantes
    calculateAverage(student1, student2);

    return 0;
}