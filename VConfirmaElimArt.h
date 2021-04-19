#ifndef VCONFIRMAELIMART_H
#define VCONFIRMAELIMART_H
#include "Ventanas.h"

class VConfirmaElimArt : public VentanaConfirmar {
	
private:
	
protected:
	void no_elimina_click( wxCommandEvent& event ) ;
	void si_elimina_click( wxCommandEvent& event ) ;
public:
	VConfirmaElimArt(wxWindow *parent=NULL);
	~VConfirmaElimArt();
};

#endif

