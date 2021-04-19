#include "VConfirmaElimVenta.h"

VConfirmaElimVenta::VConfirmaElimVenta(wxWindow *parent) : VentanaConfirmar(parent) {
	texto_desea_eliminar->SetLabel("¿Está seguro que desea eliminar la venta?");
}

VConfirmaElimVenta::~VConfirmaElimVenta() {
	
}

void VConfirmaElimVenta::no_elimina_click( wxCommandEvent& event )  {
	EndModal(0);
}

void VConfirmaElimVenta::si_elimina_click( wxCommandEvent& event )  {
	EndModal(1);
}

