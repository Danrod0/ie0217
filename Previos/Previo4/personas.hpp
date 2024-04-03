#ifndef PERSONA_H  // Se evita la inclusion multiple
#define PERSONA_H

#include <string> 

using namespace std; 

// Se declara la clase Persona
class Persona {
    private:
        string nombre; // Atributo privado para almacenar el nombre de la persona
        int edad;      // Atributo privado para almacenar la edad de la persona

    public:
        // Constructor de la clase Persona que recibe un nombre y una edad como argumentos
        Persona(string nombre, int edad);

        // Métodos para obtener el nombre y la edad de la persona
        string getNombre();
        int getEdad();

        // Método para establecer la edad de la persona
        void setEdad(int edad);
};

#endif // Fin