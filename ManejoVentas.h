#ifndef MANEJOVENTAS_H
#define MANEJOVENTAS_H

#include <iostream>
#include "Venta.h"
#include <vector>
using namespace std;

class ManejoVentas{
	string archivo;
	vector<Venta> v_venta;
	vector<Venta> v_ventashoy;
public:
	ManejoVentas(string archivo_);
	
	void NuevaVenta(Venta venta_);
	void NuevaVentaHoy(Venta venta_);
	
	void EliminarVenta(int pos);
	void EliminarVentasHoy();
	
	//Guarda el vector de ventas en el archivo (con verificacion)
	bool ActualizarLista();
	
	int CantidadDatos();
	int CantidadDatosHoy();
	
	//Sobrecarga [] para que devuelva un elemento del vector (venta) mediante su pos
	Venta &operator[](int pos);
	Venta &VentasHoy(int pos);
	
	void Ordenar(int criterio);
	void OrdenarHoy(int criterio);
};

#endif
