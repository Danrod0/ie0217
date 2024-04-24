#include <iostream> 
#include <forward_list> // Incluye la liberia forward_list
using namespace std;

int main() {
    
    // Inicializa una lista ligada simple (forward_list) de enteros
    forward_list<int> nums{1, 2, 3, 4};

    // Inicializa un iterador para apuntar al inicio de la lista ligada
    forward_list<int>::iterator itr = nums.begin();

    // Recorre la lista ligada y multiplica cada elemento por 2
    while (itr != nums.end()) {

        // Accede al valor del iterador utilizando el operador de indireccion 
        int original_value = *itr;

        // Asigna un nuevo valor utilizando el operador de indireccion
        *itr = original_value * 2;
        
        // Avanza el iterador a la siguiente posicion 
        itr++;
    }   

    // Muestra el contenido de nums
    for (int num: nums) {
        cout << num << ", ";
    }
    
    return 0;
}