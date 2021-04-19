#include "VHistorialVentas.h"
#include "ManejoVentas.h"
#include "Venta.h"
#include "Singleton.h"
#include "VConfirmaElimVenta.h"
#include <wx/msgdlg.h>
#include "VFiltraHist.h"

VHistorialVentas::VHistorialVentas(wxWindow *parent) : HistorialDeVentas(parent) {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();

	int cant_ventas = manejo_ventas->CantidadDatos(); //Averigua numero de filas que va a tener la tabla
	grillaventashistorial->AppendRows(cant_ventas); //Agrega las filas
	for (int i=0;i<cant_ventas;i++){
		Venta &v=(*manejo_ventas)[i];
		CargarFilaVentasHistorial(i);//Cargar los datos de las ventas del dia
	}
	grillaventashistorial->SetSelectionMode(wxGrid::wxGridSelectRows); //Hace que se seleccione por fila y no por celda
}

void VHistorialVentas::CargarFilaVentasHistorial(int i) {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	Venta &v=(*manejo_ventas)[i];
	
	grillaventashistorial->SetCellValue(i,0,v.VerNombre());
	grillaventashistorial->SetCellValue(i,1,v.VerCantidad());
	grillaventashistorial->SetCellValue(i,2,v.VerPrecioFinal());
	grillaventashistorial->SetCellValue(i,3,v.VerFecha());
}

void VHistorialVentas::ClickGrillaVentasHistorial( wxGridEvent& event )  {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	int columna=event.GetCol();
	int cant_ventas=manejo_ventas->CantidadDatos();
	switch(columna) { //Ordenar de ManejoVentas.h
	case 0: manejo_ventas->Ordenar(4); break;
	case 1: manejo_ventas->Ordenar(2); break;
	case 2: manejo_ventas->Ordenar(1); break;
	case 3: manejo_ventas->Ordenar(3); break;
	}
	for (int i=0;i<cant_ventas;i++){
		CargarFilaVentasHistorial(i); //Actualiza la grilla
	}
}

VHistorialVentas::~VHistorialVentas() {
}

void VHistorialVentas::eliminar_venta_click( wxCommandEvent& event )  {
	
	if(grillaventashistorial->IsSelection()){
		VConfirmaElimVenta nueva_ventana(this);//Crear la ventana
		if (nueva_ventana.ShowModal()==1){//Mostrar y esperar a que retorne el codigo del boton
			ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
			int fila_actual = grillaventashistorial->GetGridCursorRow();//Busca la posicion de la fila que estaba seleccionada
			grillaventashistorial->DeleteRows(fila_actual,1);
			manejo_ventas->EliminarVenta(fila_actual);//Elimina la venta del vector
			manejo_ventas->ActualizarLista();//Actualiza el archivo
		}
	} else {
		wxMessageBox("No ha seleccionado ninguna venta");
		}
}

void VHistorialVentas::ventana_filtrar_click( wxCommandEvent& event )  {
	VFiltraHist nueva_ventana(this);//Crear la ventana
	if (nueva_ventana.ShowModal()==1) { //Mostrar y esperar
	}
}

void VHistorialVentas::cierra_historial( wxCloseEvent& event )  {
	EndModal(1);
}

