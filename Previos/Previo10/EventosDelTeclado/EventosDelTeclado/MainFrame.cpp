#include "MainFrame.hpp" 
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Crea un panel dentro de la ventana principal
    wxPanel* panel = new wxPanel(this);
    // Crea una barra de estado
    CreateStatusBar();
    // Vincula el evento de pulsacion de tecla al manejador de eventos OnKeyEvent
    panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
    // Obtiene el caracter Unicode de la tecla pulsada
    wxChar keyChar = evt.GetUnicodeKey();

    if (keyChar == WXK_NONE) {
        // Si el caracter Unicode es WXK_NONE, significa que se presiono una tecla sin un caracter asociado, si pasa esto, se obtiene el codigo de la tecla
        int keyCode = evt.GetKeyCode();
        // Muestra un mensaje en la barra de estado con el codigo de la tecla
        wxLogStatus("Key Event %d", keyCode);
    }
    else {
        // Si se presiono una tecla con un caracter asociado, se muestra el caracter en la barra de estado
        wxLogStatus("Key Event %c", keyChar);
    }
}