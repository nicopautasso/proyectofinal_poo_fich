#ifndef VFILTRAHIST_H
#define VFILTRAHIST_H
#include "Ventanas.h"

class VFiltraHist : public VentanaFiltraHist {
	
private:
	void CargarFilaVentasFiltradas(int i, int fila);	
protected:
	void ClickGrillaFiltrar( wxGridEvent& event ) ;
	void filtrar_ahora_click( wxCommandEvent& event ) ;
public:
	VFiltraHist(wxWindow *parent=NULL);
	~VFiltraHist();
};

#endif

