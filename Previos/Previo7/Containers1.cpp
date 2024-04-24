#include <iostream>
#include <vector> // Incluye la liberia vector
using namespace std;

int main() {

    // Inicializa un vector de tipo int
    vector<int> numbers = {1, 100, 10, 70, 100};

    // Imprime los numeros del vector
    cout << "Numbers are: "; 
    for (auto &num: numbers) { 
        cout << num << ", ";
    }

    return 0;
}
