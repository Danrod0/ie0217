#include "MainFrame.hpp" 
#include <wx/wx.h>

// Constructor de la clase MainFrame que recibe el titulo de la ventana como parametro
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Creacion de un panel que abarcara toda la ventana
    wxPanel* panel = new wxPanel(this);

    // Creacion de dos botones dentro del panel
    wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100));
    wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));

    // Vinculacion del evento de pulsacion de tecla al metodo manejador OnKeyEvent
    panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);

    // Creacion de la barra de estado de la ventana
    CreateStatusBar();
}

// Metodo manejador de eventos para el evento de pulsacion de tecla
void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
    // Obtencion del caracter de la tecla pulsada
    wxChar keyChar = evt.GetUnicodeKey();

    // Verificacion de si el caracter obtenido es WXK_NONE (no es un caracter imprimible)
    if (keyChar == WXK_NONE) {
        // Si no es un caracter imprimible, se obtiene el codigo numerico de la tecla
        int keyCode = evt.GetKeyCode();
        // Se muestra un mensaje en la barra de estado con el codigo numerico de la tecla pulsada
        wxLogStatus("Key Event %d", keyCode);
    }
    else {
        // Si es un caracter imprimible, se muestra el caracter en la barra de estado
        wxLogStatus("Key Event %c", keyChar);
    }
}