#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <regex>
#include <iostream>
#include <string>

class ValidadorEmail { 
    public:
        void validacionNombre(const std::string& mail);
        void validacionDominio(const std::string& mail);
        void validacionExtension(const std::string& mail); 
        void validarArroba(const std::string& mail);
        bool validarCorreo(const std::string& mail);


    private:
        std::string getNombre(const std::string& mail);
        std::string getExtension(const std::string& mail);
        std::string getDominio(const std::string& mail);
};


#endif // EMAIL_HPP