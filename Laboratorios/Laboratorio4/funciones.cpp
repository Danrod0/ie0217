#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "funciones.hpp"

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    /*
    Funcion para implementar el metodo
    de ordenamiento de burbuja, recorre el
    array, cuando tiene los dos elementos a
    comparar, los revisa a ver si intercambia
    sus posiciones.
    */
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    /*
    Funcion para implementar el metodo
    de ordenamiento de seleccion.
    Primero busca el elemento mas pequeno
    cuando lo selecciona, lo coloca en su
    posicion correcta, luego vuelve a 
    recorrer el array en busca del siguiente
    mas pequeno, y asi hasta ordenarlo.
    */
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertionSort(int arr[], int n) {
    /*
    Funcion para implementar el metodo
    de ordenamiento de inserccion,
    Se selecciona un elemento del array
    lo va comparando con cada uno de los 
    elementos, si es menor, los desplaza
    asi hasta encontrar su posicion.
    */
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    /*
    Esta funcion toma el elemento pivote del
    array, particiona el array en 2, dejando
    los elementos menores del mismo de un lado
    y los mayores del otro, una vez hecho esto
    devuelve la posicion del pivote en el array
    "ordenado".
    */
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    /*
    Funcion para implementar el metodo
    de ordenamiento de Quick Sort,
    Primero compara que low sea menro que high
    si si, llama a la funcion partition, la cual
    devuelve la posicion correcta del pivote
    luego llama 2 veces a la funcion de nuevo
    modificando su rango.
    */
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[], int n) {
    /*
    Esta funcion genera un array
    aleatorio utilizando la funcion
    rand.
    */
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
    }
}

void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName) {
    /*
    Esta funcion se utiliza para
    medir el tiempo de ejecucion
    de los algoritmos de ordenamiento
    utilizando funciones la liberia
    chrono.
    */
    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortingAlgorithm(arr, n);
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // auto duration = duration_cast<microseconds>(stop - start); otra version
    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;
}

void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int, int), int arr[], int low, int high, string algorithmName) {
    /*
    Esta funcion se utiliza para
    medir el tiempo de ejecucion
    del algoritmo Quick sort
    utilizando funciones la liberia
    chrono.
    */
    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortingAlgorithm(arr, low, high);
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // auto duration = duration_cast<microseconds>(stop - start); otra version
    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;
}
