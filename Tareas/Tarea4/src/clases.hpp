/**
 * @file  clases.hpp
 * @brief En este archivo las clases que no usan template, son declaradas
 * mientras que las que si lo usan son definidas
 *
 * @author Daniel Rodriguez Rivas B96719
 * @date 08/05/2024
 * 
 * Licencia: MIT
 */

#ifndef CLASES_HPP
#define CLASES_HPP


#include <string>
#include <iostream>
#include <stdexcept>
#include <complex>
#include <vector>
#include <algorithm>
#include <random>

/**
* @brief La clase ValidarEntrada en tiene dos metodos publicos: 
* validarDatos, que valida tipos de datos, y validarTamanio, que 
* verifica el tamaño de una matriz.
* 
*/
// Clase para validar la entrada de datos
class ValidarEntrada { 
    public:
        // Metodo para validar el tipo de datos
        std::string validarDatos(std::string input);

        // Metodo para validar el tamaño de la matriz
        void validarTamanio(int tamano);
};


// Clase tipo template para operaciones basicas entre matrices
template <typename T>
class OperacionesBasicas;


/**
* @brief La plantilla de clase Matriz representa una matriz 
* generica que puede contener tipos de datos simples como enteros 
* o flotantes, asi como numeros complejos. Proporciona metodos para 
* llenar la matriz con valores ingresados por el usuario o aleatorios, 
* imprimir la matriz y sobrecargar operadores para realizar operaciones 
* matriciales basicas.
* 
*/
// Clase tipo template para representar una matriz
template <typename T>
class Matriz { 
public:
    // Atributos publicos
    std::vector<std::vector<T>> matrizResultado;
    OperacionesBasicas<T> operaciones;
    int filasMatriz;
    int columnasMatriz;
    std::string tipo;

    // Constructor por default
    Matriz(){}

    /**
    * @brief Es el constructor de la clase matriz, pide las dimensiones
    *  y valores de las entradas al usuario
    * 
    * @param filas especifica el numero de filas que tendra la matriz.
    * @param columnas  indica el numero de columnas de la matriz.
    * @param tipoString representa el tipo de datos que contendra la matriz, como "int", "float" o "complejo".
    * 
    *
    */
    // Constructor con parametros
    Matriz(int filas, int columnas, std::string tipoString) : filasMatriz(filas), columnasMatriz(columnas), tipo(tipoString){ 
        setearDimensiones(filasMatriz, columnasMatriz); // Inicializa la matriz con las dimensiones dadas
        fillMatriz(); // Llena la matriz con los valores proporcionados por el usuario
    }

    // Destructor
    ~Matriz() {}

    /**
    * @brief Esta funcion verifica si las dimensiones son validas 
    * (mayores que cero) y redimensiona la matriz en consecuencia 
    * utilizando el metodo resize de la clase std::vector.
    * 
    * @param filasMatriz representa el numero de filas de la matriz.
    * @param columnasMatriz  indica el numero de columnas de la matriz.
    *
    */
    // Metodo para establecer las dimensiones de la matriz
    void setearDimensiones(int filasMatriz, int columnasMatriz){ 
        // Se verifica que las dimensiones sean validas
        if (filasMatriz <= 0 || columnasMatriz <= 0) {
            throw std::invalid_argument("Dimensiones de la matriz no son validas");
        }
        // Se redimensiona la matriz
        matrizResultado.resize(filasMatriz, std::vector<T>(columnasMatriz));  
    }
    
