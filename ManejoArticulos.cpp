#include <iostream>
#include "Articulo.h"
#include "ManejoArticulos.h"
#include "Utiles.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool CompararPorNombre(Articulo a1, Articulo a2){
	string aux1=a1.VerNombre();
	string aux2=a2.VerNombre();
	return aux1<aux2;
}
bool CompararPorPrecio(Articulo a1, Articulo a2){
	float aux1=a1.VerPrecioFloat();
	float aux2=a2.VerPrecioFloat();
	return aux1<aux2;
}
bool CompararPorCantidad(Articulo a1, Articulo a2){
	int aux1=a1.VerCantidadInt();
	int aux2=a2.VerCantidadInt();
	return aux1<aux2;
}

	//Recibe el nombre del archivo donde se guardan todas los archivos y los carga en el vector v_articulos
	ManejoArticulos::ManejoArticulos(string archivo_){
	archivo=archivo_;
	ifstream archi1(archivo.c_str(),ios::binary|ios::ate);
	if (archi1.is_open()){
		int cant_bytes=archi1.tellg();
		int cant_datos=cant_bytes/sizeof(tipoarticulo);
		v_articulos.resize(cant_datos);
		archi1.seekg(0,ios::beg);
		for (int i=0; i<cant_datos; i++){
			v_articulos[i].LeerDesdeArchivo(archi1);
			}
		archi1.close();
		}
	}
	
	//Se fija si el nombre de un articulo ya esta en el vector (se usa en ValidacionDatos() de Articulo)
	bool ManejoArticulos::ArticuloExiste(string nombre_){
		int cant_datos=(v_articulos.size());
		bool resultado=false;
		Minusculas(nombre_);
		for (int i=0; i<cant_datos; i++){
			string aux=v_articulos[i].VerNombre();
			Minusculas(aux);
			if (aux==nombre_){
				resultado=true;
			}
		}
		return resultado;
	}
	
	//Agrega un articulo al final del vector
	void ManejoArticulos::AgregarArticulo(Articulo art_){
		v_articulos.push_back(art_);
	}
	//Recibe su posicion, lo busca y lo elimina del archivo
	void ManejoArticulos::BajaArticulo(int pos){
		v_articulos.erase(v_articulos.begin()+(pos));
	}
	
	//Se fija si el articulo esta sin stock
	bool ManejoArticulos::ArticuloConPocoStock(Articulo artic){
		if (artic.VerCantidadInt()<=10)
			return true;
	}
	
	//Modifica el stock de determinado articulos restandole la cantidad que se le pasa
	void ManejoArticulos::ModificarStock(int pos, int cantidad_restar){
		v_articulos[pos].RestarStock(cantidad_restar);
	}
	
	
	//Guarda el vector de articulos en el archivo (con verificacion)
	bool ManejoArticulos::ActualizarLista(){
		ofstream archi2(archivo.c_str(),ios::binary|ios::trunc);
		if (!archi2.is_open()) return false;
		int cant=CantidadDatos();
		for (int i=0; i<cant; i++){
			v_articulos[i].GuardarEnArchivo(archi2);
		}
		archi2.close();
		return true;
	}
	int ManejoArticulos::CantidadDatos(){
		return v_articulos.size();
	}
	
	//Sobrecarga [] para que devuelva un elemento del vector (articulo) mediante su pos
	Articulo &ManejoArticulos::operator[](int pos){
		return v_articulos[pos];
	}
	
	//Busca en el arreglo las coincidencias a partir de un articulo ingresado en la busqueda
	int ManejoArticulos::BuscarArticulo(string n_art, int desde){
		Minusculas(n_art);
		int cant=CantidadDatos();
		for (int i=desde; i<cant; i++){
			string aux=v_articulos[i].VerNombre();
			Minusculas(aux);
			if (aux.find(n_art,0)!=string::npos){
				return i;
			}
		}
		return -1;
	}
	
	float ManejoArticulos::BuscarPrecioArticulo (int pos_art){ //Retorna el precio de un articulo a partir de una pos
		return v_articulos[pos_art].VerPrecioFloat();
	}
	int ManejoArticulos::BuscarCantidadArticulo (int pos_art){ //Retorna la cantidad de articulos en stock a partir de una pos
		return v_articulos[pos_art].VerCantidadInt();
	}
	
	int ManejoArticulos::BuscarArticuloModificar(string nombre_art){ //Busca la posicion de un articulo en el vector a partir del nombre
		int cant_articulos=CantidadDatos(); 
		
		for (int i=0;i<cant_articulos;i++){
			if (v_articulos[i].VerNombre()==nombre_art){
				return i;
			}
		}	
	}
	
	void ManejoArticulos::Ordenar(int criterio){
		switch (criterio){
		case 1: 
			sort(v_articulos.begin(),v_articulos.end(),CompararPorNombre);
			break;
		case 2: 
			sort(v_articulos.begin(),v_articulos.end(),CompararPorPrecio);
			break;
		case 3: 
			sort(v_articulos.begin(),v_articulos.end(),CompararPorCantidad);
			break;
		}
	}

