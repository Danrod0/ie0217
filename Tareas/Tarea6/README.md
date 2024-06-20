# Parte teorica
**Respuestas**
  
1. Una base de datos relacional es un tipo de base de datos que se utiliza para organizar los datos en tablas que pueden ser relacionadas entre si. Cada una de estas tablas esta compuesta por filas y columnas, donde cada fila representa un registro y cada columna un atributo de este. Sus características fundamentales son: cuenta con una estructura tabular para almacenar los datos; llaves, esto para el uso de claves primarias y foráneas para la identificación y relación de datos; Operaciones CRUD, para realizar operaciones sobre los datos.
  
2. Una clave primaria es un campo que identifica de manera única cada registro en una tabla, no puede contener valores nulos y su valor debe ser único. Por otro lado una clave candidata es un campo que también puede servir como clave primaria, la diferencia con la primaria es que pueden haber múltiples candidatas pero solo una primaria.
  
3. Una clave foránea es un campo en una tabla que se utiliza para establecer y reforzar un vínculo entre los datos de una tabla a otra. Una clave foránea apunta a la clave primaria de otra tabla. Las claves foráneas aseguran que los valores en una tabla correspondan a valores válidos en otra tabla, esto con el din de mantener la integridad referencial en una base de datos.
  
4. Una transacción en el contexto de bases de datos es una unidad de trabajo que se ejecuta de manera completa o no se ejecuta en absoluto. Debe cumplir las siguientes propiedades ACID: Atomicidad (Atomicity), debe ser completada en su totalidad o no realizarse del todo; Consistencia (Consistency), debe llevar al sistema de un estado válido a otro estado válido; Aislamiento (Isolation), las operaciones deben realizarse de manera aislada; Durabilidad (Durability), si la transacción se hizo, los cambios deben ser permanentes.
  
5. Una vista (view) en SQL es una consulta almacenada que se puede tratar como una tabla virtual. O sea, no hay almacenamiento de datos, solo puede consultarlos. Cuenta con beneficios como una simplificación a la hora de realizar consultas, da seguridad a la base de datos, ya que restringe su acceso. Algunas limitaciones con las que cuenta es que pueden ser mas lentas que tablas normales y no todas las vistas son actualizables.
  
6. La normalización de bases de datos es el proceso de organizar los datos para reducir la redundancia y mejorar la integridad de los datos. Existen distintas formas normales:
  
        Primera forma normal: Elimina grupos repetitivos de datos.
        
        Segunda forma normal: Elimina datos redundantes y se asegura de que cada campo dependa de la clave primaria.
        
        Tercera forma normal: Elimina campos que no dependen directamente de la clave primaria.
        
        Cuarta forma normal: Elimina dependencias multivaluadas.
        
        Quinta forma normal: Trata la descomposición de relaciones más complejas.
  
7. Los índices en SQL son una estructura de datos que mejora la velocidad de las operaciones de consulta en una tabla. Pueden tener impactos positivos como una aceleración en las búsquedas y en las consultas con `SELECT`. También hay impactos negativos como ralentizar operaciones de inserción o actualización y eliminación.
  
8. SQL Injection es una técnica de ataque en la que un atacante inserta o manipula consultas SQL a través de la entrada de datos para ejecutar comandos no autorizados. Algunas de las mejores practicas para prevenir este tipo de ataque pueden ser: utilizar consultas parametrizadas, utilizar procedimientos almacenados, validar y sanitizar la entrada del usuario, limitar los privilegios de la base de datos.
  
9. Los procedimientos almacenados son bloques de código SQL que se almacenan y se ejecutan en el servidor de la base de datos. Pueden mejorar la eficiencia ya que reducen el tráfico de red al ejecutar múltiples operaciones en una sola llamada. Pueden mejorar la seguridad ya que permiten controlar el acceso y limitar las operaciones que los usuarios pueden realizar.
  
10. Uno a uno: Se implementa usando una clave primaria que también es clave foránea en otra tabla. Consideraciones para tener en cuenta: hay que asegurarse de que las tablas siempre tengan una correspondencia uno a uno.  
Uno a muchos: Se implementa mediante una clave foránea en la tabla "muchos" que apunta a la clave primaria en la tabla "uno", esta es la relación más común. Consideraciones para tener en cuenta: Se debe garantizar la integridad referencial y las restricciones de claves foráneas.  
Muchos a muchos: Se implementa utilizando una tabla intermedia que contiene claves foráneas las cuales apuntan a las claves primarias de las dos tablas relacionadas. Consideraciones para tener en cuenta: se debe asegurar que la tabla intermedia tenga restricciones adecuadas para mantener la integridad referencial.  
  
  

# Parte Practica: **Pasos a Seguir**  
## 1. Creación de la base de datos y tablas:  
Primero se crea la base de datos con el siguiente comando:  
```
CREATE DATABASE IF NOT EXISTS plan_estudios_db;
```
Donde al correr el comando se obtuvo la siguiente respuesta en la consola:
![Base de datos creada](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Basededatoscreada.png)  