    /**
    * @brief La funcion fillMatriz llena la matriz con valores ingresados 
    * por el usuario, verificando primero el tipo de datos. Si el tipo es 
    * entero o flotante, solicita valores para cada entrada. Si es complejo, 
    * solicita valores para la parte real e imaginaria de cada numero complejo. 
    * Si alguna entrada es invalida, lanza una excepcion.
    *
    */
    // Metodo para llenar la matriz con los valores ingresados por el usuario
    void fillMatriz(){ 
        // Se verifica el tipo de datos T
        if (tipo == "int" || tipo == "float")  { 
            // Si el tipo es entero o flotante, se solicita al usuario que ingrese los valores para cada entrada de la matriz
            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {
                    // Se solicita al usuario que ingrese el valor para la entrada [i][j]
                    std::cout << "Por favor ingrese el valor para la entrada [" << i + 1 << "][" << j + 1 << "]: ";
                    T valorEntrada;
                    std::cin >> valorEntrada;

                    // Se verifica si la entrada es valida
                    if (std::cin.fail()) {
                        // Si la entrada es invalida, se limpia el estado de cin y se ignora la entrada incorrecta
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        // Se lanza una excepcion indicando que la entrada es invalida
                        throw std::invalid_argument("Entrada invalida: Por favor introducir una entrada numerica del formato deseado");
                        
                    }
                    // Se asigna el valor ingresado a la posicion correspondiente en la matriz
                    matrizResultado[i][j] = valorEntrada;
                }
            }
        }
        else if constexpr (std::is_same_v<T, std::complex<float>>){ 
            // Si el tipo es complejo, se solicita al usuario que ingrese la parte real e imaginaria de cada numero complejo en la matriz
            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {
                    // Se solicita al usuario que ingrese la parte real del numero complejo en la posicion [i][j]
                    std::cout << "Por favor ingrese la parte real del numero complejo de la entrada [" << i +1 << "][" << j +1 << "]: ";
                    float real;
                    std::cin >> real;
                    
                    // Se verifica si la entrada es valida
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Entrada invalida: Por favor introducir una entrada numerica del formato deseado");
                    }

                    // Se solicita al usuario que ingrese la parte imaginaria del numero complejo en la posicion [i][j]
                    std::cout << "Por favor ingrese la parte imaginaria (solo el numero, omitir la \"i\") del numero complejo de la entrada [" << i +1 << "][" << j +1 <<"]: ";
                    float imaginario;
                    std::cin >> imaginario;

                    // Se verifica si la entrada es valida
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        throw std::invalid_argument("Entrada invalida: Por favor introducir una entrada numerica del formato deseado");
                    }
                    // Se crea un numero complejo con la parte real e imaginaria ingresadas y se asigna a la posicion correspondiente en la matriz
                    matrizResultado[i][j] = std::complex<float>(real, imaginario);
                }
            }
        }
    }

    /**
    * @brief La función llenarMatrizRandom llena la matriz con valores 
    * aleatorios dentro de un rango especifico. Si el tipo de datos es 
    * entero o flotante, se generan numeros aleatorios dentro de un rango 
    * entero o de punto flotante y se asignan a cada entrada de la matriz. 
    * Si el tipo es complejo, se generan valores aleatorios para la parte real 
    * e imaginaria de cada numero complejo y se asignan a cada entrada de la 
    * matriz.
    *
    */
    // Metodo para llenar la matriz con valores aleatorios
    void llenarMatrizRandom() {
        // Se crea un generador de numeros aleatorios
        std::random_device random;
        std::mt19937 generador(random());

        // Se verifica el tipo de datos T
        if (tipo == "int" || tipo == "float") {
            // Si el tipo es entero o flotante, se generan valores aleatorios dentro de un rango y se asignan a cada entrada de la matriz
            std::uniform_int_distribution<int> distribucionEntera(0, 100); 
            std::uniform_real_distribution<float> distribucionFlotante(0.0, 100.0); 

            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {
                    // Se genera un valor aleatorio dentro del rango adecuado
                    T valorAleatorio;

                    if constexpr (std::is_same_v<T, int>) {
                        valorAleatorio = distribucionEntera(generador);
                    } 
                    
                    else if constexpr (std::is_same_v<T, float>) {
                        valorAleatorio = distribucionFlotante(generador);
                    }
                    // Se asigna el valor aleatorio a la posicion correspondiente en la matriz
                    matrizResultado[i][j] = valorAleatorio;
                }
            }
        } 
        else if constexpr (std::is_same_v<T, std::complex<float>>) {
            // Si el tipo es complejo, se generan valores aleatorios para la parte real e imaginaria de cada numero complejo y se asignan a cada entrada de la matriz
            std::uniform_real_distribution<float> distribucionReal(0.0, 100.0); 
            std::uniform_real_distribution<float> distribucionImaginaria(0.0, 100.0); 

            for (int i = 0; i < filasMatriz; ++i) {
                for (int j = 0; j < columnasMatriz; ++j) {
                    // Se generan valores aleatorios para la parte real e imaginaria
                    float real = distribucionReal(generador);
                    float imaginaria = distribucionImaginaria(generador);
                    // Se crea un numero complejo con los valores aleatorios y se asigna a la posicion correspondiente en la matriz
                    matrizResultado[i][j] = std::complex<float>(real, imaginaria);
                }
            }
        }
    }

    /**
    * @brief La funcion imprimirMatriz itera sobre la matriz y 
    * imprime cada elemento. Si el tipo de datos es complejo, 
    * imprime cada numero complejo en formato (real + imaginario*i),
    * donde real e imaginario son las partes real e imaginaria del 
    * numero. Para otros tipos de datos, imprime el valor normal de 
    * cada elemento.
    *
    */
    // Metodo para imprimir la matriz
    void imprimirMatriz() const {
        // Se itera sobre la matriz y se imprime cada elemento
        for (const auto& fila : matrizResultado) {
            for (const auto& elemento : fila) {
                if constexpr (std::is_same_v<T, std::complex<float>>) {
                    // Si el tipo es complejo, se imprime en formato (real + imaginario*i)
                    std::cout << "(" << elemento.real() << " + " << elemento.imag() << "i) ";
                } else {
                    // Si el tipo no es complejo, se imprime el valor normal
                    std::cout << elemento << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Sobrecarga del operador de suma
    void operator+(Matriz<T>& segundaMatriz) {
        operaciones.Suma(*this, segundaMatriz);
    }

    // Sobrecarga del operador de resta
    void operator-(Matriz<T>& segundaMatriz) {
        operaciones.Resta(*this, segundaMatriz);
    }

    // Sobrecarga del operador de multiplicación
    void operator*(Matriz<T>& segundaMatriz) {
        operaciones.Multiplicacion(*this, segundaMatriz);
    }
};


/**
    * @brief La clase OperacionesBasicas proporciona metodos para 
    * validar y realizar operaciones matriciales basicas, incluyendo 
    * suma, resta y multiplicacion. Estos metodos toman dos matrices 
    * como parametros y verifican si cumplen con las condiciones 
    * necesarias para realizar la operacion correspondiente antes de 
    * realizarla. Cada operacion calcula el resultado y lo imprime en 
    * la consola.
    *
    */
// Clase para operaciones basicas entre matrices
template <typename T>
class OperacionesBasicas{ 

    public:
        // Constructor por default
        OperacionesBasicas(){}
        
        /**
        * @brief La funcion validarSumaResta toma dos matrices como parametros 
        * y verifica que tengan las mismas dimensiones para realizar operaciones 
        * de suma o resta. Si las dimensiones no coinciden, lanza una excepcion 
        * indicando que la operacion no puede realizarse.
        * 
        * @param matrizA Matriz de tipo T.
        * @param matrizB  Matriz de tipo T.
        * 
        *
        */
        // Metodo para validar la suma y resta de matrices
        void validarSumaResta(Matriz<T>&matrizA, Matriz<T>&matrizB){ 
            // Se verifica que las matrices tengan las mismas dimensiones
            if (matrizA.filasMatriz != matrizB.filasMatriz || matrizA.columnasMatriz != matrizB.columnasMatriz){ 
                throw std::invalid_argument("La operacion no puede ser realizadas, las matrices deben tener las mismas dimensiones");
            } 
        } 
        
        /**
        * @brief La funcion validarMultiplicacion toma dos matrices como parametros 
        * y verifica que tengan dimensiones compatibles para la multiplicacion. Si 
        * el numero de columnas de la matriz A no es igual al numero de filas de la 
        * matriz B, lanza una excepcion indicando que la operacion no puede realizarse.
        * 
        * @param matrizA Matriz de tipo T.
        * @param matrizB  Matriz de tipo T.
        * 
        *
        */
        // Metodo para validar la multiplicacion de matrices
        void validarMultiplicacion(Matriz<T>&matrizA, Matriz<T>&matrizB){ 
            // Se verifica que las matrices tengan dimensiones compatibles para la multiplicacion
            if (matrizA.columnasMatriz != matrizB.filasMatriz){ 
                throw std::invalid_argument("No se puede realizar la operacion, para realizarla, el numero de columnas de la matriz 1 debe ser igual al numero de filas de la matriz 2.");
            } 
        } 

        /**
        * @brief La funcion Suma, suma dos matrices, verificando primero 
        * si tienen las mismas dimensiones. Luego, crea una matriz para almacenar 
        * el resultado con las mismas dimensiones y tipo que la matriz de entrada. 
        * Posteriormente, suma cada elemento correspondiente de las matrices de entrada 
        * y almacena el resultado en la matriz resultado. Finalmente, imprime la matriz 
        * resultado en la consola
        * 
        * @param matrizA Matriz de tipo T.
        * @param matrizB  Matriz de tipo T.
        * 
        *
        */
        // Metodo para realizar la suma de matrices
        void Suma(Matriz<T>& matrizA, Matriz<T>& matrizB) {

            // Se valida la suma de matrices
            validarSumaResta(matrizA, matrizB);

            // Se crea una matriz para almacenar el resultado
            Matriz<T> resultado;
            resultado.filasMatriz = matrizA.filasMatriz;
            resultado.columnasMatriz = matrizA.columnasMatriz;
            resultado.tipo = matrizA.tipo;

            // Se suma cada elemento de las matrices y se almacena en la matriz resultado
            for (size_t i = 0; i < matrizA.matrizResultado.size(); ++i) {
                std::vector<T> filaResultado;

                for (size_t j = 0; j < matrizA.matrizResultado[i].size(); ++j) {
                    filaResultado.push_back(matrizA.matrizResultado[i][j] + matrizB.matrizResultado[i][j]);
                }
                resultado.matrizResultado.push_back(filaResultado);
            }
            // Se imprime la matriz resultado
            resultado.imprimirMatriz();
        }

        /**
        * @brief La funcion Resta, resta dos matrices, verificando primero 
        * si tienen las mismas dimensiones. Luego, crea una matriz para almacenar 
        * el resultado con las mismas dimensiones y tipo que la matriz de entrada. 
        * Posteriormente, resta cada elemento correspondiente de las matrices de entrada 
        * y almacena el resultado en la matriz resultado. Finalmente, imprime la matriz 
        * resultado en la consola
        * 
        * @param matrizA Matriz de tipo T.
        * @param matrizB  Matriz de tipo T.
        * 
        *
        */
        // Metodo para realizar la resta de matrices
        void Resta(Matriz<T>& matrizA, Matriz<T>& matrizB) {
            // Se valida la resta de matrices
            validarSumaResta(matrizA, matrizB);

            // Se crea una matriz para almacenar el resultado
            Matriz<T> resultado;
            resultado.filasMatriz = matrizA.filasMatriz;
            resultado.columnasMatriz = matrizA.columnasMatriz;
            resultado.tipo = matrizA.tipo;

            // Se resta cada elemento de las matrices y se almacena en la matriz resultado
            for (size_t i = 0; i < matrizA.matrizResultado.size(); ++i) {
                std::vector<T> filaResultado;
                for (size_t j = 0; j < matrizA.matrizResultado[i].size(); ++j) {
                    filaResultado.push_back(matrizA.matrizResultado[i][j] - matrizB.matrizResultado[i][j]);
                }
                resultado.matrizResultado.push_back(filaResultado);
            }
            // Se imprime la matriz resultado
            resultado.imprimirMatriz();
        }

        /**
        * @brief La funcion Multiplicacion valida primero si las matrices tienen 
        * dimensiones compatibles para la multiplicacion. Luego, crea una matriz 
        * para almacenar el resultado con el numero adecuado de filas y columnas. 
        * Despues, realiza la multiplicacion de matrices utilizando un bucle triple 
        * para calcular cada elemento del resultado. Si el tipo de datos es complejo, 
        * utiliza la formula de multiplicacion de numeros complejos. Finalmente, 
        * imprime la matriz resultado en la consola.
        * 
        * @param matriz1 Matriz de tipo T.
        * @param matriz2  Matriz de tipo T.
        * 
        *
        */
        // Metodo para realizar la multiplicacion de matrices
        void Multiplicacion(Matriz<T>& matriz1, Matriz<T>& matriz2) {
            // Se valida la multiplicacion de matrices
            validarMultiplicacion(matriz1, matriz2);

            // Se crea una matriz para almacenar el resultado
            Matriz<T> resultado;
            resultado.filasMatriz = matriz1.filasMatriz;
            resultado.columnasMatriz = matriz2.columnasMatriz;
            resultado.tipo = matriz1.tipo;

            // Se realiza la multiplicacion de matrices
            for (size_t i = 0; i < matriz1.filasMatriz; ++i) {
                std::vector<T> filaResultado;

                for (size_t j = 0; j < matriz2.columnasMatriz; ++j) {
                    T elemento = 0;

                    for (size_t k = 0; k < matriz1.columnasMatriz; ++k) {
                        if constexpr (std::is_same_v<T, std::complex<float>>) {
                            // Multiplicación de números complejos
                            std::complex<float> a = matriz1.matrizResultado[i][k];
                            std::complex<float> b = matriz2.matrizResultado[k][j];
                            elemento += (a.real() * b.real() - a.imag() * b.imag()) + 
                                        (a.real() * b.imag() + a.imag() * b.real()) * std::complex<float>(0, 1);
                        } else {
                            // Multiplicación para otros tipos de datos
                            elemento += matriz1.matrizResultado[i][k] * matriz2.matrizResultado[k][j];
                        }
                    }
                    filaResultado.push_back(elemento);
                }
                resultado.matrizResultado.push_back(filaResultado);
            }
            // Se imprime la matriz resultado
            resultado.imprimirMatriz();
        }
}; 


#endif // CLASES_HPP