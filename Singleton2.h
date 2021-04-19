#ifndef SINGLETON2_H
#define SINGLETON2_H
#include "ManejoArticulos.h"

class Singleton2:public ManejoArticulos {
	static Singleton2 *instancia2; // puntero a la única instancia
	Singleton2():ManejoArticulos("articulos.dat"){}; // constructor privado
public:
	// Método para obtener la instancia, única forma de hacerlo
	static Singleton2 *ObtenerInstancia() {
		// si no hay instancia, la crea
		if (!instancia2) instancia2=new Singleton2();
		return instancia2;
	}
};

#endif
