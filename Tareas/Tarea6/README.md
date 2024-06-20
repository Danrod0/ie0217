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
