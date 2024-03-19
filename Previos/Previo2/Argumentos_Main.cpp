#include <iostream> // Libreria

int main(int argc, char* argv[]) { // Funcion main con argumentos de entrada
    std::cout << "Número de argumentos: " << argc << std::endl; // Imprime en consola
    std::cout << "Nombre del programa: " << argv[0] << std::endl; // Imprime en consola
    
    // Imprimir argumentos adicionales si existen
    if (argc > 1) { // Comprueba si hay mas de un argumento
        std::cout << "Argumentos adicionales: " << std::endl;
        for (int i = 1; i < argc; ++i) { // Bucle para imprimir los argumentos adicionales
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
    }
    
    return 0;
}