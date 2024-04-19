# Como compilar la Tarea1

```
g++ -o main.exe .\main.cpp .\Contacto.cpp .\HashTable.cpp
```

# Como ejecutar la Tarea1

```
.\main.exe
```

| Archivos  | Contenido |
| ------------- | ------------- |
| main.cpp  | Contiene el la funcion main donde se llaman las funciones  |
| Contacto.cpp  | Contiene las declaraciones de las funciones para contacto  |
| Contacto.hpp  | Contiene las firma de la estructura para contacto  |
| HashTable.cpp  | Contiene las declaraciones de las funciones  |
| HashTable.hpp  | Contiene las firmas de las funciones para la clase Hashtable  |


# Parte teorica
**Respuestas**

1. Un algoritmo es una secuencia de pasos, los cuales son lógicos y precisos para la resolución de un problema específico. Sus principales características son que es determinista, finito, definido y eficiente.

2. La principal diferencia entre un algoritmo eficiente y uno deficiente, es que el eficiente requiere una menor cantidad de recursos, como lo pueden ser el tiempo o el espacio en memoria, a diferencia de los deficientes que consumen en exceso.

3. Una estructura de datos es una forma particular para representar y organizar datos en memoria, su importancia radica en la optimización del acceso a la memoria y su facilidad de manipulación.

4. Una estructura de datos estática cuenta con un tamaño fijo, además de que es asignado durante el tiempo de compilación. En cambio, las estructuras de datos dinámicas cuentan con un tamaño variable, y es asignado durante el tiempo de ejecución.

5. La memoria dinámica es una parte de la memoria del sistema que se utiliza para almacenar datos de forma temporal durante la ejecución de un programa. Se gestiona utilizando los operadores new y delete para asignar y liberar memoria. Algunas operaciones son:
new[] y delete[]: Son los operadores que se utilizan para asignar y liberar memoria para arreglos dinámicos.
malloc(), calloc() y realloc(): Son funciones que se utilizan para asignar y reasignar memoria dinámica. 
free(): Se utiliza para liberar la memoria asignada dinámicamente con malloc(), calloc() o realloc().

6. Las principales ventajas de la utilización de la memoria dinámica en comparación con la estática es una mayor flexibilidad en el manejo de los datos, además de un uso mucho mas eficiente de la memoria. Sus desventajas en comparación es que puede haber una fragmentación de memoria, además de que es mucho mas complejo que trabajar la memoria estática.

7. Un árbol binario es una estructura de datos jerárquica no lineal que cuenta con nodos y ramas. Cada nodo principal/nodo interno tiene dos hijos como maximo o ningún hijo.

8. Una cola es una estructura de datos tipo FIFO, o sea, el primer dato en entrar es el primer dato en salir. Puede ser utilizado para el procesamiento de solicitudes, o en las impresoras para la cola de impresión.

9. La cola sigue el principio de FIFO, el primero en entrar, serán los primeros en salir, en cambio la pila sigue el principio de LIFO, lo cual es que el ultimo en entrar es el primero en salir.

10. El algoritmo de inserción (insert) en una tabla hash funciona para insertar un elemento a una tabla hash, además que calcula el índice de la tabla y resuelve colisiones si fuera necesario.

11. Una función de dispersión es un tipo de función que toma una entrada y la mapea a un valor de rango fijo. Son importantes porque permiten asignar claves a ubicaciones especificas en las tablas Hash, además de facilitar la búsqueda y recuperación mucho más eficiente de datos.

12. En una tabla hash bien implementada, se puede tener una complejidad O(1) en promedio. Esto es importante porque significa que la búsqueda es muy rápida.

13. Para poder realizar una operación push es una pila debemos primero agregar el elemento a la parte superior de la pila, luego actualizar el puntero de la parte superior.

14. La complejidad temporal de las operaciones de push y pop en una pila es de O(1), esto debido a que las dos operaciones solo afectan al elemento superior de la pila.

15. Una lista enlazada es una estructura de datos donde los nodos se encuentran conectados mediante punteros. Tiene algunas ventajas como que cuenta con un tamaño dinámico, o sea, puede crecer o disminuirlo, además de que tiene una facilidad y gran eficiencia a la hora de realizar inserciones o eliminaciones. Asimismo tiene algunas desventajas, como que utiliza una mayor cantidad de memoria, además de que el acceso es mas lento cuando se trabaja con arreglos.

16. Un nodo en una lista enlazada consta de dos partes, un dato, el cual es el valor que se almacena en el nodo, y un puntero al siguiente nodo, el cual como su nombre lo indica es un puntero que apunta a la dirección del siguiente nodo.

17. Una lista enlazada simple es en la que cada nodo tiene un puntero al siguiente, mientras que una lista doblemente enlazada acá cada nodo cuenta con un puntero al siguiente nodo y al anterior.

18. Para realizar una eliminación de un nodo en una lista se deben actualizar los punteros para saltar al nodo que se desea eliminar, luego se tiene que liberar la memoria ocupada.

19. El algoritmo de recorrido (traversal) en un árbol binario puede funcionar de 3 distintas maneras:
Preorden: Raíz -> Izquierda -> Derecha
En orden: Izquierda -> Raíz -> Derecha
Postorden: Izquierda -> Derecha -> Raíz

20. Si el árbol binario es un árbol  balanceado, todos los recorridos cuentan con una complejidad O(n), donde depende de la cantidad de nodos que seria n.

21. La notación Big O (O) representa al peor caso o limite superior de la complejidad temporal, a diferencia de la notación Omega (), la cual representa lo contrario, o sea, el mejor caso o limite inferior de complejidad temporal. Algunos ejemplos podrían ser:
O(log n) (peor caso): Búsqueda eficiente en una lista ordenada.
Omega(1) (mejor caso): Si el elemento buscado está en la primera posición.

# Que es el formato Markdown?

Es un lenguaje de marcado ligero, este facilita la escritua de texto en la web.
Se utiliza para darle formato a documentos de texto de manera facil y eficiente.

# Link de Nelify
https://662262173d383500a04cc74f--dreamy-gingersnap-1f61d2.netlify.app/