#include "text_processor.hpp"
#include <fstream>
#include <regex>

// Constructor de la clase que se inicializa con los nombres de archivo de entrada y salida
TextProcessor::TextProcessor(const std::string& input_filename, const std::string& output_filename)
    : input_filename(input_filename), output_filename(output_filename){}

// Funcion para reemplazar todas las ocurrencias del patron de busqueda con la cadena de reemplazo en el archivo de salida
void TextProcessor::replace(const std::string& search_pattern, const std::string& replace_string){
    // Abre el archivo de entrada
    std::ifstream input_file(input_filename);

    // Abre/crea el archivo de salida
    std::ofstream output_file(output_filename);
    std::string line;

    // Crea un objeto regex con el patron de búsqueda
    std::regex pattern(search_pattern);

    // Primero verfica que los arcivos de entrada y salida se hayan abierto bien
    if(input_file && output_file){
        // Ahora lee cada linea del archivo de entrada
        while(getline(input_file, line)){
            // Realiza el reemplazo en la linea actual y la almacena en la variable 'replaced'
            std::string replaced = std::regex_replace(line, pattern, replace_string);
            // Escribe la linea reemplazada en el archivo de salida, seguida de un salto de linea
            output_file << replaced << "\n";
        }
    }
}