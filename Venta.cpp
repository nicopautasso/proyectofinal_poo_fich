#include <iostream>
#include "Utiles.h"
#include "Venta.h"
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

	Venta::Venta(){
		
	}

	Venta::Venta(int cant_, string nombre_art_, string archivo_ventas, string archivo_art){
		//Le llega la cantidad y el nombre del articulo vendido y calcula su precio final (cant*precio_art)
		string archivo1=archivo_ventas;
		string archivo2=archivo_art;
		
		//Busca el precio del articulo por medio del nombre que recibió
		ifstream archi2(archivo2.c_str(),ios::binary|ios::ate);
		int cant_bytes2=archi2.tellg();
		int cant_datos2=cant_bytes2/sizeof(tipoarticulo);
		archi2.seekg(0);
		float precio_aux;
		for (int i=0; i<cant_datos2; i++){
			tipoarticulo aux;
			archi2.read(reinterpret_cast <char*> (&aux), sizeof(aux));
			string nombre_art_aux=aux.nombre;
			if(nombre_art_==nombre_art_aux){
				precio_aux=aux.precio;
				break;
			}
		}
		archi2.close();
		
		//Guardo el nombre del articulo vendido, la cantidad y calculo el precio final de la venta con la cantidad*precio del articulo que buscaba
		nombre_art=nombre_art_;
		cantidad=cant_;
		precio_total=cantidad*precio_aux;

		//Toma la hora del sistema y la guarda en dos structs distintos (fecha y hora)
		time_t now=time(0);
		tm* ltm=localtime(&now);
		
		fecha_venta.dia=ltm->tm_mday;
		fecha_venta.mes=1+ltm->tm_mon;
		fecha_venta.anio=1900+ltm->tm_year;
		hora_venta.hr=ltm->tm_hour;
		hora_venta.min=ltm->tm_min;
		hora_venta.seg=ltm->tm_sec;
	}
	
	//Muestra el precio final, cantidad o fecha de la venta
	string Venta::VerPrecioFinal(){
		stringstream ss;
		ss<<precio_total;
		string aux=ss.str();
		return "$"+aux;
	}
	float Venta::VerPrecioFinalFloat() const{
		return precio_total;
	}
	string Venta::VerCantidad(){
		stringstream ss;
		ss<<cantidad;
		string aux=ss.str();
		return aux;
	}
	int Venta::VerCantidadInt() const{
		return cantidad;
	}
	string Venta::VerNombre() const{
		return nombre_art; 
	}
	string Venta::VerFecha(){
		string auxcerohora;
		if (hora_venta.hr<10){
			auxcerohora="0";
		}else {auxcerohora="";
		}
		
		string auxceromin;
		if (hora_venta.min<10){
			auxceromin="0";
		}else {auxceromin="";
			}
				
		string auxceroseg;
		if (hora_venta.seg<10){
			auxceroseg="0";
		}else {auxceroseg="";
			}
		
		string auxcerodia;
		if (fecha_venta.dia<10){
			auxcerodia="0";
		}else {auxcerodia="";
		}
		
		string auxceromes;
		if (fecha_venta.mes<10){
			auxceromes="0";
		}else {auxceromes="";
		}
				
		stringstream ssfecha;
		ssfecha<<auxcerodia<<fecha_venta.dia<<"/"<<auxceromes<<fecha_venta.mes<<"/"<<fecha_venta.anio;
		stringstream sshora;
		sshora<<auxcerohora<<hora_venta.hr<<":"<<auxceromin<<hora_venta.min<<":"<<auxceroseg<<hora_venta.seg;
				
		string fecha=ssfecha.str();
		string hora=sshora.str();
		
		return fecha+" "+hora; 
	}
	string Venta::VerHora(){
		string auxcerohora;
		if (hora_venta.hr<10){
			auxcerohora="0";
		}else {auxcerohora="";
		}
		
		string auxceromin;
		if (hora_venta.min<10){
			auxceromin="0";
		}else {auxceromin="";
		}
		
		string auxceroseg;
		if (hora_venta.seg<10){
			auxceroseg="0";
		}else {auxceroseg="";
		}
		
		stringstream sshora;
		sshora<<auxcerohora<<hora_venta.hr<<":"<<auxceromin<<hora_venta.min<<":"<<auxceroseg<<hora_venta.seg;
		
		string hora=sshora.str();
		
		return hora;
	}
	fecha Venta::VerFechaStruct() const{
		return fecha_venta;
	}
	hora Venta::VerHoraStruct() const{
		return hora_venta;
	}
	
	//Lee o escribe cada registro desde/en el archivo
	void Venta::GuardarEnArchivo(ofstream &archivo) {
		tipoventa aux;
		
		aux.cantidad=cantidad;
		aux.fecha_venta.dia=fecha_venta.dia;
		aux.fecha_venta.mes=fecha_venta.mes;
		aux.fecha_venta.anio=fecha_venta.anio;
		aux.hora_venta.hr=hora_venta.hr;
		aux.hora_venta.min=hora_venta.min;
		aux.hora_venta.seg=hora_venta.seg;
		strcpy(aux.nombre_art,nombre_art.c_str());
		aux.precio_total=precio_total;
		archivo.write((char*)(&aux),sizeof(aux));
	}
	
	void Venta::LeerDesdeArchivo(ifstream &archivo) {
		tipoventa aux;
		
		archivo.read((char*)(&aux),sizeof(aux));
		cantidad=aux.cantidad;
		fecha_venta.dia=aux.fecha_venta.dia;
		fecha_venta.mes=aux.fecha_venta.mes;
		fecha_venta.anio=aux.fecha_venta.anio;
		hora_venta.hr=aux.hora_venta.hr;
		hora_venta.min=aux.hora_venta.min;
		hora_venta.seg=aux.hora_venta.seg;
		nombre_art=aux.nombre_art;
		precio_total=aux.precio_total;
	}
	


