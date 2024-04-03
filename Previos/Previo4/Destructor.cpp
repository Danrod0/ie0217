#include <iostream> 
#include <fstream>

class Archivo {
    private:
        std::fstream archivo; // variable fstream para manejar el archivo

    public:
        Archivo (std::string nombre_archivo) { // Constructor que toma el nombre del archivo
            archivo.open(nombre_archivo, std::ios::in | std::ios::out | std::ios::app); // Aca se intenta abrir el archivo
            if (!archivo.is_open()) { // Se verifica si el archivo se abrió correctamente
                std::cout << "No se pudo abrir el archivo " << nombre_archivo << std::endl; // Si no se puede abrir se imprime un mensaje de error en la consola
            }
        }

        ~Archivo() { // ~ es lo que lo hace destructor
            if (archivo.is_open()) { // Verifica si el archivo está abierto
                archivo.close(); // Cierra el archivo
            };
        }
};

int main() {
    Archivo mi_archivo("datos.txt"); // Crea un objeto de la clase Archivo con el nombre de archivo "datos.txt"
    
    // hacer algo con el archivo

    return 0;
}
