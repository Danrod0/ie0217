#include <iostream>  // Libreria

extern int count; // Variable global externa

void write_extern(void) { // Definición de la función
    std::cout << "Count is " << count << std::endl;
}