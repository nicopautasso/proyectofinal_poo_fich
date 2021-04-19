#ifndef VPOCOSTOCK_H
#define VPOCOSTOCK_H
#include "Ventanas.h"
#include <string>

class VPocoStock : public VentanaAlertas {
	
private:
	void CargarGrillaPocosArticulos(int i, int fila);
protected:
	void cierra_alerta( wxCloseEvent& event ) ;
	void click_agregar_stock( wxCommandEvent& event ) ;
public:
	VPocoStock(wxWindow *parent=NULL);
	~VPocoStock();
};

#endif

