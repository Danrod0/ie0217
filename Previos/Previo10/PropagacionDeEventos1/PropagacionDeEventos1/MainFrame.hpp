#include <wx/wx.h>

// Declaracion de la clase MainFrame que hereda de wxFrame
class MainFrame : public wxFrame {
public:
    // Constructor que recibe el titulo de la ventana como parametro
    MainFrame(const wxString& title);

private:
    // Metodo manejador de eventos para el evento de clic de boton
    void OnButtonClicked(wxCommandEvent& evt);
};