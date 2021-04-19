#include "VNuevoArticulo.h"
#include "ManejoArticulos.h"
#include <string>
#include <stdlib.h> 
#include <wx/msgdlg.h>
#include "Singleton2.h"

VNuevoArticulo::VNuevoArticulo(wxWindow *parent) : VentanaIngresoArticulo(parent) {
	titu_ingresa_art->SetLabel("NUEVO ARTÍCULO");
	boton_aceptar_art->SetLabel("Listo");
}

void VNuevoArticulo::acepta_articulo( wxCommandEvent& event )  {
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	
	//Creo variables auxiliares para los atributos del nuevo articulo
	long cantidad_art; 	
	string nombre;
	float precio; const char* aux;
	string nombre_archivo="articulos.dat";
	
	nombre=nombre_ingresa_art->GetValue(); //Obtengo los valores ingresados
	cant_ingresa_art->GetValue().ToLong(&cantidad_art);
	
	aux=precio_ingresa_art->GetValue().c_str();
	precio=strtof(aux,NULL); //Convierte el char* obtenido en float para guardarlo en precio
	
	Articulo articulo_nuevo(nombre,precio,cantidad_art);//Creo una instancia de articulo
	
	string validacion=articulo_nuevo.ValidarDatos(nombre_archivo,true); //Llamo a validar de articulo
	if (validacion.size()){
		wxMessageBox(validacion); //Muestra los errores
		EndModal(0);
	} else {
		manejo_articulos->AgregarArticulo(articulo_nuevo);//Lo agrega al vector
		manejo_articulos->ActualizarLista();
		EndModal(1);
		}
	
	}

VNuevoArticulo::~VNuevoArticulo() {
	
}

