# Breakout Room 4   
**Integrantes**  
Luis Felipe Agüero Peralta C10089  
José Ignacio Sáenz Díaz C27032  
María José Guevara Matarrita C13476  
Daniel Rodríguez Rivas B96719  

# Base de datos hospital  
  
**Pregunta 1** : Display patient's full name, height in the units feet rounded to 1 decimal, weight in the unit pounds rounded to 0 decimals, birth_date,gender non abbreviated. Convert CM to feet by dividing by 30.48. Convert KG to pounds by multiplying by 2.205.  
```
-- Luis Felipe
-- De la base hospital la penúltima pregunta de dificultad media
-- La pregunta: Display patient's full name, height in the units feet rounded to 1 decimal,
-- weight in the unit pounds rounded to 0 decimals,
-- birth_date,gender non abbreviated.
--Convert CM to feet by dividing by 30.48.
-- Convert KG to pounds by multiplying by 2.205.
SELECT 
    -- Aqui concatenamos el primer nombre y el apellido del paciente con un espacio entre ellos
    CONCAT(first_name, ' ', last_name) AS 'patient_name',
    
    -- Convertimos la altura de centímetros a pies y redondeamos a una decimal
    ROUND(height / 30.48, 1) AS 'height_feet', 
    
    -- Convertimos el peso de kilogramos a libras y redondeamos a cero decimales
    ROUND(weight * 2.205, 0) AS 'weight_pounds',
    
    -- Mostramos la fecha de nacimiento del paciente
    birth_date,
    
    -- Convertimos el género abreviado a su forma completa
    CASE 
        WHEN gender = 'M' THEN 'MALE'  -- Si el género es 'M', lo cambiamos a 'MALE'
        ELSE 'FEMALE'                  -- Si el género es cualquier otro valor (asumido como 'F'), lo cambiamos a 'FEMALE'
    END AS 'gender_type'
FROM patients;
```
  
**Pregunta 2** : Show patient_id, first_name, last_name from patients whose does not have any records in the admissions table. (Their patient_id does not exist in any admissions.patient_id rows.)  
```
-- Luis Felipe
-- De la base hospital la última pregunta de dificultad media
-- La pregunta: Show patient_id, first_name, last_name from patients whose does not have any records in the admissions table. (Their
-- patient_id does not exist in any admissions.patient_id rows.)

SELECT
  -- Seleccionamos el ID del paciente
  patients.patient_id,
  
  -- Seleccionamos el primer nombre del paciente
  first_name,
  
  -- Seleccionamos el apellido del paciente
  last_name
FROM patients
WHERE patients.patient_id NOT IN (
    -- Subconsulta: seleccionamos el ID del paciente de la tabla 'admissions'
    SELECT admissions.patient_id
    FROM admissions
)

```
  
**Pregunta 3** : Sort the province names in ascending order in such a way that the province 'Ontario' is always on top.  
```
-- Luis Felipe
-- De la base hospital la penúltima pregunta de dificultad dificil 
-- La pregunta: Sort the province names in ascending order in such a way that the province 'Ontario' is always on top.
SELECT 
  -- Seleccionamos el nombre de la provincia
  province_name
FROM 
  province_names
ORDER BY 
  -- Utilizamos una cláusula CASE para darle prioridad a la provincia 'Ontario', asignándole el valor 0
  (CASE WHEN province_name = 'Ontario' THEN 0 ELSE 1 END),
  
  -- Luego ordenamos el resto de las provincias alfabéticamente
  province_name;

```
  
