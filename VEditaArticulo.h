#ifndef VEDITAARTICULO_H
#define VEDITAARTICULO_H
#include "Ventanas.h"

class VEditaArticulo : public VentanaIngresoArticulo {
	
private:
	int articulo_editar;
protected:
	void acepta_articulo( wxCommandEvent& event ) ;
	
public:
	VEditaArticulo(wxWindow *parent, int cual);
	~VEditaArticulo();
};

#endif

