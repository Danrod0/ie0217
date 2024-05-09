#include <iostream>
#include "text_processor.hpp"

int main(int argc, char* argv[]){
    // Primero se verifica que se poporcionaran la cantidad suficiente de argumentos
    if(argc < 5){
        // Si no se proporcionan imprime el siguiente mensaje
        std::cerr << "Usage: " << argv[0] << "-f <filename> -o <outputfile> -search <search_pattern> -replace <replace_string>\n";
    }

    // Obtiene los argumentos
    std::string filename = argv[2];
    std::string outputfile = argv[4];
    std::string search_pattern = argv[6];
    std::string replace_string = argv[8];

    // Crea un objeto TextProcessor con los nombres de archivo de entrada y salida
    TextProcessor processor(filename, outputfile);

    // Llama a la funcion replace para reemplazar el patron de busqueda con la cadena de reemplazo
    processor.replace(search_pattern, replace_string);

    return 0;
}