// Stack implementation in C++

#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10 // Tamaño maximo de la pila
int size = 0; // Tamaño actual de la pila

// Definicion de la estructura de la pila
struct stack {
    int items[MAX]; // Arreglo para almacenar los elementos de la pila
    int top; // indice del elemento superior de la pila
};
typedef struct stack st; // Renombrando la estructura como 'st'

void createEmptyStack(st *s) { 
    s->top = -1; // Inicializa el indice del elemento superior como -1
}

// Funcion para verificar si la pila esta llena
int isfull(st *s) {
    if (s->top == MAX - 1) // Si el indice del elemento superior es igual a MAX - 1, la pila esta llena
        return 1;
    else
        return 0;
}

// Funcion para verificar si la pila esta vacia 
int isempty(st *s) {
    if (s->top == -1) // Si el indice del elemento superior es -1, la pila esta vacia
        return 1;
    else
        return 0;
}

// Funcion para agregar elementos a la pila
void push(st *s, int newitem) { 
    if (isfull(s)) {
        cout << "STACK FULL"; // Muestra un mensaje si la pila esta llena
    } else {
        s->top++; // Incrementa el indice del elemento superior
        s->items[s->top] = newitem; // Agrega el nuevo elemento en la posicion del indice del elemento superior
    }
    size++; // Incrementa el tamaño de la pila
}

// Funcion para eliminar un elemento de la pila
void pop(st *s) {
    if (isempty(s)) {
        cout << "\n STACK EMPTY \n";  // Muestra un mensaje si la pila esta vacia
    } else {
        cout << "Item popped= " << s->items[s->top]; // Muestra el elemento que se esta eliminando
        s->top--; // Decrementa el indice del elemento superior
    }
    size--; // Decrementa el tamaño de la pila
    cout << endl;
}

// Funcion para imprimir los elementos de la pila
void printStack(st *s) { 
    printf("Stack: ");
    for (int i = 0; i < size; i++) {
        cout << s->items[i] << " "; // Imprime cada elemento de la pila
    }
    cout << endl;
}

// Funcion principal
int main() { 
    int ch;
    st *s = (st *)malloc(sizeof(st)); // Crea un puntero a una estructura 'st' en el heap

    // Crea una pila vacía
    createEmptyStack(s);

    // Agrega elementos a la pila
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    // Imprimie la pila
    printStack(s);

    pop(s); // Elimina un elemento de la pila

    // Imprime la pila despues de eliminar un elemento
    cout << "\nAfter popping out\n";
    printStack(s);
}
