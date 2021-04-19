#include "VSinStock.h"
#include "Singleton2.h"
#include "ManejoArticulos.h"
#include "Articulo.h"
#include "VEditaArticulo.h"
#include <wx/msgdlg.h>

VSinStock::VSinStock(wxWindow *parent) : VentanaAlertas(parent) {
	titulo_alerta->SetLabel("Estos articulos estan agotados:");
	grillapocostock->DeleteCols(1);
	
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	int cant_articulos=manejo_articulos->CantidadDatos(); //Averigua numero de articulos del vector
	int cont_articulos=-1;
	for (int i=0;i<cant_articulos;i++){
		Articulo &a=(*manejo_articulos)[i];
		if(a.VerCantidadInt()==0){
			cont_articulos++;
			grillapocostock->AppendRows(1);
			CargarGrillaSinArticulos(i,cont_articulos);//Cargar los articulos del vector a la grilla
		}
	}	
	
	grillapocostock->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void VSinStock::CargarGrillaSinArticulos(int i, int fila) {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	Articulo &a=(*manejo_articulos)[i];
	
	grillapocostock->SetCellValue(fila,0,a.VerNombre());
}

VSinStock::~VSinStock() {
	
}

void VSinStock::click_agregar_stock( wxCommandEvent& event )  {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	
	if(grillapocostock->IsSelection()){
		int fila_actual=grillapocostock->GetGridCursorRow(); //Busco que elemento esta seleccionado
		string nombre_aux=grillapocostock->GetCellValue(fila_actual,0).c_str(); //Obtengo el nombre de ese elemento y lo guardo
		int articulo_modificar=manejo_articulos->BuscarArticuloModificar(nombre_aux); //Le paso el nombre a la funcion y me devuelve en que posicion esta
		VEditaArticulo nueva_ventana(this,articulo_modificar);//Crear la ventana con el articulo a modificar
		
		if (nueva_ventana.ShowModal()==1){//Mostrar y esperar a que retorne el codigo del boton
			//Limpio toda la grilla
			int cant_filas=grillapocostock->GetNumberRows();
			grillapocostock->DeleteRows(0,cant_filas);
			
			int cant_articulos=manejo_articulos->CantidadDatos(); //Averigua numero de articulos del vector
			int cont_articulos=-1;
			for (int i=0;i<cant_articulos;i++){
				Articulo &a=(*manejo_articulos)[i];
				if(a.VerCantidadInt()==0){
					cont_articulos++;
					grillapocostock->AppendRows(1);
					CargarGrillaSinArticulos(i,cont_articulos);//Cargar los articulos del vector a la grilla
				}
			}	
		}
	}else {
		wxMessageBox("No ha seleccionado ningún artículo");
	}
}

void VSinStock::CierraVentAlerta( wxCloseEvent& event )  {
	event.Skip();
}

void VSinStock::cierra_alerta( wxCloseEvent& event )  {
	EndModal(1);
}

