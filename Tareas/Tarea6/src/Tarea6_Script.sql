CREATE DATABASE IF NOT EXISTS plan_estudios_db;

USE plan_estudios_db;

CREATE TABLE IF NOT EXISTS Cursos (
    CursoID INT AUTO_INCREMENT,
    Sigla VARCHAR(10) NOT NULL,
    Nombre VARCHAR(100) NOT NULL,
    Semestre INT NOT NULL,
    Creditos INT NOT NULL,
    PRIMARY KEY (CursoID),
    UNIQUE (Sigla),
    UNIQUE (Nombre)
);


CREATE TABLE IF NOT EXISTS Requisitos (
    RequisitoID INT AUTO_INCREMENT,
    CursoID INT NOT NULL,
    RequisitoCursoID INT NOT NULL,
    PRIMARY KEY (RequisitoID),
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID),
    FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID)
);

CREATE TABLE IF NOT EXISTS Descripciones (
    DescripcionID INT AUTO_INCREMENT,
    CursoID INT NOT NULL,
    Descripcion TEXT NOT NULL,
    Dificultad ENUM('Facil', 'Media', 'Dificil') NOT NULL,
    PRIMARY KEY (DescripcionID),
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID)
);

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

INSERT INTO Cursos (CursoID, Sigla, Nombre, Semestre, Creditos) VALUES
(10, 'IE-0479	', 'INGENIERÍA ECONÓMICA', 8, 3),
(11, 'IE-0413', 'ELECTRÓNICA II', 5, 3),
(12, 'IE-0315', 'MÁQUINAS ELÉCTRICAS I', 6, 3),
(13, 'IE-0499', 'PROYECTO ELÉCTRICO', 10, 3),
(14, 'IE-0405', 'MODELOS PROBABILÍSTICOS DE SEÑALES Y SISTEMAS', 6, 3),
(15, 'IE-0501', 'RESPONSABILIDADES EN EL EJERCICIO PROFESIONAL DE LA INGENIERÍA ELÉCTRICA', 6, 1);

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

INSERT INTO Requisitos (RequisitoID, CursoID, RequisitoCursoID) VALUES
(01, 01, 10),
(02, 02, 11),
(03, 02, 12),
(04, 03, 13),
(05, 06, 14),
(06, 06, 01),
(07, 07, 15);

-- Se anaden los dos cursos nuevecitos
INSERT INTO Cursos (CursoID, Sigla, Nombre, Semestre, Creditos) VALUES
(16, 'IE-0901', 'Introduccion a las redes neuronales', 5, 3),
(17, 'IE-0902', 'Introduccion a la computacion evolutiva', 6, 4);

INSERT INTO Descripciones (DescripcionID, CursoID, Descripcion, Dificultad) VALUES
(16, 16, 'Curso donde se introduce la teoria sobre las redes neuronales para IA', 'Media'),
(17, 17, 'Curso donde se introduce la teoria sobre la computacion evolutiva para IA', 'Dificil');

INSERT INTO Requisitos (RequisitoID, CursoID, RequisitoCursoID) VALUES
(08, 17, 16);

-- Consultas para listar todos los cursos
SELECT c.Sigla, c.Nombre, c.Semestre, c.Creditos, d.Descripcion, d.Dificultad
FROM Cursos c
JOIN Descripciones d ON c.CursoID = d.CursoID;

-- Consulta requisitos curso especifico
SELECT r.RequisitoID, c1.Sigla AS Curso, c2.Sigla AS Requisito
FROM Requisitos r
JOIN Cursos c1 ON r.CursoID = c1.CursoID
JOIN Cursos c2 ON r.RequisitoCursoID = c2.CursoID
WHERE c1.Sigla = 'IE-0613';

-- Consulta para listar los cursos que no son optativos
SELECT Sigla, Nombre, Semestre, Creditos
FROM Cursos
WHERE Nombre NOT LIKE 'Optativa%';

-- Consulta para listar los cursos del semestre 10
SELECT Sigla, Nombre, Semestre, Creditos
FROM Cursos
WHERE Semestre = 10;

-- Actualizacion Optativa 1
UPDATE Cursos
SET Nombre = 'Programación bajo plataformas abiertas', Creditos = 4
WHERE Sigla = 'IE-1';

-- Actualizacion Optativa 2
UPDATE Cursos
SET Nombre = 'Estructuras abstractas de datos y algoritmos para ingeniería', Creditos = 4
WHERE Sigla = 'IE-2';

-- Actualizacion Optativa 3
UPDATE Cursos
SET Nombre = 'Inteligencia artificial aplicada a la ingeniería eléctrica', Creditos = 4
WHERE Sigla = 'IE-3';

-- Actualizacion descripcion curso Optativa 1
UPDATE Descripciones
SET Descripcion = 'Curso donde se aprende a programar en Python y lo basico en C', Dificultad = 'Dificil'
WHERE CursoID = 04;

-- Actualizacion descripcion curso Optativa 2
UPDATE Descripciones
SET Descripcion = 'Curso donde se aprende a programar en C++ y lo basico de SQL', Dificultad = 'Dificil'
WHERE CursoID = 05;

-- Actualizacion descripcion curso Optativa 3
UPDATE Descripciones
SET Descripcion = 'Curso donde se aprende como se puede aplicar la IA en Ing. Electrica.', Dificultad = 'Dificil'
WHERE CursoID = 08;
 
 SET SQL_SAFE_UPDATES = 0;
-- Elimina un curso inventado y 2 cursos del plan
-- 1 Curso inventado
DELETE FROM Descripciones
WHERE CursoID = 16;
DELETE FROM Requisitos
WHERE CursoID = 16 OR RequisitoCursoID = 16;
DELETE FROM Cursos
WHERE CursoID = 16;

-- 2
DELETE FROM Descripciones
WHERE CursoID = 07;
DELETE FROM Requisitos
WHERE CursoID = 07 OR RequisitoCursoID = 07;
DELETE FROM Cursos
WHERE CursoID = 07;

-- 3
DELETE FROM Descripciones
WHERE CursoID = 09;
DELETE FROM Requisitos
WHERE CursoID = 09 OR RequisitoCursoID = 09;
DELETE FROM Cursos
WHERE CursoID = 09;

SET SQL_SAFE_UPDATES = 1;

-- Eliminar requisitos específicos de 2 cursos existentes
-- Eliminando requisitos del curso Administración de sistemas
DELETE FROM Requisitos
WHERE CursoID = 01 AND RequisitoCursoID = 10;

-- Eliminando requisitos del curso Anteproyecto de TFG
DELETE FROM Requisitos
WHERE CursoID = 03 AND RequisitoCursoID = 13;