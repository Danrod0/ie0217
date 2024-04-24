#include <iostream>
#include <set> // Incluye la liberia set
using namespace std;

int main() {

    // Inicializa un set de tipo int
    set<int> numbers = {1, 100, 10, 70, 100};

    // Imprime los numeros del set
    cout << "Numbers are: "; 
    for (auto &num: numbers) { 
        cout << num << ", ";
    }

    return 0;
}
