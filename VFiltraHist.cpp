#include "VFiltraHist.h"
#include "Singleton.h"
#include "Utiles.h"
#include <wx/msgdlg.h>
#include <string>

VFiltraHist::VFiltraHist(wxWindow *parent) : VentanaFiltraHist(parent) {
	
}

void VFiltraHist::filtrar_ahora_click( wxCommandEvent& event )  {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	
	//Varibles auxiliares que uso
	fecha fecha_hoy=FechaSistema();
	float total=0;
	
	//Obtengo los valores ingresados en los text de las fechas
	long d_desde,m_desde,a_desde,d_hasta,m_hasta,a_hasta;
	dia_fechadesde->GetValue().ToLong(&d_desde);
	mes_fechadesde->GetValue().ToLong(&m_desde);
	anio_fechadesde->GetValue().ToLong(&a_desde);
	dia_fechahasta->GetValue().ToLong(&d_hasta);
	mes_fechahasta->GetValue().ToLong(&m_hasta);
	anio_fechahasta->GetValue().ToLong(&a_hasta);

	string errores; //Valida dia y mes del filtro y que el año no sea menor a 2016. Tambien corrobora año biciesto (febrero<29) y los meses que tienen 30 dias
	if((d_desde>31 || d_desde<1) || (m_desde>12 || m_desde<1) || (m_desde==2 && d_desde>28 && (a_desde%4)!=0) || ((m_desde==4 || m_desde==6 || m_desde==9 ||m_desde==11) && d_desde>30)){
		errores+="Fecha inicial inválida\r\n";
	}
	if((d_hasta>31 || d_hasta<1) || (m_hasta>12 || m_hasta<1) || (m_hasta==2 && d_hasta>28 && (a_hasta%4)!=0) || ((m_hasta==4 || m_hasta==6 || m_hasta==9 ||m_hasta==11) && d_hasta>30)){
		errores+="Fecha final inválida\r\n";
	}
	
	//Verifica que la fecha inicial a filtrar sea menor a la fecha final
	int fecha_desde=(a_desde*10000)+(m_desde*100)+(d_desde);
	int fecha_hasta=(a_hasta*10000)+(m_hasta*100)+(d_hasta);
	if((fecha_desde-fecha_hasta)>0){
		errores+="El período ingresado no es válido\r\n";
	}
	
	if (errores.size()){//Corrobora que paso la validacion
		wxMessageBox(errores); //Muestra los errores
		int cant_filas=grillaventasfiltrado->GetNumberRows();//Obtiene la cantidad de filas de la grilla
		grillaventasfiltrado->DeleteRows(0,cant_filas);	//Elimina esa cantidad obtenida para asi vaciarla
	}else{ 
		int cant_filas=grillaventasfiltrado->GetNumberRows(); //Obtiene la cantidad de filas de la grilla
		grillaventasfiltrado->DeleteRows(0,cant_filas);	//Elimina esa cantidad obtenida para asi vaciarla
		ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	
		int cant_ventas = manejo_ventas->CantidadDatos(); //Averigua numero de ventas en el vector
		int cont_ventas=-1;
		for (int i=0;i<cant_ventas;i++){
			Venta &v=(*manejo_ventas)[i];
			fecha fecha_aux=v.VerFechaStruct();
			int fecha_venta=(fecha_aux.anio*10000)+(fecha_aux.mes*100)+(fecha_aux.dia);
			//Se fija que la fecha de la venta este dentro de las ingresadas por el usuario
			if ((((fecha_desde-fecha_venta)<0) && ((fecha_hasta-fecha_venta)>0)) || (fecha_desde==fecha_venta)|| (fecha_hasta==fecha_venta)){
				cont_ventas++;
				total+=v.VerPrecioFinalFloat(); //Suma el precio de la venta al precio total que se va a mostrar
				grillaventasfiltrado->AppendRows(1);//Si encuentra, agrega una fila
				CargarFilaVentasFiltradas(i,cont_ventas);//Cargar los datos de las ventas del dia
			}
		}
		total_periodo->Clear();//Vacia el textctrl donde lo va a mostrar
		*total_periodo<<"$"<<total; //Muestra el precio total del periodo que se obtuvo
	}
}

void VFiltraHist::CargarFilaVentasFiltradas(int i, int fila) {
	ManejoVentas *manejo_ventas=Singleton::ObtenerInstancia();
	Venta &v=(*manejo_ventas)[i];
	
	grillaventasfiltrado->SetCellValue(fila,0,v.VerNombre());
	grillaventasfiltrado->SetCellValue(fila,1,v.VerCantidad());
	grillaventasfiltrado->SetCellValue(fila,2,v.VerPrecioFinal());
	grillaventasfiltrado->SetCellValue(fila,3,v.VerFecha());
}

VFiltraHist::~VFiltraHist() {
	
}


void VFiltraHist::ClickGrillaFiltrar( wxGridEvent& event )  {
	event.Skip();
}

