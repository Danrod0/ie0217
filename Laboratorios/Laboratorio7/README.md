# Instrucciones para compilar
Encontrandose en la carpeta Laboratorio7 correr el siguiente comando en la consola.
```
mingw32-make
```

# Intruccion para correr
Encontrandose en la carpeta Laboratorio7 correr el siguiente comando en la consola.
```
./bin/textprocessor -f data/input.txt -o data/output.txt -search "foo" -replace "bar"
```

**Warning:** No existe la carpeta de data porque el prodesor dijo que el la agregaba para hacer las pruebas con el codigo.

**Warning2:** Cuando realice el programa, el Makefile no me tiro ningun error de como estaba escrito originalmente, por lo que no se le hizo ningun cambio.

| **Archivos**  | **Contenido** |
| ------------- | ------------- |
| main.cpp  | Contiene el la funcion main donde se llaman las funciones |
| text_processor.cpp  | Contiene las declaraciones de las funciones |
| text_processor.hpp  | Contiene las firmas de las funciones  |
| Makefile  | Facilita la compilacion del programa |
| Carpeta src  | Contiene los archivos del programa |
| Carpeta bin  | Contiene las archivos binarios generados |
| Carpeta data  | Contendria los achivos de entrada y salida |