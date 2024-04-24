#include <iostream>
#include <unordered_set> // Incluye la liberia unordered_set
using namespace std;

int main() {

    // Inicializa una unordered_set de tipo int
    unordered_set<int> numbers = {1, 100, 10, 70, 100};

    // Imprime los numeros del unordered_set
    cout << "Numbers are: "; 
    for (auto &num: numbers) { 
        cout << num << ", ";
    }

    return 0;
}