**Pregunta 4** : We need a breakdown for the total amount of admissions each doctor has started each year. Show the doctor_id, doctor_full_name, specialty, year, total_admissions for that year.  
```
-- Luis Felipe
-- De la base hospital la última pregunta de dificultad dificil 
-- La pregunta: We need a breakdown for the total amount of admissions each doctor has started each year. Show the doctor_id, 
-- doctor_full_name, specialty, year, total_admissions for that year.
SELECT
  -- Seleccionamos el ID del doctor y lo etiquetamos como 'doctor_id'
  d.doctor_id AS doctor_id,
  
  -- Concatenamos el primer nombre y el apellido del doctor, y lo etiquetamos como 'doctor_name'
  CONCAT(d.first_name, ' ', d.last_name) AS doctor_name,
  
  -- Seleccionamos la especialidad del doctor
  d.specialty,
  
  -- Extraemos el año de la fecha de admisión y lo etiquetamos como 'selected_year'
  YEAR(a.admission_date) AS selected_year,
  
  -- Contamos el número de admisiones y lo etiquetamos como 'total_admissions'
  COUNT(*) AS total_admissions
FROM 
  doctors AS d
  -- Realizamos para esta parte una unión izquierda con la tabla 'admissions' usando 'doctor_id' y 'attending_doctor_id'
  LEFT JOIN admissions AS a ON d.doctor_id = a.attending_doctor_id
GROUP BY
  -- Agrupamos por 'doctor_name' y 'selected_year'
  doctor_name,
  selected_year
ORDER BY 
  -- Ordenamos por 'doctor_id' y 'selected_year'
  doctor_id, 
  selected_year;

```
  
**Pregunta 5** : Write a query to find list of patients first_name, last_name, and allergies where allergies are not null and are from the city of 'Hamilton'  
```  
/*
Jose Ignacio Saenz Diaz
Se seleccionan nombre, apellidos y alergias
Se utiliza  WHERE para evaluar las condiciones y AND para forzar a que se cumplan ambas
*/
SELECT first_name, last_name, allergies
FROM patients
WHERE city = 'Hamilton' AND allergies is not null;

```
  
**Pregunta 6** : Show unique first names from the patients table which only occurs once in the list.  
```
/*
Jose Ignacio Saenz Diaz
Se selecciona el primer nombre de la tabla pacientes
Se agrupan los nombres que son iguales
Se despliegan únicamente los que la cuenta sea 1 utilizando Having count
*/
SELECT first_name
FROM patients
GROUP BY first_name
HAVING COUNT(*) = 1;
```
  
**Pregunta 7** : Show unique birth years from patients and order them by ascending  
```
/*
Jose Ignacio Saenz Diaz
Se seleccionan los distintos anios de nacimiento y se separan utilizando YEAR
Se utiliza la funcion ORDER BY para escoger el orden ascendente
*/
SELECT DISTINCT YEAR(birth_date) AS birth_year
FROM patients
ORDER BY birth_year ASC;
```
  
**Pregunta 8** : Show patient_id, weight, height, isObese from the patients table. Display isObese as a boolean 0 or 1. Obese is defined as weight(kg)/(height(m)2) >= 30. weight is in units kg. height is in units cm  
```
/*
Jose Ignacio Saenz Diaz
Se utiliza Case para evaluar el IMC. Si el IMC es mayor a 30, el paciente es obeso
Si no, no lo es.
Para este condicional, se utiliza THEN y ELSE, donde THEN declara lo que pasa si
se cumple y ELSE si no
*/
SELECT 
    patient_id, 
    weight, 
    height,
    CASE 
        WHEN (weight / (height / 100.0) / (height / 100.0)) >= 30 THEN 1 
        ELSE 0 
    END AS isObese
FROM 
    patients;
```
  
# Base de datos northwind  

**Pregunta 9** : Show all the contact_name, address, city of all customers which are not from 'Germany', 'Mexico', 'Spain'  
```
/*
Daniel Rodriguez
Primero se utiliza SELECT para seleccionar las columnas a mostrar
luego con el FROM se selecciona de que tabla se va a obtener la info
por ultimo se utiliza el WHERE para filtrar en la tabla y luego un
NOT IN para buscar los datos que no se encuentren en la lista y
asi poder realizar el filtrado.
*/

SELECT contact_name, address, city 
FROM customers
where country not in ('Germany', 'Mexico', 'Spain')
``` 
  
