#include <iostream>
#include "Utiles.h"
#include "Articulo.h"
#include "Singleton2.h"
#include <fstream>
#include <sstream>
using namespace std;

	Articulo::Articulo(){
		
	}
	
	Articulo::Articulo(string nombre_, float precio_, int cantidad_){
		nombre=nombre_;
		precio=precio_;
		cantidad=cantidad_;
	}
	
	//Corrobora que los datos no sean invalidos o esten vacios (el bool sirve para saber si estoy creando un nuevo articulo o modificando uno existe y asi evita que diga que el articulo ya existe)
	string Articulo::ValidarDatos(string archivo_articulos, bool verificar_nombre){
		ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
		string aux;
		if (nombre.size()==0) aux+="No se ingresó el nombre del artículo\r\n";
		if (verificar_nombre==true){
			if (manejo_articulos->ArticuloExiste(nombre)==true) aux+="El artículo ya existe\r\n";
		}
		if (precio==NULL && precio!=0) aux+="No se ingresó precio del artículo\r\n";
		if (precio<=0) aux+="El precio del artículo es inválido\r\n";
		if (cantidad==NULL && cantidad!=0) aux+="No se ingresó la cantidad de artículos\r\n";
		if (cantidad<0) aux+="La cantidad del artículo es inválida\r\n";
		return aux;
	}
	
	//Muestra nombre, precio o cantidad del articulo
	string Articulo::VerNombre(){
		return nombre;
	}
	string Articulo::VerPrecio(){
		stringstream ss;
		ss<<precio;
		string aux=ss.str();
		return "$"+aux;
	}
	string Articulo::VerCantidad(){
		stringstream ss;
		ss<<cantidad;
		string aux=ss.str();
		return aux;
	}
	int Articulo::VerCantidadInt(){
		return cantidad;
	}
	float Articulo::VerPrecioFloat(){
		return precio;
	}
	
	//Lee o escribe cada registro desde/en el archivo
	void Articulo::GuardarEnArchivo(ofstream &archivo) {
		tipoarticulo aux;
		strcpy(aux.nombre,nombre.c_str());
		aux.precio=precio;
		aux.cantidad=cantidad;
		archivo.write(reinterpret_cast <char*>(&aux),sizeof(aux));
	}
	void Articulo::LeerDesdeArchivo(ifstream &archivo) {
		tipoarticulo aux;
		archivo.read(reinterpret_cast <char*>(&aux),sizeof(aux));
		nombre=aux.nombre;
		precio=aux.precio;
		cantidad=aux.cantidad;
	}	
	
	//Modifica el nombre, precio o cantidad del articulo
	void Articulo::ModificarNombre(string nombre_){
		nombre=nombre_;
	}
	void Articulo::ModificarPrecio(float precio_){
		precio=precio_;		
	}
	void Articulo::ModificarCantidad(int cantidad_){
		cantidad=cantidad_;		
	}
	void Articulo::RestarStock(int cantidad_){
		cantidad-=cantidad_;		
	}
	

	
	

