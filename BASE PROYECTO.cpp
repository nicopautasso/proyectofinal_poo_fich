#include <iostream>
#include <fstream>
using namespace std;

struct tipoarticulo{
	char nombre[256];
	int id;
	float precio;
	int cantidad;
};

struct tipoventa{
	int id;
	int cantidad;
	fecha //ver
	int id_art;
	float precio_total;
};

struct tipoalerta{
	char caution[256];
	int id;
	int id_art
};

void Minusculas(string &s){
	int cant=s.size();
	for (int i=0;i<cant;i++)
		 s[i]=tolower(s[i]);
};

class Articulo{
	int id;
	string nombre;
	float precio;
	int cantidad;
public:
	//Construye un articulo nuevo
	Articulo(string nombre_, float precio_, int cantidad_, string archivo_){
		nombre=nombre_;
		precio=precio_;
		cantidad=cantidad_;
		//Busco el id del nuevo articulo
		ifstream archi1(archivo_,ios::binary|ios::ate);
		int cant_bytes=archi1.tellg();
		int cant_datos=cant_bytes/sizeof(tipoarticulo);
		archi1.close();
		id=cant_datos+1;
	}
	
	//Corrobora que los datos no sean invalidos o esten vacios
	string ValidarDatos(){
		string aux;
		if (nombre.size()==0) aux+="No se ingreso el nombre del articulo\r\n";
		if (precio.size()==0) aux+="No se ingreso precio del articulo\r\n";
		if (precio<0) aux+="El precio \r\n";
		if (cantidad.size()==0) aux+="No se ingreso la cantidad de articulos\r\n";
		if (cantidad<0) aux+="La cantidad del articulo es invalida\r\n";
		return aux;
	}
	
	//Muestra el id del articulo
	int VerId(){
		return id;
	}
	//Muestra el nombre, precio o cantidad del articulo
	string VerNombre(){
		return nombre;
	}
	int VerPrecio(){
		return precio;
	}
	int VerCantidad(){
		return cantidad;
	}
	
	//Modifica el nombre, precio o cantidad del articulo
	void ModificarNombre(string nombre_){
		nombre=nombre_;
	}
	void ModificarPrecio(float precio_){
		precio=precio_;		
	}
	void ModificarCantidad(int cantidad_){
		cantidad=cantidad_;		
	}
	
	//Distintos tipos de comparaciones que se invocan en la clase agenda para ordenar
	bool CompararPorNombre(Articulo a1, Articulo a2){
		string aux1=a1.VerNombre();
		string aux2=a2.VerNombre();
		if (aux1<aux2)
			return true;
	}
	bool CompararPorPrecio(Articulo a1, Articulo a2){
		float aux1=a1.VerPrecio();
		float aux2=a2.VerPrecio();
		if (aux1<aux2)
			return true;
	}
	bool CompararPorCantidad(Articulo a1, Articulo a2){
		int aux1=a1.VerPrecio();
		int aux2=a2.VerPrecio();
		if (aux1<aux2)
			return true;
	}
};

class ManejoArticulos{
	string archivo;
	vector<Articulo> v1;
public:
	//Recibe el nombre del archivo donde se guardan todas las alertas y las carga en el vector v_alerta
	ManejoArticulos(string archivo_){
		archivo=archivo_;
		ifstream archi1(archivo,ios::binary|ios::ate);
		if (archi1.is_open()){
			int cant_bytes=archi1.tellg();
			int cant_datos=cant_bytes/sizeof(tipoarticulo);
			archi1.seekg(0);
			v1.resize(cant_datos);
			for (int i=0; i<cant_datos; i++){
				tipoarticulo aux;
				archi1.read(reinterpret cast <char*> (&aux), sizeof(aux));
				v1[i].id=aux.id;
				v1[i].nombre=aux.nombre;
				v1[i].cantidad=aux.cantidad;
				v1[i].precio=aux.precio;
			}
		archi1.close();
		}
	}
	
	//Agrega un articulo al final del vector
	void AgregarArticulo(Articulo art_){
		v1.pushback(art_);
	}
	//Recibe el id (que es igual a su posicion), lo busca y lo elimina del archivo
	void BajaArticulo(int id_){
		v1.erase(id_);		
	}
	
	//Guarda el vector en el archivo (con verificacion)
	bool ActualizarLista(){
		ofstream archi2(archivo,ios::binary|ios::trunc);
		if (archi2.is_open()) return false;
		int cant=CantidadDatos();
		for (int i=0; i<cant; i++){
		tipoarticulo aux;
		strcpy(aux.nombre,nombre.c_str());
		aux.id=v_alerta[i].id;
		aux.cantidad=v_alerta[i].cantidad;
		aux.precio=v_alerta[i].precio;
		archi2.write(reinterpret cast <char*> (&aux), sizeof(aux));
		}
		archi2.close();
		return true;
	}
	int CantidadDatos(){
		return v1.size();
	}

