/**
 * @file  Email.cpp
 * @brief Este archivo se encuentra definida la clase
 * ValidadorEmail, junto con sus metodos
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 16/5/2024
 * 
 * Licencia: MIT
 */

#include "Email.hpp"


/**
* @brief Este metodo se crea para obtener
* la parte del correo llamada nombre 
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para obtener el nombre de usuario de un correo electronico
std::string ValidadorEmail::getNombre(const std::string& mail) {
    // Buscar la posicion de la arroba
    size_t arroba = mail.find('@');
    // Extraer el substring desde el inicio hasta la posicion de la arroba
    std::string nombre = mail.substr(0, arroba);
    // Devolver el nombre de usuario
    return nombre;
}

/**
* @brief Este metodo se crea para obtener
* la parte del correo llamada dominio 
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para obtener el dominio de un correo electronico
std::string ValidadorEmail::getDominio(const std::string& mail) {
    // Buscar la posicion de la arroba
    size_t arroba = mail.find('@');
    // Calcular el inicio del substring del dominio
    size_t inicio = arroba + 1;
    // Calcular la longitud del substring del dominio
    size_t final = mail.find_last_of('.') - arroba - 1;
    // Extraer el substring del dominio
    std::string dominio = mail.substr(inicio, final);
    // Devolver el dominio
    return dominio;
}

/**
* @brief Este metodo se crea para obtener
* la parte del correo llamada extension 
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para obtener la extension de un correo electronico
std::string ValidadorEmail::getExtension(const std::string& mail) {
    // Buscar la posicion del ultimo punto
    size_t punto = mail.find_last_of('.');
    // Extraer la extension a partir de la posicion del ultimo punto
    std::string extension = mail.substr(punto + 1);
    // Devolver la extension
    return extension;
}

/**
* @brief Este metodo se crea para validar
* la parte del correo llamada nombre 
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para validar el nombre de usuario de un correo electronico
void ValidadorEmail::validacionNombre(const std::string& mail) {
    // Obtener el nombre de usuario
    std::string nombre = getNombre(mail);
    // Definir una expresion regular para validar el nombre de usuario
    std::regex charNombre("^(?!.*([._-])\\1)[a-zA-Z0-9](?:[a-zA-Z0-9._-]{0,15}[^.-_])?$");
    // Contar la cantidad de caracteres validos en el nombre de usuario
    size_t cantidadCharNombre = std::count_if(nombre.begin(), nombre.end(), [](char c) {
        return std::isalnum(c) && c != '.' && c != '-' && c != '_';
    });
    // Verificar si la cantidad de caracteres excede el limite
    if (cantidadCharNombre > 15) {
        throw std::invalid_argument("El nombre no puede contener mas de 15 caracteres.");
    }
    // Verificar si el nombre comienza o termina con un caracter especial
    if (nombre.front() == '.' || nombre.back() == '.'|| nombre.front() == '-'|| nombre.back() == '-'|| nombre.front() == '_'|| nombre.back() == '_') {
        throw std::invalid_argument("El nombre no puede empezar o terminar con un punto \".\", guion \"-\" o guion bajo \"_\" .");
    }
    // Verificar si el nombre contiene dos o mas caracteres especiales consecutivos
    if (std::regex_search(nombre, std::regex("[._-]{2}"))) {
        throw std::invalid_argument("El nombre no puede contener dos o mas caracteres especiales consecutivos. (Ej: .. , .- , _-, ._, __, --)");
    }
    // Verificar si el nombre cumple con la expresion regular
    if (!std::regex_match(nombre, charNombre)) {
        throw std::invalid_argument("El nombre introducido es invalido.");
    }
}

/**
* @brief Este metodo se crea para validar
* la parte del correo llamada dominio 
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para validar el dominio de un correo electronico
void ValidadorEmail::validacionDominio(const std::string& mail) {
    // Obtener el dominio
    std::string dominio = getDominio(mail);
    // Definir una expresion regular para validar el dominio
    std::regex charDominio("^([a-zA-Z]+\\.[a-zA-Z]+)(\\.[a-zA-Z]+)*$");
    // Contar la cantidad de caracteres validos en el dominio
    size_t cantidadCharDominio = std::count_if(dominio.begin(), dominio.end(), [](char c) {
        return std::isalnum(c) && c != '.';
    });
    // Verificar si la cantidad de caracteres excede los limites establecidos
    if (cantidadCharDominio > 30 || cantidadCharDominio < 3) {
        throw std::invalid_argument("El dominio no puede contener mas de 30 caracteres ni menos de 3.");
    }
    // Verificar si el dominio comienza o termina con un punto
    if (dominio.front() == '.' || dominio.back() == '.') {
        throw std::invalid_argument("El dominio no puede iniciar ni terminar con un punto.");
    }
    // Verificar si el dominio contiene segmentos consecutivos separados por un unico punto
    if (dominio.find("..") != std::string::npos) {
        throw std::invalid_argument("El dominio no puede contener segmentos consecutivos separados por un unico punto. (Ej: hola..mundo)");
    }
    // Verificar si el dominio cumple con la expresion regular
    if (!std::regex_match(dominio, charDominio)) {
        throw std::invalid_argument("El dominio introducido es invalido.");
    }
}

/**
* @brief Este metodo se crea para validar
* la parte del correo llamada extension 
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para validar la extension de un correo electronico
void ValidadorEmail::validacionExtension(const std::string& mail) {
    // Obtener la extension
    std::string extension = getExtension(mail); 
    // Definir una expresion regular para validar la extension
    std::regex charExtension("^([a-zA-Z]{2,6}|\\.[a-zA-Z]{2,6})(\\.[a-zA-Z]{2,6}){0,2}$");
    // Verificar si la longitud de la extension cumple con los limites establecidos
    if (extension.length() > 6 || extension.length() < 2) {
        throw std::invalid_argument("La extension no puede contener mas de 6 letras ni menos de dos.");
    }
    // Verificar si la extension cumple con la expresion regular
    if (!std::regex_match(extension, charExtension)) {
        throw std::invalid_argument("La extension introducida es invalida (solo puede contener letras, no numeros ni caracteres especiales).");
    }
}

/**
* @brief Este metodo se crea para validar
* la parte que el correo tenga arroba
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para validar la presencia de la arroba en un correo electronico
void ValidadorEmail::validarArroba(const std::string& mail) {
    // Buscar la posicion de la arroba
    size_t arroba = mail.find('@');
    // Si no se encuentra la arroba, lanzar una excepcion
    if (arroba == std::string::npos) { 
        throw std::invalid_argument("El correo debe contener una arroba.");
    }  
}

/**
* @brief Este metodo se crea para llamar
* todas las validaciones
*
* @param mail es un parámetro tipo string que es
* el correo ingresado por el usuario
* 
*/
// Metodo para validar un correo electronico en su totalidad
bool ValidadorEmail::validarCorreo(const std::string& mail) {
    try {
        // Llamar a los metodos de validacion individual
        validarArroba(mail);
        validacionNombre(mail);
        validacionExtension(mail);
        validacionDominio(mail);
        // Si todas las validaciones pasan, devolver verdadero
        return true;
    } 
    // Capturar cualquier excepcion y mostrar un mensaje de error
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Devolver falso si la validacion falla
        return false;
    }
}