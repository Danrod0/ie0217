#include "MainFrame.hpp"
#include <wx/wx.h>

// Definici�n de la tabla de eventos para MainFrame
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
    EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
    EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()

// Implementaci�n del constructor de MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Creaci�n del panel principal
    wxPanel* panel = new wxPanel(this);

    // Creaci�n de los controles: bot�n, slider y textCtrl
    wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
    wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
    wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

    // Creaci�n de la barra de estado
    CreateStatusBar();
}

// Implementacion de la funcion de manejo de eventos para el boton
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
    wxLogStatus("Button Clicked");
}

// Implementacion de la funcion de manejo de eventos para el slider
void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
    wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
    wxLogStatus(str);
}

// Implementacion de la funcion de manejo de eventos para el textCtrl
void MainFrame::OnTextChanged(wxCommandEvent& evt) {
    wxString str = wxString::Format("Text: %s", evt.GetString());
    wxLogStatus(str);
}