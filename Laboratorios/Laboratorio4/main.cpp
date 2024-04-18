#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "funciones.hpp"

using namespace std;
using namespace std::chrono;

int main(){
    /*
    Esta es la funcion main, donde
    se llaman las funciones para
    comparar los tiempos de ejeccion
    de los distintos tipos de 
    algoritmo de ordenamiento
    esto generando un array random para
    cada uno.
    */
    const int SIZE = 10000;
    int arr[SIZE];

    generateRandomArray(arr, SIZE);
    measuringSortingTime(bubbleSort, arr, SIZE, "Bubble Sort");

    generateRandomArray(arr, SIZE);
    measuringSortingTime(selectionSort, arr, SIZE, "Selection Sort");

    generateRandomArray(arr, SIZE);
    measuringSortingTime(insertionSort, arr, SIZE, "Insertion Sort");

    generateRandomArray(arr, SIZE);
    measuringQuickSortTime(quickSort, arr, 0, SIZE -1, "Quick Sort");

    return 0;
}