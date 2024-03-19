#include <iostream>  // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

// Definición de la estructura Person, es como POO
struct Person
{
    char name[50];
    int age;
    float salary;
};

int main()
{
    Person p1; // Crea p1 y lo hace tipo Person
    

    // Solicita al usuario que ingrese los datos y los guarda en los atributos de p1
    cout << "Enter Full name: ";
    cin.get(p1.name, 50);
    cout << "Enter age: ";
    cin>> p1.age;
    cout << "Enter salary: ";
    cin >> p1.salary;
    
    // Imprime los datos de p1
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary;
    
    return 0;
}