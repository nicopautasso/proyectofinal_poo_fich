#ifndef VNUEVOARTICULO_H
#define VNUEVOARTICULO_H
#include "Ventanas.h"

class VNuevoArticulo : public VentanaIngresoArticulo {
	
private:
	
protected:
	void acepta_articulo( wxCommandEvent& event ) ;
	
public:
	VNuevoArticulo(wxWindow *parent=NULL);
	~VNuevoArticulo();
};

#endif

