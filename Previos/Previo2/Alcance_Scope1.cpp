#include <iostream>  // Libreria
int count; // Variable global
extern void write_extern(); // Declaración de una función externa

main() {
    count = 5;
    write_extern(); // Llama a la funcion externa
    return 0;
}