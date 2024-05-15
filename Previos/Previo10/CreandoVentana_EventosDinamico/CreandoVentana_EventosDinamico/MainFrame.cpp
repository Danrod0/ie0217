#include "MainFrame.hpp" 
#include <wx/wx.h>


// Implementacion del constructor de la clase MainFrame
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Creacion de un panel que actuara como contenedor de los controles
    wxPanel* panel = new wxPanel(this);

    // Creacion de un boton
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

    // Creacion de un control deslizante (slider)
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));

    // Creacion de un control de texto
    wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

    // Asociacion de eventos a los controles
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
    text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

    // Desasociacion de un evento especifico del boton
    button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    // Creacion de una barra de estado
    CreateStatusBar();
}

// Implementacion de la funcion de manejo de eventos para el clic del boton
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
    // Registro de un mensaje en la barra de estado
    wxLogStatus("Button Clicked");
}

// Implementacion de la funcion de manejo de eventos para el cambio en el slider
void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
    // Formato del mensaje con el valor actual del slider
    wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
    // Registro del mensaje en la barra de estado
    wxLogStatus(str);
}

// Implementacion de la funcion de manejo de eventos para el cambio en el texto
void MainFrame::OnTextChanged(wxCommandEvent& evt) {
    // Formato del mensaje con el texto actual
    wxString str = wxString::Format("Text: %s", evt.GetString());
    // Registro del mensaje en la barra de estado
    wxLogStatus(str);
}