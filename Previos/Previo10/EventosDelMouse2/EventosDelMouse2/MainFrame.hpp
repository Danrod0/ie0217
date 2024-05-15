#include <wx/wx.h>

// Declaracion de la clase MainFrame que hereda de wxFrame
class MainFrame : public wxFrame {
public:
    // Constructor de la clase MainFrame que recibe un titulo
    MainFrame(const wxString& title);

private:
    // Declaracion de la funcion de manejo de eventos del mouse
    void OnMouseEvent(wxMouseEvent& evt);
};