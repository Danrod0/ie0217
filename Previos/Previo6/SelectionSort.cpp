// Selection sort in C++

#include <iostream>
using namespace std;

// Función para intercambiar la posición de dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para imprimir un arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para implementar el algoritmo de Selection Sort
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) { 
        // Encuentra el índice del mínimo elemento en cada iteración
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // Compara los elementos para encontrar el mínimo
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        
        // Coloca el mínimo en la posición correcta intercambiándolo con el elemento en el índice actual
        swap(&array[min_idx], &array[step]);
    }
}

// driver code
int main() {
    int data[] = {20, 12, 10, 15, 2};

    // Encuentra la longitud del arreglo
    int size = sizeof(data) / sizeof(data[0]);

    // Aplica el algoritmo de Selection Sort
    selectionSort(data, size);
    
    cout << "Sorted array in Acsending Order: \n"; 
    printArray(data, size);
}