# Como compilar la Tarea1

g++ -o ahorcado.exe .\main.cpp .\funciones.cpp

# Como ejecutar la Tarea1

.\ahorcado.exe

# Parte teorica

**Respuestas**

1. La principal diferencia entre C y C++ es que C no soporta programación orientada a objetos, a diferencia de C++.

2. 
git init: Se utiliza para inicializar repositorios en el Git local.
git add: Se utiliza para añadir archivos al área de preparación para realizar el próximo commit.
git commit: Se utiliza para guardar los cambios que se encuentran en el área de preparación en el repositorio.
git push: Se utiliza para subir los cambios realizados en el commit al repositorio remoto.
git clone: Se utiliza para copiar el repositorio Git remoto en la maquina local.
git branch: Se utiliza para crear, enlistar o eliminar ramas.
git merge: Se utiliza para combinar los cambios de diferentes ramas.

3. Git es un sistema que sirve para el control de versiones de software, además de permitir colaborar a los desarrolladores en proyectos de software.

4. Un conflicto de fusión en Git sucede cuando aparecen cambios incompatibles en las mismas líneas de un archivo. Para resolverlo se debe editar manualmente los archivos y marcando los conflictos como resueltos.

5. Un archivo tipo .gitignore especifica que tipo de archivo o directorio debe ignorar Git, cuando se hace un push un commit y un pull, el archivo se encarga de que estos comandos ignoren los tipos de archivos especificados.

6. Una solicitud de extracción en GitHub sirve para que los usuarios puedan proponer cambios al repositorio, cuando estos cambios son propuestos, se debe realizar una revisión para definir si pueden integrados o no.

7. Un lenguaje compilado traduce a código maquina antes de su ejecución, en cambio los interpretados traducen a código maquina durante su ejecución. Un lenguaje compilado es mas optimo a la hora de compilar sistemas operativos. Y un lenguaje interpretado puede ser mas optimo a la hora de compilar aplicaciones web.

8. Un linker en lenguaje de programación compilado es un software que combina varios archivos de código objeto y bibliotecas, esto con el fin de crear el archivo ejecutable.

9. Primero se deben modificar los archivos, o sea, realizar los cambios, seguidamente se debe realizar un git add para agregarlos al área de preparación, ya ahí se realiza un git commit para guardar los cambios en el repositorio, y por último un git pull para cargarlos al repositorio remoto.

10. Inicializar una variable es cuando a la hora de declararla o cuando ya se encuentra declarada, se le da un valor. Declarar una variable es especificar el tipo de variable que será, darle un nombre, pero no asignarle un valor aún. 

11. En C++ existe la sobrecarga de funciones, que lo que hace es que puedan existir varias funciones con el mismo nombre, solo que con diferentes tipos o distintas cantidades de argumentos. Esto puede dar una comprensión más fácil del código, y que las funciones puedan ser adaptadas según el uso necesitado.

12. Un puntero es una variable la cual guarda la dirección a memoria de otro valor. Un ejemplo en la vida real podría ser en un GPS un puntero que apunte a la ubicación actual, permitiendo así actualizar y seguir esta ubicación en tiempo real.

13. Un Branch en Git es como una versión que se crea, independiente al código, esta permite modificar el código para realizar algún cambio, sin afectar al código original. 

14. Un bucle do-while ejecuta el código antes de verificar la condición del while, a diferencia de un bucle while, el cual primero verifica la condición del while para poder correr el código.

15. Dividir el código ayuda en gran manera a la organización de este, además de facilitar una colaboración y mejora la compilación. Un archivo .hpp contiene las declaraciones de las funciones, un .cpp la implementación de estas, por último, el main.cpp es la entrada al programa.

16. En C++, las variables son guardadas en la memoria RAM, las variables locales son guardadas en la pila y solo son accesibles dentro de la función, a diferencia de las variables globales, estas son guardadas en una sección fija, y pueden ser llamadas desde cualquier parte del programa.

17. En primer lugar, pasar parámetros por valor realiza una copia del argumento. Segundo, por referencia se puede modificar el argumento original. Por último, por puntero, este pasa la dirección de memoria de la variable, permitiendo también su modificación.

18. Cuando se usa un puntero para apuntar a un arreglo, apunta inicialmente a la primera dirección del arreglo, y para poder acceder a todos los datos de este, se puede incrementar el puntero para recorrerlo.

19. Un puntero doble en C++ es utilizado para apuntar a un puntero ya hecho, esto puede llegar a ser muy útil en la utilización de matrices dinámicas.

20. #indef es utilizado para evitar que un archivo se incluya múltiples veces, se asegura que un bloque de un código solo sea compilado una vez si no había sido definido previamente.

21. El puntero this-> en C++, es un puntero que solo es accesible dentro de funciones tipo class, struct o unión, permitiendo acceder a sus miembros de la clase.

22. En C++, un arreglo tiene un tamaño fijo, o sea que ya se encuentra definido, y su almacenamiento es contiguo, en cambio en una lista su tamaño puede cambiar y sus elementos no necesariamente se encuentran contiguos en memoria.

23. Un memory leak es cuando un programa realiza una reserva de memoria dinámica, pero no la libera de la manera correcta, lo que deriva a un agotamiento de la memoria del sistema, afectando tiempos de ejecución y rendimiento del sistema.

# Que es el formato Markdown?

Es un lenguaje de marcado ligero, este facilita la escritua de texto en la web.
Se utiliza para darle formato a documentos de texto de manera facil y eficiente.

# Link de Nelify

https://660d1fdabb7e39b75be0b54d--dreamy-gingersnap-1f61d2.netlify.app/