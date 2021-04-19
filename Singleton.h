#ifndef SINGLETON_H
#define SINGLETON_H
#include "ManejoVentas.h"

class Singleton:public ManejoVentas {
	static Singleton *instancia; // puntero a la �nica instancia
	Singleton():ManejoVentas("ventas.dat"){}; // constructor privado
public:
	// M�todo para obtener la instancia, �nica forma de hacerlo
	static Singleton *ObtenerInstancia() {
		// si no hay instancia, la crea
		if (!instancia) instancia=new Singleton();
		return instancia;
	}
};

#endif

