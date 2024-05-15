#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    // Constructor de la clase MainFrame que recibe el titulo de la ventana como parametro
    MainFrame(const wxString& title);

private:
    // Metodo manejador de eventos para el evento de pulsacion de tecla
    void OnKeyEvent(wxKeyEvent& evt);
};