#ifndef MANEJAARTICULOS_H
#define MANEJAARTICULOS_H

#include <iostream>
#include "Articulo.h"
#include <vector>
using namespace std;

class ManejoArticulos{
	string archivo;
	vector<Articulo> v_articulos;
public:
	//Recibe el nombre del archivo donde se guardan todas las alertas y las carga en el vector v_alerta
	ManejoArticulos(string archivo_);
	
	//Se fija si un articulo ya esta en el vector (se usa en ValidacionDatos() de Articulo)
	bool ArticuloExiste(string nombre_);
	
	//Agrega un articulo al final del vector
	void AgregarArticulo(Articulo art_);
	
	//Recibe la fila y lo elimina del vector
	void BajaArticulo(int fila);
	
	//Se fija si el articulo esta sin stock
	bool ArticuloConPocoStock(Articulo artic);
	
	//Modifica el stock de determinado articulos restandole la cantidad que se le pasa
	void ModificarStock(int pos, int cantidad_restar);
	
	//Guarda el vector de articulos en el archivo (con verificacion)
	bool ActualizarLista();
	int CantidadDatos();
	
	//Sobrecarga [] para que devuelva un elemento del vector (articulo) mediante su pos
	Articulo &operator[](int pos);
	
	void Ordenar(int criterio);
		
	//Busca en el arreglo las coincidencias a partir de un articulo ingresado en la busqueda
	int BuscarArticulo(string n_art, int desde);
	
	//Retorna el precio o cantidad de un articulo a partir de una pos
	float BuscarPrecioArticulo (int pos_art);
	int BuscarCantidadArticulo (int pos_art);
	
	//Busca la posicion de un articulo en el vector a partir del nombre
	int BuscarArticuloModificar(string nombre_art); 
};

#endif