Luego se definió y se creó la tabla de cursos utilizando la siguiente parte del código:  

```
USE plan_estudios_db;

CREATE TABLE Cursos (
    CursoID INT AUTO_INCREMENT,
    Sigla VARCHAR(10) NOT NULL,
    Nombre VARCHAR(100) NOT NULL,
    Semestre INT NOT NULL,
    Creditos INT NOT NULL,
    PRIMARY KEY (CursoID),
    UNIQUE (Sigla),
    UNIQUE (Nombre)
);
```
Donde se obtuvo la siguiente salida en la consola:
![Confirmacion de la creacion de la tabla Cursos en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/CreacionTablaCursos.png)  

Y se puede ver la confirmación de la creación de la tabla a la hora de abrir la misma como se puede ver en la siguiente imagen:
![Tabla cursos vacia recien creada](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/CreacionTablaCursos2.png)  

  
Seguidamente se definió y se creó la tabla de requisitos utilizando la siguiente parte del código:  
```
CREATE TABLE IF NOT EXISTS Requisitos (
    RequisitoID INT AUTO_INCREMENT,
    CursoID INT NOT NULL,
    RequisitoCursoID INT NOT NULL,
    PRIMARY KEY (RequisitoID),
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID),
    FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID)
);
``` 
Donde se obtuvo la siguiente salida en la consola:  
![Confirmacion de la creacion de la tabla Requisito en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/CreacionTablaRequisitos.png)  

Y se puede ver la confirmación de la creación de la tabla a la hora de abrir la misma como se puede ver en la siguiente imagen:  
![Tabla Requisito vacia recien creada](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/CreacionTablaRequisitos2.png)  
  

Por ultimo se definió y se creó la tabla de descripciones utilizando la siguiente parte del código:  
```
CREATE TABLE IF NOT EXISTS Descripciones (
    DescripcionID INT AUTO_INCREMENT,
    CursoID INT NOT NULL,
    Descripcion TEXT NOT NULL,
    Dificultad ENUM('Facil', 'Media', 'Dificil') NOT NULL,
    PRIMARY KEY (DescripcionID),
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID)
);
``` 
Donde se obtuvo la siguiente salida en la consola:  
![Confirmacion de la creacion de la tabla Descripciones en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/CreacionTablaDescripciones.png)  

Y se puede ver la confirmación de la creación de la tabla a la hora de abrir la misma como se puede ver en la siguiente imagen:  
![Tabla Descripciones vacia recien creada](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/CreacionTablaDescripciones2.png)  

## 2. Inserción de datos:

### Inserte la informacion basica de los cursos y sus requisitos segun el plan de estudios proporcionado.

Primero para esta parte se ingresaron los datos a la tabla de cursos, de los cursos del plan de estudios proporcionado:  
```
INSERT INTO Cursos (CursoID, Sigla, Nombre, Semestre, Creditos) VALUES
(01, 'IE-0579', 'Administración de sistemas', 9, 4),
(02, 'IE-0613', 'Electrónica industrial', 9, 4),
(03, 'IE-0599', 'Anteproyecto de TFG', 9, 4),
(04, 'IE-1', 'Optativa I', 9, 3),
(05, 'IE-2', 'Optativa II', 9, 3),
(06, 'IE-0679', 'Ciencia de datos para la est. y pron. de eventos', 10, 3),
(07, 'IE-0541', 'Seguridad ocupacional', 10, 3),
(08, 'IE-3', 'Optativa III', 10, 3),
(09, 'IE-4', 'Optativa IV', 10, 3);
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de la primer subida de datos a la tabla cursos en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/ConfirmacionDatosTablaCursos.png)  
  
Ademas se puede observar en la siguiente imagen la tabla ya llena con los datos:  
![Primera tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos1.png)  
  
Luego me di cuenta que hicieron falta cursos por lo que se subieron igual a la tabla de cursos:
```
INSERT INTO Cursos (CursoID, Sigla, Nombre, Semestre, Creditos) VALUES
(10, 'IE-0479	', 'INGENIERÍA ECONÓMICA', 8, 3),
(11, 'IE-0413', 'ELECTRÓNICA II', 5, 3),
(12, 'IE-0315', 'MÁQUINAS ELÉCTRICAS I', 6, 3),
(13, 'IE-0499', 'PROYECTO ELÉCTRICO', 10, 3),
(14, 'IE-0405', 'MODELOS PROBABILÍSTICOS DE SEÑALES Y SISTEMAS', 6, 3),
(15, 'IE-0501', 'RESPONSABILIDADES EN EL EJERCICIO PROFESIONAL DE LA INGENIERÍA ELÉCTRICA', 6, 1);
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de la segunda subida de datos a la tabla cursos en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/ConfirmacionDatosTablaCursos2.png)  
  
Ademas se puede observar en la siguiente imagen la tabla ya llena con los datos:  
![Segunda tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos2.png)  
