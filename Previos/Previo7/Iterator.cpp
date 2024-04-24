#include <iostream>
#include <vector> // Incluye la liberia vector
using namespace std;

int main() {

    // Crea un vector de strings llamado languages con algunos valores
    vector <string> languages = {"Python", "C++", "Java"};
    
    // Crea un iterador para recorrer el vector de strings
    vector<string>::iterator itr;

    // Itera sobre todos los elementos del vector para imprimirlos
    for (itr = languages.begin(); itr != languages.end(); itr++) { 
        cout<<*itr << ", ";
    }
    
    return 0;
}