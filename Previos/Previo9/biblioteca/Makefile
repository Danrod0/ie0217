# Makefile para compilar un programa C++ con múltiples archivos y clases
# Especifica el nombre del programa de salida 
TARGET = gestion_biblioteca.exe

# Objetivo predeterminado
all: $(TARGET)

# Especifica el compilador de C++ a utilizar 
CXX = g++

# Son las opciones de compilacion, que incluyen -Wall para habilitar todos los mensajes de advertencia y -std=c++11 para habilitar el estándar C++11. 
CXXFLAGS = -Wall -std=c++11

# Es una lista de archivos fuente
SOURCES = libro.cpp biblioteca.cpp main.cpp

# Es una lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES: .cpp=.exe)

# Regla para compilar los archivos fuente en archivos objeto 
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto 
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos generados
.PHONY: clean
clean:
	del $(TARGET) $(OBJECTS)