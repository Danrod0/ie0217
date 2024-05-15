#include <wx/wx.h>

// Declaracion de la clase MainFrame que hereda de wxFrame
class MainFrame : public wxFrame {
public:
    // Declaracion del constructor que recibe un titulo
    MainFrame(const wxString& title);

private:
    // Declaracion de las funciones de manejo de eventos
    void OnButtonClicked(wxCommandEvent& evt);
    void OnSliderChanged(wxCommandEvent& evt);
    void OnTextChanged(wxCommandEvent& evt);

    // Declaracion de la tabla de eventos
    wxDECLARE_EVENT_TABLE();
};