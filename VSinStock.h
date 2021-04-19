#ifndef VSINSTOCK_H
#define VSINSTOCK_H
#include "Ventanas.h"

class VSinStock : public VentanaAlertas {
	
private:
	void CargarGrillaSinArticulos(int i, int fila);
protected:
	void cierra_alerta( wxCloseEvent& event ) ;
	void CierraVentAlerta( wxCloseEvent& event ) ;
	void click_agregar_stock( wxCommandEvent& event ) ;
	
public:
	VSinStock(wxWindow *parent=NULL);
	~VSinStock();
};

#endif

