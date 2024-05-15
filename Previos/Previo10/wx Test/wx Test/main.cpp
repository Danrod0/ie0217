#include <wx/wx.h>

// Declaracion de la clase App que hereda de wxApp
class App : public wxApp {
public:
    // Metodo OnInit que se llama al iniciar la aplicacion
    bool OnInit() {
        // Creacion de una nueva ventana de tipo wxFrame
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(600, 400));

        // Creacion de un sizer de tipo wxBoxSizer con orientacion horizontal
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

        // Creacion de un objeto de tipo wxStaticText
        wxStaticText* text = new wxStaticText(window, wxID_ANY, "Well Done!\nEverything seems to be working",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

        // Configuracion del tamaño de fuente del texto
        text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        // Añadir el texto al sizer con un factor de expansion de 1 y centrado
        sizer->Add(text, 1, wxALIGN_CENTER);

        // Establecer el sizer como el sizer de la ventana
        window->SetSizer(sizer);

        // Mostrar la ventana
        window->Show();

        // Indicar que la inicializacion fue exitosa
        return true;
    }
};

// Macro para implementar la aplicacion con la clase App
wxIMPLEMENT_APP(App);