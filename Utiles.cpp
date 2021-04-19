#include <iostream>
#include "Utiles.h"
#include <ctime>

using namespace std;

void Minusculas(string &s){
	int cant=s.size();
	for (int i=0;i<cant;i++)
		 s[i]=tolower(s[i]);
};

fecha FechaSistema(){
	time_t now=time(0);
	tm* ltm=localtime(&now);
	
	int dia=ltm->tm_mday;
	int mes=1+ltm->tm_mon;
	int anio=1900+ltm->tm_year;
	
	fecha fecha_sistema;
	
	fecha_sistema.dia=ltm->tm_mday;
	fecha_sistema.mes=1+ltm->tm_mon;
	fecha_sistema.anio=1900+ltm->tm_year;
	
	return fecha_sistema;
}
