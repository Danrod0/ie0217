#include "MainFrame.hpp" 
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Crea un panel dentro de la ventana principal
    wxPanel* panel = new wxPanel(this);
    // Crea un boton en el panel
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));

    // Crea una barra de estado y la almacena en statusBar
    wxStatusBar* statusBar = CreateStatusBar();
    // Habilita el doble bufer para la barra de estado para evitar el parpadeo
    statusBar->SetDoubleBuffered(true);

    // Vincula el evento de movimiento del mouse al manejador de eventos OnMouseEvent
    panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
    // Vincula el evento de movimiento del mouse al manejador de eventos OnMouseEvent para el boton
    button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
    // Obtiene la posicion del mouse en la ventana
    wxPoint mousePos = evt.GetPosition();
    // Convierte la posicion del mouse de coordenadas de pantalla a coordenadas relativas al cliente de la ventana principal
    mousePos = this->ScreenToClient(mousePos);
    // Formatea un mensaje con la posicion del mouse
    wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
    // Muestra el mensaje en la barra de estado
    wxLogStatus(message);
}