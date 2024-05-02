#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

template <typename T>
class Stadistics {
    public:
        // Constructor que recibe un vector de datos const
        Stadistics(const std::vector<T>& data) : data(data){
            // Se verifica si el vector de datos esta vacio
            if(data.empty()){
                throw std::invalid_argument("La lista de datos debe contener elementos");
            }
        }

        // Metodo para calcular la media de los datos
        double mean() const {
            T sum = 0;
            // Se calcula la suma de los elementos en el vector
            for (const T& value : data){
                sum += value;
            }
            // Se calcula la media dividiendo la suma por la cantidad de elementos
            return static_cast<double>(sum) / data.size();
        }

        // Metodo para calcular la desviacion estandar de los datos
        double standardDeviation() const{
            double meanValue = mean();
            double sumSquares = 0;

            // Se calcula la suma de los cuadrados de las diferencias entre cada dato y la media
            for(const T& value : data){
                sumSquares += (value -meanValue) * (value -meanValue);
            }
            // Se calcula la raiz cuadrada de la suma de los cuadrados dividida por la cantidad de elementos
            return std::sqrt(sumSquares / data.size());
        }
    
    private:
        std::vector<T> data; // Vector de datos tipo T (variable)
};

int main() {
    try{
        // Se crea una instancia de Stadistics con un vector de enteros
        std::vector<int> intData = {1, 2, 3, 4, 5};

        Stadistics<int> statsInts(intData);

        std::cout << "Media de intData: " << statsInts.mean() << std::endl;
        std::cout << "Desviacion estandar de intData: " << statsInts.standardDeviation() << std::endl;
        
        /********************************************************/
        // Se crea una instancia de Stadistics con un vector de doubles
        std::vector<double> doubleData = {1.5, 2.5, 3.5, 4.5, 5.5};

        Stadistics<double> statsDouble(doubleData);

        std::cout << "Media de doubleData: " << statsDouble.mean() << std::endl;
        std::cout << "Desviacion estandar de doubleData: " << statsDouble.standardDeviation() << std::endl;

        /*******************************************************/
        // Se crea una instancia de Stadistics con un vector vacio para poder probar la excepcion
        std::vector<int> emptyData;
        Stadistics<int> statsEmpty(emptyData);

    } catch (const std::invalid_argument& e) {
        // Se captura para manejar la excepcion de vector vacio
        std::cerr << "Excepcion encontrada: " << e.what() << std::endl;
    }

    return 0;
}
