/**
 * @file  Email.hpp
 * @brief Este archivo se encuentra la firma
 * de la clase ValidadorEmail
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 16/5/2024
 * 
 * Licencia: MIT
 */

#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <regex>
#include <iostream>
#include <string>

/**
* @brief Se declara la clase ValidadorEmail
* esta tiene los metodos para obtener las
* partes del correo y validarlo
*    
* 
*/
// Declaracion de la clase ValidadorEmail
class ValidadorEmail { 
    // Metodos publicos para validar diferentes aspectos del correo electronico
    public:
        void validacionNombre(const std::string& mail);
        void validacionDominio(const std::string& mail);
        void validacionExtension(const std::string& mail); 
        void validarArroba(const std::string& mail);
        bool validarCorreo(const std::string& mail);

    // Metodos privados para extraer partes del correo electronico
    private:
        std::string getNombre(const std::string& mail);
        std::string getExtension(const std::string& mail);
        std::string getDominio(const std::string& mail);
};


#endif // EMAIL_HPP