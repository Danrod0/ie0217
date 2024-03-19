#include <iostream>  // Libreria
#include <cstring> // Libreria

using namespace std; // Para poder llamar a todo lo que incluye std

// Definición de la estructura Books, es como POO
struct Books {
    char title[50]; 
    char author[50]; 
    char subject[100]; 
    int book_id;
};

int main() {
    struct Books Book1; // Declaración de Book1 de tipo Books
    struct Books Book2; // Declaración de Book2 de tipo Books
    
    // Especificaciones del libro 1 
    strcpy(Book1.title, "Learn C++ Programming"); // strcpy copia el string que se inserta
    strcpy(Book1.author, "Chand Miyan"); 
    strcpy(Book1.subject, "C++ Programming");
    Book1.book_id = 6495407;
    
    // Especificaciones del libro 2
    strcpy(Book2.title, "Telecom Billing"); 
    strcpy(Book2.author, "Yakit Singha"); 
    strcpy(Book2.subject, "Telecom"); 
    Book2.book_id = 6495700;
    
    // Imprime la información del libro 1
    cout << "Book 1 title: " << Book1.title <<endl;
    cout << "Book 1 author: " << Book1.author <<endl;
    cout << "Book 1 subject: " << Book1.subject <<endl;
    cout << "Book 1 id: " << Book1.book_id <<endl;
    
    // Imprime la información del libro 2
    cout << "Book 2 title : " << Book2.title <<endl;
    cout << "Book 2 author : " << Book2.author <<endl;
    cout << "Book 2 subject: " << Book2.subject <<endl;
    cout << "Book 2 id: " << Book2.book_id <<endl;
    
    return 0;
}