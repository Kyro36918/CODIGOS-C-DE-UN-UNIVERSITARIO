#include <iostream>
#include <limits>
using namespace std;

const long int 	DURACION = 110;
const long int COSTO_MAX = 18000;
const long int COSTO_MINI = 12000;
const char CLASIFICACION = 'r';

class peliculas{
	protected:
	string titulo;
	long int duracion, resultado;


	public:
	peliculas(string, long int, long int);
	virtual void pedir_datos() = 0;
	virtual void costo() = 0;
	virtual void mostrar_datos()  = 0;

	static void limpiar_buffer();
};

void peliculas::limpiar_buffer(){
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

peliculas::peliculas(string titu, long int dura, long int resul){
	titulo = titu;
	duracion = dura;
	resultado = resul;
}

class peli_accion: public peliculas {
	string protagonista, director;

	public:
	peli_accion(string, string, string, long int, long int);
	void pedir_datos() override;
	void costo() override;
	void mostrar_datos() override;
};

peli_accion::peli_accion(string prota, string direc, string titu, long int dura, long int resul):peliculas(titu, dura, resul){
	protagonista = prota;
	director = direc;
}

void peli_accion::pedir_datos(){
	cout << "escribe el titulo de la pelicula: ";
	getline(cin,titulo);

	cout << "escribe el protagonista de la pelicula: ";
	getline(cin, protagonista);

	cout << "escribe el director de la pelicula: ";
	getline(cin, director);

	cout << "escribe la duracion de la pelicula: ";
	cin >> duracion;
}

void peli_accion::costo(){
	if (duracion > DURACION)
	{
		resultado = COSTO_MAX;
	}
	else
	{
		resultado = COSTO_MINI;
	}
}

void peli_accion::mostrar_datos(){
	cout << "TITULO: " << titulo;
	cout << "\nPROTAGONISTA: " << protagonista;
	cout << "\nDIRECTOR: " << director;
	cout << "\nDURACION: " << duracion;
	cout << "\nCOSTO: " << resultado;
	cout << endl;
}

class peli_terror:public peliculas{
	char clasificacion;
	string idioma;

	public:
	peli_terror(char, string, string, long int, long int);
	void pedir_datos() override;
	void costo() override;
	void mostrar_datos() override;
};

peli_terror::peli_terror(char clasi, string idio, string titu, long int dura, long int resul):peliculas(titu, dura, resul){
	clasificacion = clasi;
	idioma = idio;
}

void peli_terror::pedir_datos(){
	cout << "escribe el titulo de la pelicula: ";
	getline(cin, titulo);

	cout << "escribe la clasificacion de la pelicula: ";
	cin >> clasificacion;
	
	limpiar_buffer();

	cout << "escribe el idioma de la pelicula: ";
	getline(cin,idioma);

	cout << "escribe la duracion de la pelicula: ";
	cin >> duracion;
}

void peli_terror::costo(){
	if (tolower(clasificacion) == 	CLASIFICACION)
	{
		resultado = COSTO_MAX;
	}
	else
	{
		resultado = COSTO_MINI;
	}
}

void peli_terror::mostrar_datos(){
	cout << "TITULO: " << titulo;
	cout << "\nCLASIFICACION: " << clasificacion;
	cout << "\nIDIOMA: " << idioma;
	cout << "\nDURACION " << duracion;
	cout << "\nCOSTO: " << resultado;
	cout << endl;
}

class sistema_peliculas{
	static void mostrar_menu();
	static void procesar_peli_accion();
	static void procesa_peli_terror();

	static void pausar();
	static void limpiar_pantalla();
	static void limpiar_buffer();

	public:
	static void ejecutar();
};

void sistema_peliculas::mostrar_menu(){
	cout << "\n***SISTEMA DE COBRO DE PELICULAS***\n"
		 << "1. PELICULAS DE ACCION\n"
		 << "2. PELICULAS DE TERROR\n"
		 << "3. SALIR\n"
		 << "SELECIONA ---> ";
}

void sistema_peliculas::procesar_peli_accion(){
	limpiar_pantalla();
	peli_accion peli_acc ("_","_","_", 0, 0);
	peli_acc.pedir_datos();
	peli_acc.costo();
	limpiar_pantalla();
	peli_acc.mostrar_datos();
}

void sistema_peliculas::procesa_peli_terror(){
	limpiar_pantalla();
	peli_terror peli_terr('_', "_", "_", 0, 0);
	peli_terr.pedir_datos();
	peli_terr.costo();
	limpiar_pantalla();
	peli_terr.mostrar_datos();
}

void sistema_peliculas::pausar(){
	system("pause");
}

void sistema_peliculas::limpiar_pantalla(){
	system("cls");
}

void sistema_peliculas::limpiar_buffer(){
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void sistema_peliculas::ejecutar(){
	int opcion;
	do
	{
		limpiar_pantalla();
		mostrar_menu();
		cin >> opcion;
		limpiar_buffer();

		switch (opcion)
		{
		case 1:
			procesar_peli_accion();
			limpiar_buffer();
			pausar();
			break;
		case 2:
			procesa_peli_terror();
			limpiar_buffer();
			pausar();
			break;
		case 3:
			cout << "GRACIAS HASTA LUEGO...";
			pausar();
			break;
		default:
			cout << "OPCION NO VALIDA";
			pausar();
			break;
		}

	} while (opcion != 3);
	
}

int main() {
	sistema_peliculas::ejecutar();
	return 0;
}

