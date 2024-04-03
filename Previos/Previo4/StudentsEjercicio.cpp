#include "StudentsEjercicio.hpp" // Incluye el archivo de encabezado de la clase Student

#include <iostream>

// Se implementa el constructor de la clase Student
Student::Student(double m) {
    marks = m; // Se inicia la variable marks con el valor pasado como argumento
}

// Se crea la funcion para calcular el promedio de las calificaciones de dos estudiantes
void calculateAverage(Student s1, Student s2) {
    // Se calcula el promedio de las calificaciones de los estudiantes s1 y s2
    double average = (s1.marks + s2.marks) / 2;

    // Se imprime el promedio de las calificaciones
    std::cout << "Average Marks = " << average << std::endl;
}