#include "VEditaArticulo.h"
#include "ManejoArticulos.h"
#include "VStock.h"
#include <string>
#include <stdlib.h> 
#include <wx/msgdlg.h>
#include "Singleton2.h"

VEditaArticulo::VEditaArticulo(wxWindow *parent, int cual) : VentanaIngresoArticulo(parent) {
	titu_ingresa_art->SetLabel("MODIFICAR ARTÍCULO");
	boton_aceptar_art->SetLabel("Listo");
	
	articulo_editar=cual;
	ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
	Articulo &a=(*manejo_articulos)[articulo_editar];
	//Rellena los textctrl con los valores actuales del articulo que se va a editar
	*nombre_ingresa_art<<a.VerNombre();
	*cant_ingresa_art<<a.VerCantidadInt();
	*precio_ingresa_art<<a.VerPrecioFloat();
}

void VEditaArticulo::acepta_articulo( wxCommandEvent& event )  {

	//Creo variables auxiliares para los atributos del articulo a modificar
	long cantidad_art; 	
	string nombre;
	float precio; const char* aux;
	string nombre_archivo="articulos.dat";
	
	nombre=nombre_ingresa_art->GetValue(); //Obtengo los valores ingresados
	cant_ingresa_art->GetValue().ToLong(&cantidad_art);
	
	aux=precio_ingresa_art->GetValue().c_str();
	precio=strtof(aux,NULL); //Convierte el char* obtenido en float para guardarlo en precio
	
	Articulo art_aux(nombre,precio,cantidad_art); //Creo un articulo auxiliar

	string validacion=art_aux.ValidarDatos(nombre_archivo,false); //Llamo a validar de articulo
	if (validacion.size()){
		wxMessageBox(validacion); //Muestra los errores
		EndModal(0);
	} else {
		//Llama a las distintas funciones para modificar atributos 
		ManejoArticulos *manejo_articulos=Singleton2::ObtenerInstancia();
		(*manejo_articulos)[articulo_editar]=art_aux;
		//Guarda en el archivo y actualiza la grilla
		manejo_articulos->ActualizarLista();
		EndModal(1);
	}
}

VEditaArticulo::~VEditaArticulo() {
	
}