**Pregunta 10** : Show the ProductName, CompanyName, CategoryName from the products, suppliers, and categories table  
```
/*
Daniel Rodriguez
Primero se utiliza SELECT para seleccionar las columnas a mostrar, se utiliza
el formato p."" para seleccionar las columnas de distintas tablas
luego con el FROM se selecciona de que tabla se va a obtener la info
por ultimo se utiliza JOIN donde se selecciona otra tabla de donde se sacara
la informacion para poder completar la final, esto primero seleccinando la tabla
luego con un ON dice cual columna y con que hace match en la de products.
*/

SELECT p.product_name, s.company_name, c.category_name
from products p
join suppliers s ON s.supplier_id = p.supplier_id
join categories c ON c.category_id = p.category_id
```
  
**Pregunta 11** : Show the city, company_name, contact_name from the customers and suppliers table merged together.
Create a column which contains 'customers' or 'suppliers' depending on the table it came from.  
```
/*
Daniel Rodriguez
Primero se utiliza SELECT para seleccionar las columnas a mostrar,
ademas, la parte de 'customers' AS relationship crea una nueva columna
la cual llama relationship y da el valor predeterminado de customers
luego con el FROM se selecciona de que tabla se va a obtener la info
seguidamente se utiliza UNION para combinar los resultados de las dos
tablas, para volver a utilizar SELECT, en este caso se da un valor
predeterminado de suppliers a la columna que habia sido creada con
anterioridad.
*/

SELECT City, company_name, contact_name, 'customers' AS relationship
from customers
union
select city, company_name, contact_name, 'suppliers'
from suppliers
```
  
**Pregunta 12** :Show the employee's first_name and last_name, a "num_orders" column with a count of the orders taken, and a column called "Shipped" that displays "On Time" if the order shipped_date is less or equal to the required_date, "Late" if the order shipped late.

Order by employee last_name, then by first_name, and then descending by number of orders.  
```
/*
Daniel Rodriguez
Primero se utiliza SELECT para seleccionar las columnas a mostrar,
ademas, cuenta el numero de pedidos con COUNT para cada empleado y crea 
una columna llamada num_orders, tambien con el CASE crea un pequeno
algoritmo donde revisa si los pedidos los enviaron a tiempo o no
dependiendo de si si o si no, lo agrega al final en una columna
llamada shipped, luego con el FROM se selecciona de que tabla 
se va a obtener la info seguidamente con el JOIN une la tabla
orders con la employers, por ultimo con el GROUP agrupa los
resultados por nombre, apellido y estado de envio y con el 
ORDER los ordena por apellido y nombre alfabeticamente y el numero
de pedido de manera descendente con el DESC
*/

SELECT
	e.first_name,
    e.last_name,
    count(o.order_id) AS num_orders,
    (
      case
      	when o.shipped_date <= o.required_date then 'On time'
      	else 'Late'
      end
    )
    as shipped
from orders o
join employees e on e.employee_id = o.employee_id
group by e.first_name, e.last_name, shipped
order by e.last_name, e.first_name, num_orders DESC
```
  
**Pregunta 13** : Show the category_name and the average product unit price for each category
rounded to 2 decimal places.  
```
/*
María José Guevara Matarrita
1. `SELECT`: Es la cláusula que se usa para especificar las columnas que queremos incluir en el resultado de la consulta.
`c.category_name`: Se selecciona el nombre de la categoría desde la tabla de categorías (con el alias `c`).
`round(avg(p.unit_price),2) as average_unit_price`: Calcula el precio unitario promedio de los productos en cada categoría redondeado a 2 decimales y lo renombra como `average_unit_price` en el resultado.

2. FROM products p:
- `FROM products p`: Especifica que la consulta está utilizando la tabla `products`, a la que se le asigna el alias `p`.

3. JOIN categories c On c.category_id = p.Category_id:
- `JOIN categories c`: Realiza una unión (join) con la tabla `categories`, asignándole el alias `c`.
- `On c.category_id = p.Category_id`: Define la condición de la unión, que es donde el `category_id` en la tabla `categories` coincide con el `Category_id` en la tabla `products`.

4. GROUP BY c.category_name:
- `GROUP BY c.category_name`: Agrupa los resultados por el nombre de la categoría. Esto significa que todas las filas con el mismo `category_name` se agruparán juntas para aplicar funciones de agregación como `avg`.
*/

-- Dificultad: medio, segunda pregunta 
-- Base de datos: northwind.db 
-- Show the category_name and the average product unit price for each category
rounded to 2 decimal places.

SELECT c.category_name, round(avg(p.unit_price),2) as average_unit_price
FROM products p
JOIN categories c On c.category_id = p.Category_id
GROUP BY c.category_name
```
  
