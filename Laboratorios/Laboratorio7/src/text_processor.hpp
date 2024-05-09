#ifndef TEXT_PROCESSOR_HPP
#define TEXT_PROCESSOR_HPP

#include <string>

// Clase TextProcesor
class TextProcessor {
    // Atributos privados de la clase
    private:
        std::string input_filename; // Nombre del archivo de entrada
        std::string output_filename; // Nombre del archivo de salida

    // Atributos publicos de la clase
    public:
        // Constructor de la clase que toma los nombres de archivo de entrada y salida como parametros
        TextProcessor(const std::string& input_filename, const std::string& output_filename);

        // Funcion para reemplazar todas las ocurrencias del patron de busqueda con el string que se utilizara para el reemplazo en el archivo de salida
        void replace(const std::string& search_pattern, const std::string& replace_string);
};

#endif