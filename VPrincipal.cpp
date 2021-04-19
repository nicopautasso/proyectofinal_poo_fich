#include "VPrincipal.h"
#include "Singleton.h"
#include "Venta.h"
#include "Utiles.h"
#include "Singleton2.h"
#include "Articulo.h"
#include <wx/msgdlg.h>
#include <string>
#include "ManejoArticulos.h"
#include "VHistorialVentas.h"
#include "VStock.h"
#include "icono.xpm"
#include <wx/icon.h>
#include "VAyuda.h"

VPrincipal::VPrincipal(wxWindow *parent) : VentanaPrincipal(parent) {
	SetIcon(wxIcon(icono_xpm));
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	fecha fecha_hoy=FechaSistema(); //Guarda la fecha de hoy (class Utiles)
	
	int cant_ventas = manejo_ventas->CantidadDatos(); //Averigua numero de filas que va a tener la tabla

	int cont_articulos=-1;
	for (int i=0;i<cant_ventas;i++){
		Venta &v=(*manejo_ventas)[i];
		fecha aux=v.VerFechaStruct();
		if (fecha_hoy.dia==aux.dia && fecha_hoy.mes==aux.mes && fecha_hoy.anio==aux.anio){//Busca si la fecha de hoy es igual a la de la venta
			cont_articulos++;
			grillaventashoy->AppendRows(1);//Si encuentra, agrega una fila
			CargarFilaVentasDia(i,cont_articulos);//Cargar los datos de las ventas del dia
			manejo_ventas->NuevaVentaHoy(v);
		}
	}
	
	grillaventashoy->SetSelectionMode(wxGrid::wxGridSelectRows); //Hace que se seleccione por fila y no por celda
	
	int cant_articulos = manejo_articulos->CantidadDatos(); //Averigua numero de items que va a tener la grilla
	for (int i=0;i<cant_articulos;i++){
		lista_articulos->AppendRows(1);
		CargarListArticulos(i);//Cargar los datos de los articulos en la grilla
	}
	Show();
}

void VPrincipal::CargarFilaVentasDia(int i, int fila) {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	Venta &v=(*manejo_ventas)[i];

	grillaventashoy->SetCellValue(fila,0,v.VerNombre());
	grillaventashoy->SetCellValue(fila,1,v.VerCantidad());
	grillaventashoy->SetCellValue(fila,2,v.VerPrecioFinal());
	grillaventashoy->SetCellValue(fila,3,v.VerHora());
}
void VPrincipal::ActualizarFilaVentasDia(int i) {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	Venta &v=manejo_ventas->VentasHoy(i);
	
	grillaventashoy->SetCellValue(i,0,v.VerNombre());
	grillaventashoy->SetCellValue(i,1,v.VerCantidad());
	grillaventashoy->SetCellValue(i,2,v.VerPrecioFinal());
	grillaventashoy->SetCellValue(i,3,v.VerHora());
}

void VPrincipal::CargarListArticulos(int i) {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	Articulo &a=(*manejo_articulos)[i];
	
	lista_articulos->SetCellValue(i,0,a.VerNombre()); //Inserta los nombres de los articulos en la lista (grilla)
}

void VPrincipal::ClickBuscarArt( wxCommandEvent& event )  {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	// Buscar desde la fila actual
	int fila_actual=lista_articulos->GetGridCursorRow();
	int res=manejo_articulos->BuscarArticulo(busqueda_art->GetValue().c_str(),fila_actual+1);
	// Si no encontro buscar otra vez desde el principio
	if (res==-1)
		res=manejo_articulos->BuscarArticulo(busqueda_art->GetValue().c_str(),0);
		if (res==-1) // Si no hay ninguna coincidencia
			wxMessageBox("No se encontraron artículos");
		else {
				lista_articulos->SetGridCursor(res,0); //Seleccion el item
				lista_articulos->SelectRow(res); //Seleccion el item
				lista_articulos->MakeCellVisible(res,0); // Asegurarse de que se ve
		}
}

