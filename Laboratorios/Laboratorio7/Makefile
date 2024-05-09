CXX = g++ # El compilador de C++ a utilizar
CXXFLAGS = -Wall -std=c++11 # Opciones de compilacion para el compilador de C++
LDFLAGS = -lstdc++fs # Opciones de enlace para el enlazador

SRC_DIR = src # Directorio que contiene los archivos fuente .cpp y .hpp
BIN_DIR = bin # Directorio donde se colocaran los archivos binarios ejecutables

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) # Lista de archivos fuente .cpp en el directorio de origen
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.exe) # Lista de archivos binarios ejecutables en el directorio binario, derivados de los archivos fuente
EXECUTABLE = $(BIN_DIR)/textprocessor # Nombre del archivo ejecutable final

all: $(EXECUTABLE) # Regla para construir el ejecutable final

$(EXECUTABLE): $(OBJECTS) # Regla para construir el ejecutable final
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp # Regla para construir cada archivo binario ejecutable
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: # Regla para eliminar todos los archivos binarios ejecutables
	del $(BIN_DIR)
