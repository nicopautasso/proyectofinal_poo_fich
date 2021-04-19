#ifndef VSTOCK_H
#define VSTOCK_H
#include "Ventanas.h"

class VStock : public VentanaStock {
	
private:
	void CargarGrillaArticulos(int i);
protected:
	void cerrar_stock( wxCloseEvent& event ) ;
	void ClickModificarArt( wxCommandEvent& event ) ;
	void ClickBuscarArtStock( wxCommandEvent& event ) ;
	void ClickGrillaStock( wxGridEvent& event ) ;
	void ClickAlertas( wxCommandEvent& event ) ;
	void ClickSinStock( wxCommandEvent& event ) ;
	void ClickAgregarArt( wxCommandEvent& event ) ;
	void ClickEliminaArt( wxCommandEvent& event ) ;
	
public:
	VStock(wxWindow *parent=NULL);
	~VStock();

};

#endif

