// Linked list implementation in C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Definicion de la clase Node para representar los nodos de la lista enlazada
class Node { 
    public:
        int value;
        Node* next;
};

int main() { 
    // Se definen punteros a los nodos
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // Se asignan 3 nodos en el heap
    one = new Node();
    two = new Node(); 
    three = new Node();

    // Se asignan valores a los nodos
    one->value = 1; 
    two->value = 2; 
    three->value = 3;

    // Se conectan los nodos
    one->next = two;
    two->next = three;
    three->next = NULL;  // El ultimo nodo apunta a NULL para indicar el final de la lista

    // Se imprime el valor de los nodos de la lista enlazada
    head = one; // Se asigna el puntero head al primer nodo
    while (head != NULL) { // Mientras head no sea NULL, se recorren los nodos de la lista
        cout << head->value; // Se imprime el valor del nodo actual
        head = head->next; // Se avanza al siguiente nodo
    }
}
