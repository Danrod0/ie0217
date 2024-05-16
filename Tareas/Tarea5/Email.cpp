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


