#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "Articulo.h"
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

class Venta{
	int cantidad;
	fecha fecha_venta;
	hora hora_venta;
	string nombre_art;
	float precio_total;
public:
	Venta();
	Venta(int cant_, string nombre_art_, string archivo_ventas, string archivo_art);

	//Muestra el precio final, cantidad o fecha de la venta
	string VerPrecioFinal();
	float VerPrecioFinalFloat() const;
	string VerCantidad();
	int VerCantidadInt() const;
	string VerNombre() const;
	string VerFecha();
	string VerHora();
	fecha VerFechaStruct() const;
	hora VerHoraStruct() const;
	
	//Lee o escribe cada registro desde/en el archivo
	void GuardarEnArchivo(ofstream &archivo);
	void LeerDesdeArchivo(ifstream &archivo);

};

#endif

