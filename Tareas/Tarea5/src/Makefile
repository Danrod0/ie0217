# Se declara el compilador a utilizar
CXX = g++

# Opciones de compilación: -Wall muestra todas las advertencias y -std=c++11 especifica el estándar de C++11
CXXFLAGS = -Wall -std=c++11

# Utilizando wildcard, se encuentran todos los archivos fuente con extensión .cpp
SOURCES = $(wildcard *.cpp)

# Se declara OBJECTS para contener los nombres de los archivos objeto generados a partir de SOURCES
OBJECTS = $(SOURCES:.cpp=.exe)

# Se declara el nombre del ejecutable final
EXECUTABLE = main.x

# Se indica que tanto 'all' como 'clean' son targets que no corresponden a archivos sino a tareas
.PHONY: all clean

# El target 'all' ejecuta los targets 'build' y 'run'
all: build run

# 'build' compila el código para generar el ejecutable
build: $(EXECUTABLE)

# Regla para construir el ejecutable a partir de los archivos objeto
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regla para generar los archivos objeto a partir de los archivos fuente
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 'run' ejecuta el contenido del ejecutable
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# 'clean' elimina los archivos generados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)