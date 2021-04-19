#ifndef VHISTORIALVENTAS_H
#define VHISTORIALVENTAS_H
#include "Ventanas.h"

class VHistorialVentas : public HistorialDeVentas {
	
private:
	void CargarFilaVentasHistorial(int i);
protected:
	void cierra_historial( wxCloseEvent& event ) ;
	void ventana_filtrar_click( wxCommandEvent& event ) ;
	void eliminar_venta_click( wxCommandEvent& event ) ;
	void ClickGrillaVentasHistorial( wxGridEvent& event );
public:
	VHistorialVentas(wxWindow *parent=NULL);
	~VHistorialVentas();
};

#endif