**Pregunta 14** : Show order_date, shipped_date, customer_id, Freight of all orders placed on 2018 Feb 26  
```
/*
María José Guevara Matarrita
1. SELECT order_date, shipped_date, customer_id, freight:
- `SELECT`: Es la cláusula que se usa para especificar las columnas que queremos incluir en el resultado de la consulta.
- `order_date`: Selecciona la columna que contiene la fecha de la orden.
- `shipped_date`: Selecciona la columna que contiene la fecha de envío de la orden.
- `customer_id`: Selecciona la columna que contiene el identificador del cliente.
- `freight`: Selecciona la columna que contiene el costo de envío de la orden.

2. FROM orders:
- `FROM orders`: Especifica que la consulta está utilizando la tabla `orders`.

3. WHERE order_date = '2018-02-26':
- `WHERE`: Filtra las filas que se incluirán en el resultado de la consulta.
- `order_date = '2018-02-26'`: Es la condición del filtro, que selecciona únicamente las filas donde la columna `order_date` tiene el valor '2018-02-26'.

-- Dificultad: facil, tercera pregunta 
-- Base de datos: northwind.db 
-- Show order_date, shipped_date, customer_id, Freight of all orders placed on 2018 Feb 26

SELECT order_date, shipped_date, customer_id, freight
FROM orders
WHERE order_date = '2018-02-26';
```
  
**Pregunta 15** : Show order_date, shipped_date, customer_id, Freight of all orders placed on 2018 Feb 26  
```
/*
María José Guevara Matarrita
1. SELECT city, company_name, contact_name:
- `SELECT`: Es la cláusula que se usa para especificar las columnas que queremos incluir en el resultado de la consulta.
- `city`: Selecciona la columna que contiene el nombre de la ciudad.
- `company_name`: Selecciona la columna que contiene el nombre de la empresa.
- `contact_name`: Selecciona la columna que contiene el nombre del contacto.

2. FROM customers:
   - `FROM customers`: Especifica que la consulta está utilizando la tabla `customers`.

3. WHERE city LIKE '%L%':
- `WHERE`: Filtra las filas que se incluirán en el resultado de la consulta.
- `city LIKE '%L%'`: Es la condición del filtro, que selecciona únicamente las filas donde la columna `city` contiene la letra 'L' en cualquier posición. El símbolo `%` es un comodín que representa cero o más caracteres.

4. ORDER BY contact_name:
- `ORDER BY`: Ordena los resultados.
- `contact_name`: Especifica que los resultados deben ordenarse por el nombre de contacto (`contact_name`) en orden ascendente por defecto.
*/

-- Dificultad: facil, sexta pregunta 
-- Base de datos: northwind.db 
-- Show order_date, shipped_date, customer_id, Freight of all orders placed on 2018 Feb 26

SELECT city, company_name, contact_name
FROM customers
WHERE city LIKE '%L%'
ORDER BY contact_name
```
  
**Pregunta 16** : Show the first_name, last_name. hire_date of the most recently hired employee.  
```
-- Realizado por María José Guevara Matarrita C13476

*/
1. SELECT:
La cláusula SELECT se utiliza para especificar las columnas que se desean incluir en el resultado de la consulta.

2. first_name:
Selecciona la columna first_name de la tabla employees. Esto incluirá el primer nombre de cada empleado en el resultado.

3. last_name:
Selecciona la columna last_name de la tabla employees. Esto incluirá el apellido de cada empleado en el resultado.

4. max(hire_date) as hire_date:
max(hire_date): Calcula la fecha de contratación más reciente (máxima) de los empleados.
as hire_date: Renombra esta fecha máxima como hire_date en el resultado.

*/

-- Dificultad: facil, octava pregunta 
-- Base de datos: northwind.db 
-- Show the first_name, last_name. hire_date of the most recently hired employee.


select 
    first_name,
    last_name,
    max(hire_date) as hire_date
  from employees
```
