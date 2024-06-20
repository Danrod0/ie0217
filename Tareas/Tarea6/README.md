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
  
Seguidamente se procedió a llenar la tabla de descripciones, solo que esta vez se llenaron los 15 cursos al mismo tiempo, como se puede ver en el código:  
```
INSERT INTO Descripciones (DescripcionID, CursoID, Descripcion, Dificultad) VALUES
(01, 01, 'Curso sobre administración de sistemas de información', 'Media'),
(02, 02, 'Curso sobre electrónica aplicada a la industria.', 'Dificil'),
(03, 03, 'Curso sobre la elaboración del anteproyecto del trabajo final de graduación.', 'Media'),
(04, 04, 'Curso optativo que permite elegir entre diversas áreas de interés.', 'Facil'),
(05, 05, 'Curso optativo que permite elegir entre diversas áreas de interés.', 'Facil'),
(06, 06, 'Curso sobre ciencia de datos enfocado en la estimación y pronóstico de eventos.', 'Dificil'),
(07, 07, 'Curso sobre seguridad y salud ocupacional en el entorno laboral.', 'Media'),
(08, 08, 'Curso optativo que permite elegir entre diversas áreas de interés.', 'Facil'),
(09, 09, 'Curso optativo que permite elegir entre diversas áreas de interés.', 'Facil'),
(10, 10, 'Curso sobre los principios de la ingeniería económica y su aplicación en proyectos.', 'Media'),
(11, 11, 'Curso avanzado sobre electrónica, incluyendo circuitos y dispositivos electrónicos.', 'Dificil'),
(12, 12, 'Curso introductorio sobre las máquinas eléctricas y su funcionamiento.', 'Media'),
(13, 13, 'Curso enfocado en la elaboración y gestión de proyectos eléctricos.', 'Dificil'),
(14, 14, 'Curso sobre modelos probabilísticos aplicados a señales y sistemas.', 'Media'),
(15, 15, 'Curso sobre las responsabilidades profesionales y éticas en la ingeniería eléctrica.', 'Facil');
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de la primera subida de datos a la tabla descripciones en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/ConfirmacionDatosTablaDescripciones.png)  
  
Ademas se puede observar en la siguiente imagen la tabla ya llena con los datos:  
![Segunda tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones.png)  

Por ultimo se procedió a llenar la tabla de requisitos, como se puede ver en el código:  
```
INSERT INTO Requisitos (RequisitoID, CursoID, RequisitoCursoID) VALUES
(01, 01, 10),
(02, 02, 11),
(03, 02, 12),
(04, 03, 13),
(05, 06, 14),
(06, 06, 01),
(07, 07, 15);
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de la primera subida de datos a la tabla requisitos en la consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/ConfirmacionDatosTablaRequisitos.png)  
  
Ademas se puede observar en la siguiente imagen la tabla ya llena con los datos:  
![Segunda tabla de requisitos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaRequisitos.png)  


### Agrege dos cursos nuevos y complete la informacion requerida  (Ademas se inserta la relacion de requisitos)

Primero se anadieron estos cursos a la tabla de cursos, seguidamente a la tabla de descripciones y por ultimo a la de requisitos, donde se anade la relacion de requisitos necesaria, como se muestra en el codigo:
```
-- Se anaden los dos cursos nuevecitos
INSERT INTO Cursos (CursoID, Sigla, Nombre, Semestre, Creditos) VALUES
(16, 'IE-0901', 'Introduccion a las redes neuronales', 5, 3),
(17, 'IE-0902', 'Introduccion a la computacion evolutiva', 6, 4);

INSERT INTO Descripciones (DescripcionID, CursoID, Descripcion, Dificultad) VALUES
(16, 16, 'Curso donde se introduce la teoria sobre las redes neuronales para IA', 'Media'),
(17, 17, 'Curso donde se introduce la teoria sobre la computacion evolutiva para IA', 'Dificil');

INSERT INTO Requisitos (RequisitoID, CursoID, RequisitoCursoID) VALUES
(08, 17, 16);
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de la subida de datos de los 2 cursos a las tablas consola](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/ConfirmacionDatos2CursosNuevos.png)  
  
Ademas se puede observar en la siguiente imagen la tabla de cursos ya llena con los datos de los nuevos cursos:  
![Tercera tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos3.png)  
  
Seguidamente se puede observar en la siguiente imagen la tabla de descripciones ya llena con los datos de los nuevos cursos:  
![Segunda tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones2.png)  
  
Ademas se puede observar en la siguiente imagen la tabla de requisitos ya llena con los datos de los nuevos cursos:  
![Segunda tabla de requisitos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaRequisitos2.png)  

## 3. Consultas:  
### Realiza consultas para listar todos los cursos con su sigla, nombre, semestre, creditos, descripcion y dificultad.  
Para esto se utilizo el siguiente codigo:  
```
-- Consultas para listar todos los cursos
SELECT c.Sigla, c.Nombre, c.Semestre, c.Creditos, d.Descripcion, d.Dificultad
FROM Cursos c
JOIN Descripciones d ON c.CursoID = d.CursoID;
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la consulta 1 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta1Confirmacion.png)  

Obteniendose la siguiente tabla como resultado de la consulta:  
![Tabla obtenida con la consulta 1](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta1Tabla.png)  
  
