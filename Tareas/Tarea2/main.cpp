#include <iostream>

using namespace std;

int main() {
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "Menu:" << endl;
        cout << "1. Imprimir informacion de todos los paises." << endl;
        cout << "2. Comparar paises." << endl;
        cout << "3. Agregar un nuevo pais." << endl;
        cout << "4. Eliminar un pais existente." << endl;
        cout << "5. Salir del programa." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                salir = true;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
                break;
        }
    }

    cout << "Saliendo del programa..." << endl;

    return 0;
}