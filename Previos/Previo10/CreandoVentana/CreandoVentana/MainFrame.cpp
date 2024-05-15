#include "MainFrame.hpp"
#include <wx/wx.h> // Incluye la biblioteca principal de wxWidgets
#include <wx/spinctrl.h> // Incluye la biblioteca para controles de giro

// MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {}

// Constructor de MainFrame que recibe un titulo
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    // Crea un panel para contener los controles
    wxPanel* panel = new wxPanel(this);

    // Crea un boton con etiqueta "Button" en el panel
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

    // Crea un checkbox con etiqueta "CheckBox" en el panel
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox",
        wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

    // Crea un texto estatico con la etiqueta "StaticText - NOT editable" en el panel
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable",
        wxPoint(0, 150), wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
    staticText->SetBackgroundColour(*wxLIGHT_GREY); // Establece el color de fondo del texto estatico

    // Crea un campo de texto editable con la etiqueta "TextCtrl - editable" en el panel
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable",
        wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD); // wxTE_PASSWORD para ocultar el texto

    // Crea un control deslizante con valores de 0 a 100, valor inicial 25 en el panel
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

    // Crea una barra de progreso con valor inicial 50 en el panel
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(590, 205), wxSize(-1, 125), wxGA_VERTICAL);
    gauge->SetValue(50); // Establece el valor de la barra de progreso

    // Crea una lista de opciones para elegir
    wxArrayString choices;
    choices.Add("Item A");
    choices.Add("Item B");
    choices.Add("Item C");

    // Crea un control de seleccion con las opciones en el panel
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
    choice->Select(0); // Selecciona el primer elemento por defecto

    // Crea un control de giro para seleccionar numeros en el panel
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

    // Crea una lista de opciones multiples
    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

    // Crea un conjunto de botones de opcion con las opciones en el panel
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox",
        wxPoint(555, 450), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);
}