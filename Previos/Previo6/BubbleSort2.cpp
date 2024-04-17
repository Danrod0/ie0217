// Optimized-bubble sort in C++ 
#include <iostream>
using namespace std;

// Función para realizar el ordenamiento de burbuja
void bubbleSort(int array[], int size) {
    
    // Bucle para acceder a cada elemento del arreglo
    for (int step = 0; step < (size-1); ++step) {
    
        // Variable que se utiliza para verificar si se produjo un intercambio
        int swapped = 0;

        // Bucle para comparar dos elementos
        for (int i = 0; i < (size-step-1); ++i) {
            
            // Compara dos elementos adyacentes
            // Cambia > a < para ordenar en orden descendente
            if (array[i] > array[i+1]) {
                
                // Se produce el intercambio si los elementos
                // no están en el orden deseado
                int temp = array[i];
                array[i] = array[i + 1]; 
                array[i + 1] = temp;

                swapped = 1; // Cambia el valor de la variable para marvar que se ha realizado un intercambio
            }
        }

        // Si no se produce ningún intercambio, significa que el arreglo ya está ordenado
        // por lo que no es necesario realizar más comparaciones
        if (swapped == 0)
            break;
    }
}

// Función para imprimir un arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -9};

    // Encuentra la longitud del arreglo
    int size = sizeof(data) / sizeof(data[0]);

    // Ordena el arreglo usando el algoritmo de burbuja
    bubbleSort(data, size);
    
    cout << "Sorted Array in Ascending Order: \n"; 
    printArray(data, size);
}