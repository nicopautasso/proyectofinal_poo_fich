#include "VConfirmaElimArt.h"

VConfirmaElimArt::VConfirmaElimArt(wxWindow *parent) : VentanaConfirmar(parent) {
	texto_desea_eliminar->SetLabel("�Est� seguro que desea eliminar el art�culo?");
}

VConfirmaElimArt::~VConfirmaElimArt() {
	
}

void VConfirmaElimArt::no_elimina_click( wxCommandEvent& event )  {
	EndModal(0);
}

void VConfirmaElimArt::si_elimina_click( wxCommandEvent& event )  {
	EndModal(1);
}

