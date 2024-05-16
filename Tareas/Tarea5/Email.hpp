#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <regex>
#include <iostream>
#include <string>

class ValidadorEmail { 
    private:
        std::string getNombre(const std::string& mail);
        std::string getExtension(const std::string& mail);
        std::string getDominio(const std::string& mail);
};


#endif // EMAIL_HPP