void VPrincipal::ClickVender( wxCommandEvent& event )  {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	
	long cantidad_arts;
	cantidad_venta->GetValue().ToLong(&cantidad_arts); //Averigua el valor de la cantidad ingresada
	
	int cant_articulos=manejo_articulos->CantidadDatos();
	string nombre_articulo;
	int posicion_art;
	int cantidad_stock;
	
	if (cant_articulos!=0){
	int fila_actual = lista_articulos->GetGridCursorRow(); //Se fija cual esta seleccionada
	Articulo &a=(*manejo_articulos)[fila_actual];
	
	nombre_articulo=a.VerNombre();
	cantidad_stock=a.VerCantidadInt();

	//Valida y crea la venta
	if (cantidad_arts==NULL){ //Verifica que se ingreso un numero positivo
		wxMessageBox("Cantidad inválida");
		cantidad_venta->Clear();
	}else if (cantidad_arts>cantidad_stock){ //Verifica que hay stock
		wxMessageBox("No hay stock suficiente");
		cantidad_venta->Clear();
		} else {
			Venta v(cantidad_arts,nombre_articulo,"ventas.dat","articulos.dat");
			manejo_ventas->NuevaVenta(v);//Guarda la venta
			manejo_ventas->ActualizarLista(); //Actualiza el archivo de ventas
			manejo_articulos->ModificarStock(fila_actual,cantidad_arts);//Modifica el stock del articulo vendido
			manejo_articulos->ActualizarLista();//Actualiza el archivo de articulos
			cantidad_venta->Clear();
			
			manejo_ventas->NuevaVentaHoy(v); //Guarda la venta en el vector de hoy
			int cant_ventas = manejo_ventas->CantidadDatosHoy(); //Averigua numero de ventas de hoy
			grillaventashoy->AppendRows(1);//Agrega una fila
			ActualizarFilaVentasDia(cant_ventas-1);//Cargar los datos de las ventas del dia
			}
	} else {
		wxMessageBox("No existen artículos en el sistema");
		cantidad_venta->Clear();
		precio_unit->Clear();
		cantidad_disp->Clear();
		precio_total->Clear();
	}
}

void VPrincipal::ClickGrillaVentasHoy( wxGridEvent& event )  {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	int columna=event.GetCol();
	int cant_ventas=manejo_ventas->CantidadDatosHoy();
	switch(columna) { //Ordenar de ManejoVentas.h
	case 0: manejo_ventas->OrdenarHoy(4); break;
	case 1: manejo_ventas->OrdenarHoy(2); break;
	case 2: manejo_ventas->OrdenarHoy(1); break;
	case 3: manejo_ventas->OrdenarHoy(3); break;
	}
	for (int i=0;i<cant_ventas;i++){
		ActualizarFilaVentasDia(i); //Actualiza la grilla
	}
}

void VPrincipal::ClickVerHistorial( wxCommandEvent& event )  {
	VHistorialVentas nueva_ventana(this);//Crear la ventana
	if (nueva_ventana.ShowModal()==1) { //Mostrar y esperar
		ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
		int cant_ventas = manejo_ventas->CantidadDatos(); //Averigua numero de filas que va a tener la tabla
		int cont_articulos=-1;
		fecha fecha_hoy=FechaSistema();
		
		//Limpio toda la grilla
		int cant_filas=grillaventashoy->GetNumberRows();
		grillaventashoy->DeleteRows(0,cant_filas);
		//Vacio el vector de ventas de hoy
		manejo_ventas->EliminarVentasHoy();
		
		for (int i=0;i<cant_ventas;i++){
			Venta &v=(*manejo_ventas)[i];
			fecha aux=v.VerFechaStruct();
			if (fecha_hoy.dia==aux.dia && fecha_hoy.mes==aux.mes && fecha_hoy.anio==aux.anio){//Busca si la fecha de hoy es igual a la de la venta
				cont_articulos++;
				grillaventashoy->AppendRows(1);//Si encuentra, agrega una fila
				CargarFilaVentasDia(i,cont_articulos);//Cargar los datos de las ventas del dia
				manejo_ventas->NuevaVentaHoy(v);
			}
		}
	}
}


VPrincipal::~VPrincipal() {
	
}

void VPrincipal::cant_ontext( wxCommandEvent& event )  {
	event.Skip();
	
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	int cant_articulos=manejo_articulos->CantidadDatos();
	if (cant_articulos!=0){
	int fila_actual=lista_articulos->GetGridCursorRow();
	lista_articulos->SetGridCursor(fila_actual,0); // Seleccionar celda
	lista_articulos->SelectRow(fila_actual); // Marcar toda la fila
	lista_articulos->MakeCellVisible(fila_actual,0); // Asegurarse de que se ve
	ActualizarPrecioFinal();
	}
}
void VPrincipal::cant_onwindow( wxMouseEvent& event )  {
	event.Skip();
	
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	int cant_articulos=manejo_articulos->CantidadDatos();
	if (cant_articulos!=0){
	int fila_actual=lista_articulos->GetGridCursorRow();
	lista_articulos->SetGridCursor(fila_actual,0); // Seleccionar celda
	lista_articulos->SelectRow(fila_actual); // Marcar toda la fila
	lista_articulos->MakeCellVisible(fila_actual,0); // Asegurarse de que se ve
	ActualizarPrecioFinal();
	}
}	

