#include <wx/wx.h>

// Declaracion de la clase MainFrame que hereda de wxFrame
class MainFrame : public wxFrame {
public:
    // Constructor de la clase MainFrame que toma un wxString como titulo de la ventana
    MainFrame(const wxString& title);

private:
    // Declaracion de los metodos de manejo de eventos
    void OnAnyButtonClicked(wxCommandEvent& evt);
    void OnButton1Clicked(wxCommandEvent& evt);
    void OnButton2Clicked(wxCommandEvent& evt);
};