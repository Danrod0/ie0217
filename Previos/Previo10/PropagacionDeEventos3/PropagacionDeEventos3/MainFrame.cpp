#include "MainFrame.hpp" 
#include <wx/wx.h>

// Implementacion del constructor de la clase MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Se crea un panel dentro de la ventana principal
    wxPanel* panel = new wxPanel(this);

    // Se crean dos botones dentro del panel
    wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
    wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

    // Se vincula el evento de clic de cualquier boton al metodo OnAnyButtonClicked de esta clase
    this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
    // Se vincula el evento de clic del boton 1 al metodo OnButton1Clicked de esta clase
    button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
    // Se vincula el evento de clic del boton 2 al metodo OnButton2Clicked de esta clase
    button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

    // Se crea una barra de estado en la parte inferior de la ventana
    CreateStatusBar();
}

// Implementacion del metodo OnAnyButtonClicked, manejador de eventos para el clic de cualquier boton
void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
    // Se muestra un mensaje en la consola indicando que se hizo clic en un boton
    wxLogMessage("Button Clicked");
}

// Implementacion del metodo OnButton1Clicked, manejador de eventos para el clic del boton 1
void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
    // Se muestra un mensaje en la barra de estado indicando que se hizo clic en el boton 1
    wxLogStatus("Button 1 Clicked");
    // Se llama a Skip para permitir que otros manejadores de eventos procesen este evento tambien
    evt.Skip();
}

// Implementacion del metodo OnButton2Clicked, manejador de eventos para el clic del boton 2
void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
    // Se muestra un mensaje en la barra de estado indicando que se hizo clic en el boton 2
    wxLogStatus("Button 2 Clicked");
}