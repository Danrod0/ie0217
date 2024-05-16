#include "Email.hpp"

std::string ValidadorEmail::getNombre(const std::string& mail) {

    size_t arroba = mail.find('@');

    std::string nombre = mail.substr(0, arroba);

    return nombre;
}

std::string ValidadorEmail::getDominio(const std::string& mail) {

    size_t arroba = mail.find('@');

    size_t inicio = arroba + 1;

    size_t final = mail.find_last_of('.') - arroba- 1;

    std::string dominio =  mail.substr(inicio, final);
    
    return dominio;
}

std::string ValidadorEmail::getExtension(const std::string& mail) {

    size_t punto = mail.find_last_of('.');

    std::string extension = mail.substr(punto + 1);
    return extension;
}

void ValidadorEmail::validacionNombre(const std::string& mail) {
    
    std::string nombre = getNombre(mail);
    
    std::regex charNombre("^(?!.*([._-])\\1)[a-zA-Z0-9](?:[a-zA-Z0-9._-]{0,15}[^.-_])?$");
    
    size_t cantidadCharNombre = std::count_if(nombre.begin(), nombre.end(), [](char c) {
        return std::isalnum(c) && c != '.' && c != '-' && c != '_';
    });

    if (cantidadCharNombre > 15) {
        throw std::invalid_argument("El nombre no puede contener mas de 15 caracteres.");
    }

    if (nombre.front() == '.' || nombre.back() == '.'|| nombre.front() == '-'|| nombre.back() == '-'|| nombre.front() == '_'|| nombre.back() == '_') {
        throw std::invalid_argument("El nombre no puede empezar o terminar con un punto \".\", guion \"-\" o guion bajo \"_\" .");
    }

    if (std::regex_search(nombre, std::regex("[._-]{2}"))) {
        throw std::invalid_argument("El nombre no puede contener dos o mas caracteres especiales consecutivos. (Ej: .. , .- , _-, ._, __, --)");
    }

    if (!std::regex_match(nombre, charNombre)) {
        throw std::invalid_argument("El nombre introducido es invalido.");
    }
}
