#include <iostream> // Libreria

int main(int argc, char* argv[]) { // Funcion main con argumentos de entrada
    std::cout << "argc: " << argc << std::endl; // Imprime la cantidad de argumentos
    std::cout << "argv[0]: " << argv[0] << std::endl; // Imprime el nombre del programa
    std::cout << "argv[1]: " << argv[1] << std::endl; // Imprime los argumentos
    std::cout << "argv[2]: " << argv[2] << std::endl;
    std::cout << "argv[3]: " << argv[3] << std::endl;
    
    return 0;
}