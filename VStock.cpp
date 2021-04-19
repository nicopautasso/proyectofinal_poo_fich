#include "VStock.h"
#include "ManejoArticulos.h"
#include "Singleton.h"
#include "Singleton2.h"
#include <wx/msgdlg.h>
#include "VConfirmaElimArt.h"
#include "VNuevoArticulo.h"
#include "VEditaArticulo.h"
#include "VPrincipal.h"
#include "VPocoStock.h"
#include "VSinStock.h"
#include "icono.xpm"
#include <wx/icon.h>

VStock::VStock(wxWindow *parent) : VentanaStock(parent) {
	SetIcon(wxIcon(icono_xpm));
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	
	int cant_articulos = manejo_articulos->CantidadDatos(); //Averigua numero de articulos del vector
	grillastock->AppendRows(cant_articulos); 
	for (int i=0;i<cant_articulos;i++){
		CargarGrillaArticulos(i);//Cargar los articulos del vector a la grilla
	}
	
	grillastock->SetSelectionMode(wxGrid::wxGridSelectRows); //Hace que se seleccione por fila y no por celda
}

void VStock::CargarGrillaArticulos(int i) {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	Articulo &a=(*manejo_articulos)[i];
	
	grillastock->SetCellValue(i,0,a.VerNombre());
	grillastock->SetCellValue(i,1,a.VerCantidad());
	grillastock->SetCellValue(i,2,a.VerPrecio());
}

VStock::~VStock(){
	
}

void VStock::ClickBuscarArtStock( wxCommandEvent& event )  {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	// Buscar desde la fila actual
	int fila_actual=grillastock->GetGridCursorRow();
	int res=manejo_articulos->BuscarArticulo(busqueda_art_stock->GetValue().c_str(),fila_actual+1);
	// Si no encontro buscar otra vez desde el principio
	if (res==-1)
		res=manejo_articulos->BuscarArticulo(busqueda_art_stock->GetValue().c_str(),0);
		if (res==-1) // Si no hay ninguna coincidencia
			wxMessageBox("No se encontraron artículos");
		else {
				grillastock->SetGridCursor(res,0); //Seleccion el item
				grillastock->SelectRow(res); //Seleccion el item
				grillastock->MakeCellVisible(res,0); // Asegurarse de que se ve
		}
}

void VStock::ClickGrillaStock( wxGridEvent& event )  {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();

	int columna=event.GetCol();
	int cant_articulos=manejo_articulos->CantidadDatos();
	switch(columna) { //Ordenar de ManejoArticulos.h
	case 0: manejo_articulos->Ordenar(1); break;
	case 1: manejo_articulos->Ordenar(3); break;
	case 2: manejo_articulos->Ordenar(2); break;
	}
	for (int i=0;i<cant_articulos;i++){
		CargarGrillaArticulos(i); //Actualiza la grilla
	}
}

void VStock::ClickAlertas( wxCommandEvent& event )  {
	VPocoStock nueva_ventana(this);//Crear la ventana
	if (nueva_ventana.ShowModal()==1) { //Mostrar y esperar
		//Limpio toda la grilla
		int cant_filas=grillastock->GetNumberRows();
		grillastock->DeleteRows(0,cant_filas);
		
		ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
		int cant_articulos = manejo_articulos->CantidadDatos(); //Averigua numero de articulos del vector
		grillastock->AppendRows(cant_articulos); 
		for (int i=0;i<cant_articulos;i++){
			CargarGrillaArticulos(i);//Cargar los articulos del vector a la grilla
		}
	}
}

void VStock::ClickSinStock( wxCommandEvent& event )  {
	VSinStock nueva_ventana(this);//Crear la ventana
	if (nueva_ventana.ShowModal()==1) { //Mostrar y esperar
		//Limpio toda la grilla
		int cant_filas=grillastock->GetNumberRows();
		grillastock->DeleteRows(0,cant_filas);
		
		ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
		int cant_articulos = manejo_articulos->CantidadDatos(); //Averigua numero de articulos del vector
		grillastock->AppendRows(cant_articulos); 
		for (int i=0;i<cant_articulos;i++){
			CargarGrillaArticulos(i);//Cargar los articulos del vector a la grilla
		}
	}
}

void VStock::ClickAgregarArt( wxCommandEvent& event )  {
	VNuevoArticulo nueva_ventana(this);//Crear la ventana
	if (nueva_ventana.ShowModal()==1){//Mostrar y esperar a que retorne el codigo del boton
		ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
		grillastock->AppendRows(1); //Agregar el lugar en la grilla
		CargarGrillaArticulos(manejo_articulos->CantidadDatos()-1);//Copiar en la grilla
	}
}

void VStock::ClickEliminaArt( wxCommandEvent& event )  {
	
	if(grillastock->IsSelection()){
		VConfirmaElimArt nueva_ventana(this);//Crear la ventana
			if (nueva_ventana.ShowModal()==1){//Mostrar y esperar a que retorne el codigo del boton
			ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
			int fila_actual = grillastock->GetGridCursorRow();//Busca la posicion de la fila que estaba seleccionada
			grillastock->DeleteRows(fila_actual,1);
			manejo_articulos->BajaArticulo(fila_actual);//Elimina el articulo del vector
			manejo_articulos->ActualizarLista();//Actualiza el archivo
			}
		}else {
		wxMessageBox("No ha seleccionado ningún artículo");
			}
	}

void VStock::ClickModificarArt( wxCommandEvent& event )  {
	int fila_actual=grillastock->GetGridCursorRow();
	
	if(grillastock->IsSelection()){
		int fila_actual=grillastock->GetGridCursorRow();
		VEditaArticulo nueva_ventana(this,fila_actual);//Crear la ventana
			if (nueva_ventana.ShowModal()==1){//Mostrar y esperar a que retorne el codigo del boton
			CargarGrillaArticulos(fila_actual);
		}
	}else {
		wxMessageBox("No ha seleccionado ningún artículo");
	}
}

void VStock::cerrar_stock( wxCloseEvent& event )  {
	EndModal(1);
}

