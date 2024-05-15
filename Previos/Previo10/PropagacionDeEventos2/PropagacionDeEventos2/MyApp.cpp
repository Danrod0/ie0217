#include "MyApp.hpp"
#include "MainFrame.hpp"

// Implementa la aplicacion utilizando la macro wxIMPLEMENT_APP
wxIMPLEMENT_APP(App);

// Metodo OnInit para inicializar la aplicacion
bool App::OnInit() {
    // Crea una instancia de la clase MainFrame con el titulo "C++ GUI"
    MainFrame* mainFrame = new MainFrame("C++ GUI");

    // Establece el tamanio del cliente de la ventana principal en 800x600 pixeles
    mainFrame->SetClientSize(800, 600);

    // Centra la ventana principal en la pantalla
    mainFrame->Center();

    // Muestra la ventana principal
    mainFrame->Show();

    return true;
}