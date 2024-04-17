// Insertion sort in C++

#include <iostream> 
using namespace std;

// Función para imprimir un arreglo
void printArray(int array[], int size) { 
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para ordenar un arreglo usando el algoritmo de ordenamiento por inserción
void insertionSort(int array[], int size) {
    // Itera sobre cada elemento del arreglo comenzando desde el segundo elemento
    for (int step = 1; step < size; step++) {
        int key = array[step]; // Almacena el valor del elemento actual
        int j = step - 1; // Inicializa el índice del elemento anterior al actual

        // Compara el elemento actual con cada elemento a su izquierda hasta encontrar un elemento menor que él.
        // Para orden descendente, cambia key < array[j] a key > array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j]; // Desplaza el elemento a la derecha
            --j; // Decrementa el índice para comparar con el siguiente elemento a la izquierda
        }
        array[j + 1] = key; // Inserta el elemento en su posición correcta
    }
}

// Función principal 
int main() {
    int data[] = {9, 5, 1, 4, 3};

    // Encuentra la longitud del arreglo
    int size = sizeof(data) / sizeof(data[0]); 
    insertionSort(data, size); // Ordena el arreglo usando el algoritmo de ordenamiento por inserción
    cout << "Sorted array in ascending order: \n"; 
    printArray(data, size);
}
