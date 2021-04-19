#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "Ventanas.h"

class VPrincipal : public VentanaPrincipal {
	
private:
	void CargarFilaVentasDia(int i, int fila);
	void ActualizarFilaVentasDia(int i);
	void CargarListArticulos(int i);
protected:
	void click_acercade( wxCommandEvent& event ) ;
	void click_ayuda( wxCommandEvent& event ) ;
	void CambiaTamanio( wxSizeEvent& event ) ;
	void cant_onwindow( wxMouseEvent& event ) ;
	void ClickIrStock( wxCommandEvent& event ) ;
	void articulo_ongrid( wxGridEvent& event ) ;
	void cant_ontext( wxCommandEvent& event ) ;
	void ClickStock( wxCommandEvent& event );
	void ClickBuscarArt( wxCommandEvent& event );
	void ClickVender( wxCommandEvent& event );
	void ClickGrillaVentasHoy( wxGridEvent& event );
	void ClickVerHistorial( wxCommandEvent& event );
	void ActualizarPrecioFinal();
public:
	VPrincipal(wxWindow *parent=NULL);
	~VPrincipal();
};

#endif

