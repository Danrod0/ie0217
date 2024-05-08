#ifndef CLASES_HPP
#define CLASES_HPP


#include <string>
#include <iostream>
#include <stdexcept>
#include <complex>
#include <vector>
#include <algorithm>
#include <random>

class ValidarEntrada { 

public:
std::string validarDatos(std::string input);
void validarTamanio(int tamano);

};

template <typename T>

class Matriz { 



public:

    std::vector<std::vector<T>> matrizResultado;
    OperacionesBasicas<T> operaciones;
    int filasMatriz;
    int columnasMatriz;
    std::string tipo;

    Matriz(){}

    Matriz(int filas, int columnas, std::string tipoString) : filasMatriz(filas), columnasMatriz(columnas), tipo(tipoString){ 

    setearDimensiones(filasMatriz, columnasMatriz);
    fillMatriz();
    
    

    }

    ~Matriz() {}

    void setearDimensiones(int filasMatriz, int columnasMatriz){ 

    if (filasMatriz <= 0 || columnasMatriz <= 0) {
        throw std::invalid_argument("Dimensiones de la matriz no son validas");
    }
    
    matrizResultado.resize(filasMatriz, std::vector<T>(columnasMatriz));
    
    }

    void fillMatriz(){ 

        if (tipo == "int" || tipo == "float")  { 
            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {

                    std::cout << "Por favor ingrese el valor para la entrada [" << i + 1 << "][" << j + 1 << "]: ";
                    T valorEntrada;
                    std::cin >> valorEntrada;

                    if (std::cin.fail()) {
                        std::cin.clear();

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Entrada invalida: Por favor introducir una entrada numerica del formato deseado");
                        
                    }

                    matrizResultado[i][j] = valorEntrada;
                }
            }

        }

        else if constexpr (std::is_same_v<T, std::complex<float>>){ 

            for (int i = 0; i < filasMatriz; ++i) {

                for (int j = 0; j < columnasMatriz; ++j) {

                    std::cout << "Por favor ingrese la parte real del numero complejo de la entrada [" << i +1 << "][" << j +1 << "]: ";
                    float real;
                    std::cin >> real;

                    if (std::cin.fail()) {

                        std::cin.clear();

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Entrada invalida: Por favor introducir una entrada numerica del formato deseado");
                       
                    }

                    std::cout << "Por favor ingrese la parte imaginaria (solo el numero, omitir la \"i\") del numero complejo de la entrada [" << i +1 << "][" << j +1 <<"]: ";
                    float imaginario;
                    std::cin >> imaginario;

                    if (std::cin.fail()) {

                        std::cin.clear();

                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Entrada invalida: Por favor introducir una entrada numerica del formato deseado");
                        
                    }

                    matrizResultado[i][j] = std::complex<float>(real, imaginario);
                }
            }
        }
    }

    void llenarMatrizRandom() {

        std::random_device random;
        std::mt19937 generador(random());

        if (tipo == "int" || tipo == "float") {
            
            std::uniform_int_distribution<int> distribucionEntera(0, 100); 
            std::uniform_real_distribution<float> distribucionFlotante(0.0, 100.0); 

            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {
                    
                    
                    T valorAleatorio;

                    if constexpr (std::is_same_v<T, int>) {
                        valorAleatorio = distribucionEntera(generador);
                    } 
                    
                    else if constexpr (std::is_same_v<T, float>) {
                        valorAleatorio = distribucionFlotante(generador);
                    }

                    matrizResultado[i][j] = valorAleatorio;
                }
            }
        } 

        else if constexpr (std::is_same_v<T, std::complex<float>>) {

            std::uniform_real_distribution<float> distribucionReal(0.0, 100.0); 
            std::uniform_real_distribution<float> distribucionImaginaria(0.0, 100.0); 

            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {

                    float real = distribucionReal(generador);
                    float imaginaria = distribucionImaginaria(generador);

                    matrizResultado[i][j] = std::complex<float>(real, imaginaria);
                }
            }
        }
    }

    void imprimirMatriz() const {
        for (const auto& fila : matrizResultado) {
            for (const auto& elemento : fila) {
                if constexpr (std::is_same_v<T, std::complex<float>>) {
                    std::cout << "(" << elemento.real() << " + " << elemento.imag() << "i) ";
                } else {
                    std::cout << elemento << " ";
                }
            }
            std::cout << std::endl;
        }
    }
};

#endif // CLASES_HPP