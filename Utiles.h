#ifndef UTILES_H
#define UTILES_H
#include <iostream>

using namespace std;

struct fecha{
	int dia;
	int mes;
	int anio;
};
struct hora{
	int hr;
	int min;
	int seg;
};
struct tipoventa{
	int cantidad;
	fecha fecha_venta;
	hora hora_venta;
	char nombre_art[256];
	float precio_total;
};
struct tipoarticulo{
	char nombre[256];
	float precio;
	int cantidad;
};

void Minusculas(string &s);

fecha FechaSistema();

#endif
