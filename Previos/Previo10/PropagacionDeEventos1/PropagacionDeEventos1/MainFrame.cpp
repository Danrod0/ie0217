#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	// Creacion de un panel que abarcara toda la ventana
	wxPanel* panel = new wxPanel(this);

	// Creacion de un boton dentro del panel
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

	// button->Bind (wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	// panel->Bind (wxEVT_BUTTON, &MainFrame::OnButtonClicked, this); 
	// Vinculacion del evento de clic de boton al metodo manejador OnButtonClicked
	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	// Creacion de la barra de estado de la ventana
	CreateStatusBar();
}

// Metodo manejador de eventos para el evento de clic de boton
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	// Muestra un mensaje en la barra de estado indicando que el boton ha sido pulsado
	wxLogStatus("Button Clicked");
}