void VPrincipal::articulo_ongrid( wxGridEvent& event )  {
	event.Skip();
	cantidad_venta->Clear();
	
	if (lista_articulos->IsSelection()==true){
		int fila_actual=lista_articulos->GetGridCursorRow();
		lista_articulos->SetGridCursor(fila_actual,0); // Seleccionar celda
		lista_articulos->SelectRow(fila_actual); // Marcar toda la fila
		lista_articulos->MakeCellVisible(fila_actual,0); // Asegurarse de que se ve
		ActualizarPrecioFinal();
	}
	
}

void VPrincipal::ActualizarPrecioFinal ( ) {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();

	long cantidad; //Obtiene la cantidad ingresada
	cantidad_venta->GetValue().ToLong(&cantidad);
	
	int fila_actual=lista_articulos->GetGridCursorRow(); //Obtiene el precio y cantidad del articulo seleccionado llamando a la funcion de ManejoArticulos
	float precio_articulo=manejo_articulos->BuscarPrecioArticulo(fila_actual);
	int cantidad_articulo=manejo_articulos->BuscarCantidadArticulo(fila_actual);
	float precio_a_mostrar=cantidad*precio_articulo; //Calcula el precio final
	
	precio_unit->Clear();//Vacia el textctrl donde lo va a mostrar
	*precio_unit<<"$"<<precio_articulo;//Lo muestra
	cantidad_disp->Clear();//Vacia el textctrl donde lo va a mostrar
	*cantidad_disp<<cantidad_articulo;//Lo muestra
	precio_total->Clear();//Vacia el textctrl donde lo va a mostrar
	*precio_total<<"$"<<precio_a_mostrar;//Lo muestra
}

void VPrincipal::ClickIrStock( wxCommandEvent& event )  {
	VStock nueva_ventana(this);//Crear la ventana
	if (nueva_ventana.ShowModal()==1) {
		//Limpio toda la grilla
		int cant_filas=lista_articulos->GetNumberRows();
		lista_articulos->DeleteRows(0,cant_filas);
		
		ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
		int cant_articulos = manejo_articulos->CantidadDatos(); //Averigua numero de items que va a tener la grilla
		for (int i=0;i<cant_articulos;i++){
			lista_articulos->AppendRows(1);
			CargarListArticulos(i);//Cargar los datos de los articulos en la grilla
		}
	}
}

void VPrincipal::CambiaTamanio( wxSizeEvent& event )  {
	// si cambia el tamanio de la ventana, estira los anchos de las columnas 
	// para ajustarse al nuevo tamaño de forma proporcional
	Layout(); // primero que ajuste lo de la ventana, asi tengo el nuevo tamaño de la grilla
	int tamanios[4], ancho_total_viejo=0; // despues, guardar tamanios viejos
	for (int i=0;i<4;i++) { 
		tamanios[i] = grillaventashoy->GetColSize(i);
		ancho_total_viejo += tamanios[i];
	}
	int ancho_total_nuevo=grillaventashoy->GetSize().GetWidth(); // ver el ancho nuevo de la tabla
	grillaventashoy->BeginBatch(); // beginbatch y endbatch son para que cuando cambiamos varias cosas no redibuje varias veces, sino una sola al final
	for (int i=0;i<4;i++){ // asignar nuevos tamaños nuevos a columnas
		 grillaventashoy->SetColSize(i,tamanios[i]*ancho_total_nuevo/ancho_total_viejo);
		 grillaventashoy->EndBatch();
	}
	
	int tamanios1[1], ancho_total_viejo1=0; // despues, guardar tamanios viejos
	for (int i=0;i<1;i++) { 
		tamanios1[i] = lista_articulos->GetColSize(i);
		ancho_total_viejo1 += tamanios1[i];
	}
	int ancho_total_nuevo1=lista_articulos->GetSize().GetWidth(); // ver el ancho nuevo de la tabla
	lista_articulos->BeginBatch(); // beginbatch y endbatch son para que cuando cambiamos varias cosas no redibuje varias veces, sino una sola al final
	for (int i=0;i<1;i++){ // asignar nuevos tamaños nuevos a columnas
		lista_articulos->SetColSize(i,tamanios1[i]*ancho_total_nuevo1/ancho_total_viejo1);
		lista_articulos->EndBatch();
	}
}

void VPrincipal::click_ayuda( wxCommandEvent& event )  {
	VAyuda* a = new VAyuda(this);
	a->Show();
}


