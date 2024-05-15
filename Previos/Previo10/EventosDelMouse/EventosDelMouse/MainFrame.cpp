#include "MainFrame.hpp" 
#include <wx/wx.h>

// Implementacion del constructor de la clase MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Crea un panel dentro de la ventana principal
    wxPanel* panel = new wxPanel(this);

    // Crea una barra de estado en la parte inferior de la ventana
    CreateStatusBar();

    // Vincula el evento de clic izquierdo del mouse al manejador de eventos OnMouseEvent
    panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
}

// Implementacion del manejador de eventos de mouse
void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
    // Obtiene la posicion del mouse en la ventana
    wxPoint mousePos = evt.GetPosition();
    // Formatea un mensaje con la posicion del mouse
    wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
    // Muestra el mensaje en la barra de estado
    wxLogStatus(message);
}