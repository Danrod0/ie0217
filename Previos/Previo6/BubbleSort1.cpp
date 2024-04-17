#include <iostream>
using namespace std;

// Función para realizar el ordenamiento de burbuja
void bubbleSort(int array[], int size) {

    // Bucle para acceder a cada elemento del arreglo 
    for (int step = 0; step < size; ++step) {
    
        // Bucle para comparar los elementos del arreglo
        for (int i = 0; i < size - step; ++i) {
            
            // Compara dos elementos adyacentes
            // Cambia > a < para ordenar en orden descendente
            if (array[i]> array[i + 1]) {

                // Intercambia los elementos si no están en el orden deseado 
                int temp = array[i];
                array[i] = array[i + 1]; 
                array[i + 1] = temp;
            }
        }
    }  
}

// Función para imprimir el arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout<<"\n";
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
