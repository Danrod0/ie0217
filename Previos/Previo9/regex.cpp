#include <iostream> 
#include <regex> // Incluye la biblioteca regex

int main() {
    // Define una expresion regular utilizando la clase std::regex
    auto const regex = std::regex(" (my|your) regex");

    // Define tres textos diferentes
    // Y utiliza std::regex_search para buscar la expresión regular en cada texto

    auto const myText = std::string ("A piece of text that contains my regex."); 
    bool const myTextContainsRegex = std::regex_search(myText, regex);
    
    auto const yourText = std::string ("A piece of text that contains your regex."); 
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    auto const theirText = std::string ("A piece of text that contains their regex."); 
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    // Imprime los resultados
    std::cout << std::boolalpha
                << myTextContainsRegex << '\n'
                << yourTextContainsRegex << '\n' 
                << theirTextContainsRegex << '\n';

}
