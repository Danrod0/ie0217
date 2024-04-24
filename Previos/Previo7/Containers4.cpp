#include <iostream> 
#include <map> // Incluye la liberia map
using namespace std;

int main() {

    map<int, string> student; // Crea un mapa que asigna enteros a cadenas de texto
    
    // Usa el operador [] para agregar elementos
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // Usa el metodo insert() para agregar elementos
    student.insert(make_pair(3, "Denise")); 
    student.insert(make_pair(4, "Blake"));

    // Agrega elementos con claves duplicadas
    student[5] = "Timothy";
    student[5] = "Aaron";
    
    // Itera sobre el mapa e imprime los elementos
    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    return 0;
}