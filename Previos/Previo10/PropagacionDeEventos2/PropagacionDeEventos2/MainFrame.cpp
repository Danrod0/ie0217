#include "MainFrame.hpp"
#include <wx/wx.h>

// Implementacion del constructor de la clase MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Se crea un panel dentro de la ventana principal
    wxPanel* panel = new wxPanel(this);

    // Se crean dos botones dentro del panel
    wxButton* button = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
    wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

    // Se vincula el evento de clic de boton al metodo OnButtonClicked de esta clase
    this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    // Se crea una barra de estado en la parte inferior de la ventana
    CreateStatusBar();
}

// Implementacion del metodo OnButtonClicked, manejador de eventos para el clic de boton
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
    // Se muestra un mensaje en la barra de estado indicando que se hizo clic en el boton
    wxLogStatus("Button Clicked");
}