### Realiza consultas para listar todos los requisitos de un curso especifico.
Para esto se utilizo el siguiente codigo:  
```
-- Consulta requisitos curso especifico
SELECT r.RequisitoID, c1.Sigla AS Curso, c2.Sigla AS Requisito
FROM Requisitos r
JOIN Cursos c1 ON r.CursoID = c1.CursoID
JOIN Cursos c2 ON r.RequisitoCursoID = c2.CursoID
WHERE c1.Sigla = 'IE-0613';
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la consulta 2 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta2Confirmacion.png)  

Obteniendose la siguiente tabla como resultado de la consulta:  
![Tabla obtenida con la consulta 2](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta2Tabla.png)  
  
### Realizar consulta para listar los cursos que no son optativos.
Para esto se utilizo el siguiente codigo:  
```
-- Consulta para listar los cursos que no son optativos
SELECT Sigla, Nombre, Semestre, Creditos
FROM Cursos
WHERE Nombre NOT LIKE 'Optativa%';
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la consulta 3 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta3Confirmacion.png)  

Obteniendose la siguiente tabla como resultado de la consulta:  
![Tabla obtenida con la consulta 3](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta3Tabla.png)  
  
### Listar los cursos que pertenecen al semestre X
Para esto se utilizo el siguiente codigo:  
```
-- Consulta para listar los cursos del semestre 10
SELECT Sigla, Nombre, Semestre, Creditos
FROM Cursos
WHERE Semestre = 10;
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la consulta 4 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta4Confirmacion.png)  

Obteniendose la siguiente tabla como resultado de la consulta:  
![Tabla obtenida con la consulta 4](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Consulta4Tabla.png)  
  
## 4. Actualizaciones:
### Actualiza el nombre y creditos de 3 de los cursos optativos (puedes agregar cursos del plan de estudios de bachillerato para tomarlo como optativa).
Primero se actualizo la optativa 1, para esto se utilizo el siguiente codigo:  
```
-- Actualizacion Optativa 1
UPDATE Cursos
SET Nombre = 'Programación bajo plataformas abiertas', Creditos = 4
WHERE Sigla = 'IE-1';
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la actualizacion 1 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Actualizacion1Confirmacion.png)  

La siguiente tabla es la tabla de cursos antes de la actualizacion:  
![Tercera tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos3.png)  

Obteniendose la siguiente tabla como resultado de la actualizacion de la optativa 1:  
![Cuarta tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos4.png)  

Seguidamente se actualizo la optativa 2, para esto se utilizo el siguiente codigo:  
```
-- Actualizacion Optativa 2
UPDATE Cursos
SET Nombre = 'Estructuras abstractas de datos y algoritmos para ingeniería', Creditos = 4
WHERE Sigla = 'IE-2';
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la actualizacion 2 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Actualizacion2Confirmacion.png)  

La siguiente tabla es la tabla de cursos antes de la actualizacion:  
![Cuarta tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos4.png)  

Obteniendose la siguiente tabla como resultado de la actualizacion de la optativa 2:  
![Quinta tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos5.png)  

Seguidamente se actualizo la optativa 3, para esto se utilizo el siguiente codigo:  
```
-- Actualizacion Optativa 3
UPDATE Cursos
SET Nombre = 'Inteligencia artificial aplicada a la ingeniería eléctrica', Creditos = 4
WHERE Sigla = 'IE-3';
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la actualizacion 3 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Actualizacion3Confirmacion.png)  

La siguiente tabla es la tabla de cursos antes de la actualizacion:  
![Quinta tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos5.png)  

Obteniendose la siguiente tabla como resultado de la actualizacion de la optativa 3:  
![Sexta tabla de cursos](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaCursos6.png)  

### Actualiza la descripcion y dificultad de 3 cursos existentes a tu eleccion.  
Primero se actualizo la descripcion y dificultad de la optativa 1, para esto se utilizo el siguiente codigo:  
```
-- Actualizacion descripcion curso Optativa 1
UPDATE Descripciones
SET Descripcion = 'Curso donde se aprende a programar en Python y lo basico en C', Dificultad = 'Dificil'
WHERE CursoID = 04;
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la actualizacion 4 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Actualizacion4Confirmacion.png)  

La siguiente tabla es la tabla de descripciones antes de la actualizacion:  
![Segunda tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones2.png)  

Obteniendose la siguiente tabla como resultado de la actualizacion de la optativa 1:  
![Tercera tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones3.png)   

Seguidamente se actualizo la descripcion y dificultad de la optativa 2, para esto se utilizo el siguiente codigo:  
```
-- Actualizacion descripcion curso Optativa 2
UPDATE Descripciones
SET Descripcion = 'Curso donde se aprende a programar en C++ y lo basico de SQL', Dificultad = 'Dificil'
WHERE CursoID = 05;
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la actualizacion 5 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Actualizacion5Confirmacion.png)  

La siguiente tabla es la tabla de descripciones antes de la actualizacion:  
![Tercera tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones3.png)   

Obteniendose la siguiente tabla como resultado de la actualizacion de la optativa 2:  
![Cuarta tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones4.png)   

Luego se actualizo la descripcion y dificultad de la optativa 3, para esto se utilizo el siguiente codigo:  
```
-- Actualizacion descripcion curso Optativa 3
UPDATE Descripciones
SET Descripcion = 'Curso donde se aprende como se puede aplicar la IA en Ing. Electrica.', Dificultad = 'Dificil'
WHERE CursoID = 08;
```  
Donde se puede observar que esto fue realizado con exito gracias al siguiente mensaje que fue impreso en consola:  
![Confirmacion de que la actualizacion 6 fue realizada con exito](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/Actualizacion6Confirmacion.png)  

La siguiente tabla es la tabla de descripciones antes de la actualizacion:  
![Cuarta tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones4.png)   

Obteniendose la siguiente tabla como resultado de la actualizacion de la optativa 3:  
![Quinta tabla de descripciones](https://github.com/Danrod0/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaDescripciones5.png)   

