#include <iostream>

/* Se almacena en el segmento de data. */ 
int globalVariable = 42;

int main() {
    /*.Se almacena en el stack. */
    int stackVariable = 10;

    /* Se almacena en el heap. */
    int* heapVariable = new int(20);

    // Imprimir el valor de globalVariable
    std::cout << "Valor de globalVariable: " << globalVariable << std::endl;
    // Imprimir el valor de stackVariable
    std::cout << "Valor de stackVariable: "  << stackVariable << std::endl;
    // Imprimir el valor apuntado por heapVariable
    std::cout << "Valor de heapVariable: " << *heapVariable << std::endl;

    /* Liberar la memoria asignada en el heap. */
    delete heapVariable;

    return 0;
}