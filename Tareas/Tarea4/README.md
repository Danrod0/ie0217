# Como compilar la Tarea4

```
g++ -o main.exe .\main.cpp .\funciones.cpp .\clases.cpp
```

# Como ejecutar la Tarea4

```
.\main.exe
```

| Archivos  | Contenido |
| ------------- | ------------- |
| main.cpp  | Contiene el la funcion main donde se llaman las funciones, y se encuentra el menu del programa |
| clases.cpp  | Contiene las declaraciones de las funciones sin template  |
| clases.hpp  | Contiene las las declaraciones de las clases template |
| funciones.cpp  | Contiene las declaraciones de las funcion seleccionarOperador  |
| funciones.hpp  | Contiene las firmas de las funcion seleccionarOperador  |


# Parte teorica
**Respuestas**

1. Las templates enC++ permiten a la creación de funciones y clases que pueden funcionar con cualquier tipo de dato. Esto utilizando los parámetros de template T, que hace la tarea tipo un comodin, actuando dependiendo del tipo de dato que se seleccione.
Un ejemplo puede ser:
```
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b; // Selecciona el numero mayor
}

// Uso del template
int main() {
    int i = max(15, 5); // Devuelve 15
    double d = max(12.55, 1.5); // Devuelve 12.55
}
```

2. La sobrecarga de funciones con plantillas en C++ se da realizando la definición de varias funciones con el mismo nombre, per, estas contienen distintos conjuntos de parámetros o tipos de parámetros. A la hora de compilar el programa, el compilador se encarga de seleccionar la función dependiendo de los argumentos de la misma.

3. Las templates se pueden utilizar en la definición de clases ya que permiten definir una estructura de la clase que puede llegar a ser operada con cualquier tipo de dato. Lo cual es muy conveniente a la hora de trabajar con objetos como vectores, pilas, matrices.

4. Para el manejo de excepciones en C++ se utilizan los bloques `try`, `catch` y `throw`.
`try`: contiene el código que puede generar una excepción.
`catch`: se utiliza para capturar y manejar la excepción.
`throw`: se usa para lanzar una excepción cuando se detecta una condición de error.

5. `std::runtime_error`: Se utiliza para errores que solo pueden ser detectados durante la ejecución.
`std::logic_error`: Indica un error en la lógica del programa, como un argumento inválido.
`std::out_of_range`: Se lanza cuando se intenta acceder a un elemento fuera de los límites de un contenedor.

6. Una política de manejo de excepciones es un conjunto de directrices de como un código de un programa debería tratar las excepciones y errores. Es muy importante porque da un punto de vista coherente y predecible para el manejo de errores, facilitando de manera significativa la depuración y mantenimiento del código.

7. La palabra clave noexcept tiene como propósito indicar que una función no lanzara excepciones. Se utiliza para mejorar la eficiencia, esto porque permite al compilador realizar optimizaciones, ya que no necesita realizar manejo de excepciones, se utiliza a la par de la definición de una función.

8. `std::logic_error` representa errores de lógica del programa, estos pueden ser previstos antes de la compilación del mismo, mientras que `std::runtime_error` representa errores que solo pueden ser detectados mientas se corre el programa.

9. Cuando una excepción no es capturada, el programa termina de manera abrupta y llama a la función `std::terminate()`, la cual detiene la ejecución del programa.

10. `std::vector`: Es dinámico y permite acceso aleatorio rápido. Útil para listas que cambian de tamaño.
`std::list`: Es una lista doblemente enlazada, buena para inserciones y eliminaciones rápidas en cualquier punto.
`std::map`: Se encuentra basado en un árbol balanceado, proporciona acceso ordenado por clave. Ideal para diccionarios con búsquedas eficientes.
`std::set`: Son un conjunto de elementos únicos ordenados. Sirve para operaciones de conjunto como unión e intersección.
`std::unordered_map`: Es una hash table que permite acceso rápido a elementos por clave, sin ordenar. Útil para búsquedas eficientes sin necesidad de orden.

11. Los iteradores en la STL son objetos que apuntan a elementos dentro de los contenedores STL, además de permitir recorrerlos. Su función es muy parecida a la de los punteros.

12. `std::sort`: Ordena elementos en un rango. Se puede utilizar junto con `std::vector` para ordenar números.
`std::find`: Busca un elemento en un rango. Útil para buscar y encontrar si un valor existe en un contenedor.
`std::accumulate`: Calcula la suma de un rango de elementos. Se puede utilizar para sumar todos los elementos de un `std::vector`.

13. Un algoritmo personalizado puede ser utilizado con la STL definiendo funciones que operen sobre rangos de iteradores.


# Que es el formato Markdown?

Es un lenguaje de marcado ligero, este facilita la escritua de texto en la web.
Se utiliza para darle formato a documentos de texto de manera facil y eficiente.

# Link de Nelify
https://663bf70963a69810f8649317--lambent-torte-25f479.netlify.app/