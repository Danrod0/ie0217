#include <wx/wx.h>

// Definicion de la clase App que hereda de wxApp
class App : public wxApp {
public:
    // Declaracion del metodo OnInit, que funciona como main
    bool OnInit();
};