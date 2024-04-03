#include "StudentsEjercicio.hpp" // Incluye el archivo de encabezado StudentsEjercicio.hpp

int main() {
    // Crea dos objetos de la clase Student, student1 y student2, con las calificaciones 88.0 y 56.0 respectivamente
    Student student1(88.0), student2(56.0);

    // Llama a la función calculateAverage pasando los objetos student1 y student2 como argumentos
    calculateAverage(student1, student2);

    return 0;
}