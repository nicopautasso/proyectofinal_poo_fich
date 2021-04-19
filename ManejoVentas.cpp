#include <iostream>
#include "Venta.h"
#include "ManejoVentas.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool CompararPorPrecioFinal(const Venta &v1,const Venta &v2){
	float aux1=v1.VerPrecioFinalFloat();
	float aux2=v2.VerPrecioFinalFloat();
	return aux1<aux2;
}
bool CompararPorCantidad(const Venta &v1,const Venta &v2){
	int aux1=v1.VerCantidadInt();
	int aux2=v2.VerCantidadInt();
	return aux1<aux2;
}
bool CompararPorFechaYHora(const Venta &v1,const Venta &v2){
	fecha fecha1=v1.VerFechaStruct();
	fecha fecha2=v2.VerFechaStruct();
	hora hora1=v1.VerHoraStruct();
	hora hora2=v2.VerHoraStruct();
	
	int aux1=(fecha1.anio*10000)+(fecha1.mes*100)+(fecha1.dia);
	int aux2=(fecha2.anio*10000)+(fecha2.mes*100)+(fecha2.dia);
	if((aux1-aux2)==0){
		if(hora1.hr<hora2.hr){
			return true;
		}else if((hora1.hr==hora2.hr)&&(hora1.min<hora2.min)){
			return true;
		}else if((hora1.min==hora2.min)&&(hora1.seg<hora2.seg)){
			return true;
		}else return false;
	} else if((aux1-aux2)<0){
		return true;
	} else return false;
}
bool CompararPorHora(const Venta &v1,const Venta &v2){
	hora hora1=v1.VerHoraStruct();
	hora hora2=v2.VerHoraStruct();
	
	if(hora1.hr<hora2.hr){
		return true;
	}else if((hora1.hr==hora2.hr)&&(hora1.min<hora2.min)){
		return true;
	}else if((hora1.min==hora2.min)&&(hora1.seg<hora2.seg)){
		return true;
	}else return false;
}
bool CompararPorNombreArt(const Venta &v1,const Venta &v2){
	string aux1=v1.VerNombre();
	string aux2=v2.VerNombre();
	Minusculas(aux1);
	Minusculas(aux2);
	return aux1<aux2;
}

	ManejoVentas::ManejoVentas(string archivo_){
		//Recibe el nombre del archivo donde se guardan todas las ventas y las carga en el vector v_venta
		archivo=archivo_;
		ifstream archi1(archivo.c_str(),ios::binary|ios::ate);
		if (archi1.is_open()){
			int cant_bytes=archi1.tellg();
			int cant_datos=cant_bytes/sizeof(tipoventa);
			archi1.seekg(0);
			v_venta.resize(cant_datos);
			for (int i=0; i<cant_datos; i++){
				v_venta[i].LeerDesdeArchivo(archi1);
			}
			archi1.close();
		}
	}
	
	void ManejoVentas::NuevaVenta(Venta venta_){//Agrega la venta al vector ventas
		v_venta.push_back(venta_);
	}
	
	void ManejoVentas::NuevaVentaHoy(Venta venta_){//Agrega la venta al vector de las ventas de hoy
		v_ventashoy.push_back(venta_);
	}
	
	void ManejoVentas::EliminarVenta(int pos){
		v_venta.erase(v_venta.begin()+(pos));
	}
	void ManejoVentas::EliminarVentasHoy(){
		v_ventashoy.clear();
	}
	
	//Guarda el vector de ventas en el archivo (con verificacion)
	bool ManejoVentas::ActualizarLista(){
		ofstream archi2(archivo.c_str(),ios::binary|ios::trunc);
		if (!archi2.is_open()) return false;
		int cant=CantidadDatos();
		for (int i=0; i<cant; i++){
			v_venta[i].GuardarEnArchivo(archi2);
		}
		archi2.close();
		return true;
	}
	int ManejoVentas::CantidadDatos(){
		return v_venta.size();
	}
	int ManejoVentas::CantidadDatosHoy(){
		return v_ventashoy.size();
	}
	
	//Sobrecarga [] para que devuelva un elemento del vector (venta) mediante su pos
	Venta &ManejoVentas::operator[](int pos){
		return v_venta[pos];
	}
	Venta &ManejoVentas::VentasHoy(int pos){
		return v_ventashoy[pos];
	}
	
	void ManejoVentas::Ordenar(int criterio){
		switch (criterio){
		case 1: 
			sort(v_venta.begin(),v_venta.end(),CompararPorPrecioFinal);
			break;
		case 2: 
			sort(v_venta.begin(),v_venta.end(),CompararPorCantidad);
			break;
		case 3: 
			sort(v_venta.begin(),v_venta.end(),CompararPorFechaYHora);
			break;
		case 4: 
			sort(v_venta.begin(),v_venta.end(),CompararPorNombreArt);
			break;
		}
	}

	void ManejoVentas::OrdenarHoy(int criterio){
		switch (criterio){
		case 1: 
			sort(v_ventashoy.begin(),v_ventashoy.end(),CompararPorPrecioFinal);
			break;
		case 2: 
			sort(v_ventashoy.begin(),v_ventashoy.end(),CompararPorCantidad);
			break;
		case 3: 
			sort(v_ventashoy.begin(),v_ventashoy.end(),CompararPorHora);
			break;
		case 4: 
			sort(v_ventashoy.begin(),v_ventashoy.end(),CompararPorNombreArt);
			break;
		}
	}
