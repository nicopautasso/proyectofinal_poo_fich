#ifndef SINGLETON2_H
#define SINGLETON2_H
#include "ManejoArticulos.h"

class Singleton2:public ManejoArticulos {
	static Singleton2 *instancia2; // puntero a la �nica instancia
	Singleton2():ManejoArticulos("articulos.dat"){}; // constructor privado
public:
	// M�todo para obtener la instancia, �nica forma de hacerlo
	static Singleton2 *ObtenerInstancia() {
		// si no hay instancia, la crea
		if (!instancia2) instancia2=new Singleton2();
		return instancia2;
	}
};

#endif
