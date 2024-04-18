#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>

using namespace std;

/*
Este es el archivo de cabecera donde]
se crean las firmas de todas las funciones
a utilizar para realizar la comparacion
de los 4 distintos metodos de ordenamiento
utilizados en el laboratorio.
*/

void bubbleSort(int arr[], int n);

void selectionSort(int arr[], int n);

void insertionSort(int arr[], int n);

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

void generateRandomArray(int arr[], int n);

void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName);

void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int, int), int arr[], int low, int high, string algorithmName);

#endif // FUNCIONES_HPP