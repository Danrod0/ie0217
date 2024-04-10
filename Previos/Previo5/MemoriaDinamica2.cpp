#include <iostream> 
using namespace std;

int main() {
    
    int num;
    cout << "Enter total number of students: ";
    cin >> num;

    // Se crea el puntero que apunta a un flotante
    float* ptr;

    // Asignación de memoria dinamica para 'num' números flotantes
    ptr = new float[num];

    cout << "Enter GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student" << i + 1 << ": ";
        cin >> *(ptr + i); // Se ingresan las calificaciones y se almacenan en el arreglo
    }

    cout << "\nDisplaying GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student" << i + 1 << ": " << *(ptr + i) << endl; // Se muestra cada calificación ingresada
    }

    // Se libera la memoria asignada para el arreglo
    delete[] ptr;
    
    return 0;
}