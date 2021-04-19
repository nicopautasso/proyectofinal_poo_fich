#ifndef ARTICULOS_H
#define ARTICULOS_H

#include <iostream>
#include "Utiles.h"
using namespace std;

class Articulo{
	string nombre;
	float precio;
	int cantidad;
public:
	Articulo();
	//Construye un articulo nuevo
	Articulo(string nombre_, float precio_, int cantidad_);
	
	//Corrobora que los datos no sean invalidos o esten vacios
	string ValidarDatos(string archivo_articulos, bool verificar_nombre);
	
	//Muestra el id, nombre, precio o cantidad del articulo
	string VerId();
	string VerNombre();
	string VerPrecio();
	string VerCantidad();
	int VerCantidadInt();
	float VerPrecioFloat();
	
	//Lee o escribe cada registro desde/en el archivo
	void GuardarEnArchivo(ofstream &archivo);
	void LeerDesdeArchivo(ifstream &archivo);
	
	//Modifica el nombre, precio o cantidad del articulo
	void ModificarNombre(string nombre_);
	void ModificarPrecio(float precio_);
	void ModificarCantidad(int cantidad_);
	void RestarStock(int cantidad_);
};

#endif
