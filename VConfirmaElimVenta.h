#ifndef VCONFIRMAELIMVENTA_H
#define VCONFIRMAELIMVENTA_H
#include "Ventanas.h"

class VConfirmaElimVenta : public VentanaConfirmar {
	
private:
	
protected:
	void no_elimina_click( wxCommandEvent& event ) ;
	void si_elimina_click( wxCommandEvent& event ) ;	
public:
	VConfirmaElimVenta(wxWindow *parent=NULL);
	~VConfirmaElimVenta();
};

#endif

