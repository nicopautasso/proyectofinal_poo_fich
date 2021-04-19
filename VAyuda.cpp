#include "VAyuda.h"
#include <wx/html/htmlwin.h>
#include <cstdlib>
#include "icono.xpm"
#include <wx/icon.h>

VAyuda::VAyuda(wxWindow *parent) : VentanaAyuda(parent) {
	SetIcon(wxIcon(icono_xpm));
	texto_ayuda->LoadPage("ayuda.html");
}

VAyuda::~VAyuda() {
	
}