	//Sobrecarga [] para que devuelva un elemento del vector (articulo) mediante su pos
	Articulo &operator[](int pos){
		return v1[pos];
	}
	
	int BuscarArticulo (string n_art, int desde){
		int cant=CantidadDatos();
		for (int i=desde; i<cant; i++){
			string aux=v1[i].VerNombre();
			Minusculas(aux);
			if (aux.find(n_art,0)!=string::npos){
				return aux;
			}
		}
	}
		
	Ordenar(int criterio){
		switch (criterio){
		case 1: v1.sort(v1.begin(),v1.end(),CompararPorNombre);
		case 2: v1.sort(v1.begin(),v1.end(),CompararPorPrecio);
		case 3: v1.sort(v1.begin(),v1.end(),CompararPorCantidad);
		}
	}
};

class Alerta{
	string caution;
	int id;
	int id_art;
public:
	//Construye una alerta nueva
	Alerta (string caution_, int id_, int id_art_, string archivo_){
		caution=caution_;
		id_art=id_art_;
		//Busco el id de la nueva alerta
		ifstream archi3(archivo_,ios::binary|ios::ate);
		int cant_bytes=archi1.tellg();
		int cant_datos=cant_bytes/sizeof(tipoalerta);
		archi3.close();
		id=cant_datos+1;
	}
	string VerCaution(){
		return caution;
	}
	int VerId(){
		return id;
	}
	int VerId_Art(){
		return id_art;
	}
};

class ManejoAlertas{
	string archivo;
	vector<Alerta> v_alerta;
public:
		ManejoAlertas(string archivo){
			ifstream archi1(archivo,ios::binary|ios::ate);
			if (archi1.is_open()){
				int cant_bytes=archi1.tellg();
				int cant_datos=cant_bytes/sizeof(tipoalerta);
				archi1.seekg(0);
				v_alerta.resize(cant_datos);
				for (int i=0; i<cant_datos; i++){
					tipoalerta aux;
					archi1.read(reinterpret cast <char*> (&aux), sizeof(aux));
					v_alerta[i].id=aux.caution;
					v_alerta[i].id=aux.id;
					v_alerta[i].id_art=aux.id_art;
				}
				archi1.close();
			}
		}
		
		//Agrega una nueva alerta
		AgregarAlerta(Alerta alerta_){
			v_alerta.pushback(alerta_);
		}
		
		//Elimina una alerta
		EliminarAlertas(int id_){
			v_alerta.erase(id_);
		}
		
		//Guarda el vector en el archivo (con verificacion)
		bool ActualizarLista(){
			ofstream archi2(archivo,ios::binary|ios::trunc);
			if (archi2.is_open()) return false;
			int cant=CantidadDatos();
			for (int i=0; i<cant; i++){
				tipoalerta aux;
				strcpy(aux.nombre,caution.c_str());
				aux.id=v_alerta[i].id;
				aux.id_art=v_alerta[i].id_art;
				archi2.write(reinterpret cast <char*> (&aux), sizeof(aux));
			}
			archi2.close();
			return true;
		}
		int CantidadDatos(){
			return v_alerta.size();
		}
		
		//Sobrecarga [] para que devuelva un elemento del vector (alerta) mediante su pos
		Alerta &operator[](int pos){
			return v_alerta[pos];
		}
		
		
		
		
};

class Venta{
	int id;
	int cantidad;
	fecha;
	int art_id;
	float precio_total;
public:
	Venta(int cant_, int art_id, archivo){
		//le llega la cantidad y el articulo vendido, agrega un id a la venta y su precio final (cant*precio_art)
		cantidad=cant_;
		ifstream archivo
		articulo aux;
	}
	
};

class ManejoVentas{
	string archivo;
	vector<Venta> v1;
	ManejoVentas(string archivo){
		//le llega el nombre donde se guardan todos las ventas y los carga al vector;
	}
	
	NuevaVenta(string archivo){
		//le llega un item, llama a validarVenta, si el codigo es dist a 0, muestra que no hay stock
		//sino la realiza y guarda la venta agregandolo al vector v1;
		//usa validarventa() y disminuirstock();
	}
	ValidarVenta(int id_prod){
		//se fija si hay stock del producto y retorna 0 si hay stock y uno si no;
	}
	DisminuirStock(){
		//resta la cantidad que fueron vendidas de x producto
		//hay que ver a que metodo de que clase envia esa cantidad para restarla
	}
	ActualizarLista(){
		//guarda el archivo y retorna un mensaje que se realizo la venta con exito (if actualizarlista());
	}
	
};
int main(int argc, char *argv[]) {
	
	return 0;
}

