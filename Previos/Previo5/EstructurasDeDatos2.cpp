// Queue implementation in C++

#include <iostream> 
#define SIZE 5 // Tamaño maximo de la cola

using namespace std;

class Queue { 
    private:
        int items [SIZE], front, rear; 

    public: 
        Queue() {
            front = -1; 
            rear = -1;
        }

        // Funcion para verificar si la cola esta llena
        bool isFull() {
            if (front == 0 && rear == SIZE - 1) { 
                return true;  // Si el frente esta en 0 y el final esta en SIZE - 1, la cola esta llena
            }
            return false;
        }

        // Funcion para verificar si la cola esta vacia
        bool isEmpty() {
            if (front == -1)
                return true; // Si el frente es -1, la cola esta vacia
            else
                return false;
        }

        // Funcion para agregar un elemento a la cola
        void enQueue(int element) { 
            if (isFull()) {
                cout << "Queue is full"; // Muestrar un mensaje si la cola esta llena
            } else {
                if (front == -1) front = 0; // Si el frente es -1, establece el frente en 0
                rear++; // Incrementa el indice
                items [rear] = element; // Agrega el nuevo elemento en la posicion del indice del final
                cout << endl
                    << "Inserted " << element << endl; // Muestra el elemento insertado
            }
        }

        // Funcion para eliminar un elemento de la cola
        int deQueue() {
            int element;
            if (isEmpty()) {
                cout << "Queue is empty" << endl; // Muestra un mensaje si la cola esta vacia
                return (-1);
            } else {
                element = items[front];// Obtiene el elemento en el frente de la cola
                if (front >= rear) { // Si el frente es mayor o igual que el final, la cola esta vacia
                    front = -1;
                    rear = -1;
                } 
                else {
                    front++; // Incrementa el indice
                }
                cout << endl
                    << "Deleted -> " << element << endl; // Muestra el elemento eliminado
                return (element);
            }
        }

        // Funcion para mostrar los elementos de la cola
        void display() {
            int i;
            if (isEmpty()) {
                cout << endl
                    << "Empty Queue" << endl; // Muestra un mensaje si la cola esta vacia
            } else {
                cout << endl
                    << "Front index->" << front; 
                cout << endl
                    << "Items -> ";
                for (i = front; i <= rear; i++) 
                    cout << items[i] << " "; // Imprime cada elemento de la cola
                cout << endl
                    << "Rear index-> " << rear << endl;
            }
        }
};

// Funcion principal
int main() { 
    Queue q;

    // No se puede hacer deQueue en una cola vacia
    q.deQueue();

    // Agregar 5 elementos a la cola
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // No se puede agregar un sexto elemento porque la cola esta llena
    q.enQueue(6);

    q.display(); // Muestra los elementos de la cola
    
    // Elimina el primer elemento ingresado (1) 
    q.deQueue();

    // Ahora tenemos solo 4 elementos en la cola
    q.display(); // Se muestran los elementos de la cola despues de eliminar un elemento

    return 0;
}
