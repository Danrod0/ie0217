#include <iostream>
using namespace std;

// Función para imprimir un arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para dividir el arreglo y devolver el índice del pivote
int pivote(int array[], int menor, int mayor) {
    // Selecciona el elemento pivote
    int pivot = array[mayor];
    int i = menor - 1;

    // Coloca los elementos menores que el pivote a la izquierda y los mayores a la derecha
    for (int j = menor; j < mayor; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]); // Intercambia los elementos
        }
    }
    swap(array[i + 1], array[mayor]); // Coloca el pivote en su posición final
    return i + 1;
}

// Función para implementar el algoritmo de Quick Sort
void quickSort(int array[], int menor, int mayor) {
    if (menor < mayor) {
        // Divide el arreglo en dos sub-arreglos
        int pi = pivote(array, menor, mayor);

        // Ordena recursivamente cada sub-arreglo
        quickSort(array, menor, pi - 1);
        quickSort(array, pi + 1, mayor);
    }
}

// Driver code
int main() {
    int data[] = {9, 5, 1, 4, 3};

    // Encuentra la longitud del arreglo
    int size = sizeof(data) / sizeof(data[0]);

    // Aplica el algoritmo de Quick Sort
    quickSort(data, 0, size - 1);

    cout << "Sorted array in ascending order: \n";
    printArray(data, size);
    return 0;
}