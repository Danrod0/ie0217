/**
 * @file main.cpp
 * @brief Este archivo tiene las funciones principal
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 10/4/24
 * 
 * Licencia: MIT
 */
#include <iostream>
#include <cstdlib>
#include "Planeta.hpp"
#include "Continentes.hpp"
#include "PaisEnDesarrollo.hpp"
#include "PaisPrimerMundo.hpp"

using namespace std;

// Enumeración para representar los continentes
enum Continente {
    AMERICA = 1,
    EUROPA,
    ASIA,
    AFRICA,
    OCEANIA
};

/**
 * @brief Imprime las opciones de continentes
 * 
 * Funcion que imprime la lista
 * de los continentes disponibles
 * 
 * 
 */
// Función para imprimir la lista de opciones de continentes
void imprimirOpcionesContinentes() {
    cout << "Lista de Continentes:" << endl;
    cout << "1. America" << endl;
    cout << "2. Europa" << endl;
    cout << "3. Asia" << endl;
    cout << "4. Africa" << endl;
    cout << "5. Oceania" << endl;
}


/**
 * @brief Es la funcion main del programa.
 * 
 * Comienza con la creación de un objeto Planeta, 
 * al que se le agregan cinco continentes. Luego, 
 * entra en un bucle while que muestra un menú de 
 * opciones al usuario, permitiéndole realizar diversas 
 * acciones relacionadas con la información de los países 
 * en el planeta. Estas opciones incluyen imprimir 
 * información de todos los países, comparar países por 
 * ID, agregar un nuevo país con opciones de tipo y 
 * continente, eliminar un país existente por su ID y 
 * salir del programa. Cada opción se implementa mediante 
 * un switch que realiza las operaciones correspondientes 
 * según la selección del usuario. El bucle while continúa 
 * hasta que el usuario elige la opción de salir. Además, 
 * se gestionan algunas variables de control, como 
 * encontrado1 y encontrado2, para la comparación de 
 * países en la opción 2.
 * 
 * 
 * @return Retorna 0
 */
int main() {
    Planeta planeta;

    // Agregar los cinco continentes al planeta
    planeta.agregarContinente(new Continentes("America"));
    planeta.agregarContinente(new Continentes("Europa"));
    planeta.agregarContinente(new Continentes("Asia"));
    planeta.agregarContinente(new Continentes("Africa"));
    planeta.agregarContinente(new Continentes("Oceania"));

    int opcion;
    bool salir = false;
    bool encontrado1 = false, encontrado2 = false; // Variables declaradas aquí

    while (!salir) {
        cout << "\nMenu:" << endl;
        cout << "1. Imprimir informacion de todos los paises." << endl;
        cout << "2. Comparar paises." << endl;
        cout << "3. Agregar un nuevo pais." << endl;
        cout << "4. Eliminar un pais existente." << endl;
        cout << "5. Salir del programa." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Imprimir información de todos los países
                planeta.imprimirInformacion();
                break;
            case 2:
                // Comparar países
                int id1, id2;
                cout << "Ingrese el ID del primer pais: ";
                cin >> id1;
                cout << "Ingrese el ID del segundo pais: ";
                cin >> id2;

                // Variables para verificar si se encontraron los paises
                bool encontrado1 = false, encontrado2 = false;

                // Buscar el primer pais
                for (int i = 0; i < planeta.getNumContinentes(); ++i) {
                    for (int j = 0; j < planeta.getContinentes()[i].getNumPaises(); ++j) {
                        Pais* pais1 = planeta.getContinentes()[i].getPaises()[j];
                        if (pais1->getId() == id1) {
                            encontrado1 = true;

                            // Buscar el segundo pais
                            for (int k = 0; k < planeta.getNumContinentes(); ++k) {
                                for (int l = 0; l < planeta.getContinentes()[k].getNumPaises(); ++l) {
                                    Pais* pais2 = planeta.getContinentes()[k].getPaises()[l];
                                    if (pais2->getId() == id2) {
                                        encontrado2 = true;
                                        // Comparar los tipos de pais
                                        if (*pais1 == *pais2) {
                                            cout << "Los paises son del mismo tipo." << endl;
                                        } else {
                                            cout << "Los paises son de distinto tipo." << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                // Si uno o ambos paises no se encontraron
                if (!encontrado1 || !encontrado2) {
                    cout << "Uno o ambos paises no fueron encontrados." << endl;
                }
                break;
            case 3:
                // Agregar un nuevo país
                int id, habitantes;
                char tipo;
                cout << "Ingrese el ID del pais: ";
                cin >> id;
                cout << "Ingrese la cantidad de habitantes: ";
                cin >> habitantes;
                cout << "Ingrese el tipo de pais ('P' para pais de primer mundo, 'D' para pais en desarrollo): ";
                cin >> tipo;
                Pais* nuevoPais;
                if (tipo == 'P') {
                    // Crear un nuevo pais de primer mundo
                    bool tecnologia5G, centroInvestigacion;
                    cout << "El pais tiene tecnologia 5G (0 para No, 1 para Si): ";
                    cin >> tecnologia5G;
                    cout << "El pais tiene centro de investigacion y desarrollo (0 para No, 1 para Si): ";
                    cin >> centroInvestigacion;
                    nuevoPais = new PaisPrimerMundo(id, habitantes, tecnologia5G, centroInvestigacion);
                } else if (tipo == 'D') {
                    // Crear un nuevo pais en desarrollo
                    nuevoPais = new PaisEnDesarrollo(id, habitantes);
                } else {
                    // Tipo de pais no válido
                    cout << "Tipo de pais no valido." << endl;
                    break;
                }
                
                // Imprimir opciones de continentes
                imprimirOpcionesContinentes();
                
                // Seleccionar el continente donde agregar el país
                int continenteIndex;
                cout << "Seleccione el numero correspondiente al continente donde desea agregar el pais: ";
                cin >> continenteIndex;
                
                // Validar el índice del continente
                if (continenteIndex >= 1 && continenteIndex <= 5) {
                    planeta.agregarPaisEnContinente(nuevoPais, continenteIndex - 1);
                } else {
                    // Opción de continente no válida
                    cout << "Opcion de continente no valida." << endl;
                }
                break;
            case 4:
                // Eliminar un país existente
                int idEliminar;
                cout << "Ingrese el ID del pais que desea eliminar: ";
                cin >> idEliminar;
                for (int i = 0; i < planeta.getNumContinentes(); ++i) {
                    planeta.getContinentes()[i].eliminarPais(idEliminar);
                }
                break;
            case 5:
                salir = true;
                cout << "Programa finalizado, gracias por preferirnos..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                break;
        }
    }

    return 0;
}