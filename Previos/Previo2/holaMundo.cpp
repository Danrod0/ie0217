#include <iostream> // Libreria

int main(){
    std::cout << "Hola Mundo, estudiantes de IE0217!\n"; // Imprime

    int var1 = 2;
    // int var2 = 2;
    // int var3 = 2;

    // Switch que evalúa en casos el valor de var1
    switch (var1){
        case 1: // Si var1 == 1
            std::cout << "Case 1!\n";
            break; // Termina el switch
        case 2: // Si var1 == 2
        case 3: // Si var1 == 3
            std::cout << "Case Final!\n";
            break;

        default: // se realiza si var1 no cumple ninguno de los casos anteriores
            std::cout << "Case default!\n";
            break;
    }

    return 0;
}