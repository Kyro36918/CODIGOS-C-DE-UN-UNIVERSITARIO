#include <iostream>
#include <limits> 
using namespace std;

const int CAPACIDA_CARGA = 1;
const float PORCENTAJE_IMP_CARGA_1 = 1.04;
const float PORCENTAJE_IMP_CARGA_2 = 1.07;

const int MODELO_1 = 2010;
const int MODELO_2 = 2014;
const float PORCENTAJE_IMP_TRANS_1 = 1.025;
const float PORCENTAJE_IMP_TRANS_2 = 1.015;

class impuesto_vehiculo{
	protected:
	string marca, placa;
	long int avaluo, resultado;
	static void limpiar_buffer();
	public: 
	impuesto_vehiculo(string, string, long int, long int);
	void virtual pedir_datos() = 0;
	void virtual costo() = 0;
	void virtual mostrar_datos() = 0;
};

impuesto_vehiculo::impuesto_vehiculo(string mar, string pla, long int aval, long int resul){
	marca = mar;
	placa = pla;
	avaluo = aval;
	resultado = resul;
}

static void limpiar_buffer(){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class vehiculo_pesado:public impuesto_vehiculo{
	int capacidad_carga;

	public:
	vehiculo_pesado(int, string, string, long int, long int);
	void pedir_datos() override;
	void costo() override;
	void mostrar_datos() override;
};

vehiculo_pesado::vehiculo_pesado(int cap_carg, string mar, string pla, long int aval, long int resul):impuesto_vehiculo(mar, pla, aval, resul){
	capacidad_carga = cap_carg;
}

void vehiculo_pesado::pedir_datos(){
	cout << "escribe la marca del vehiculo: ";
	getline(cin, marca);

	cout << "escribe la placa del vehiculo: ";
	getline(cin, placa);

	cout << "escribe el avaluo: ";
	cin >> avaluo;
	limpiar_buffer();

	cout << "escribe la capacida de carga: ";
	cin >> capacidad_carga;
}

void vehiculo_pesado::costo(){
	if (capacidad_carga <= CAPACIDA_CARGA)
	{
		resultado = avaluo*PORCENTAJE_IMP_CARGA_1;
	}
	else
	{
		resultado = avaluo*PORCENTAJE_IMP_CARGA_2;
	}
}

void vehiculo_pesado::mostrar_datos(){
	cout << "MARCA DEL VEHICULO: " << marca;
	cout << "PLACA DEL VEHICULO: " << placa;
	cout << "AVALUO DEL VEHICULO: " << avaluo;
	cout << "AVALUO MAS IMPUESTO: " << resultado;
}

class vehiculo_transporte: public impuesto_vehiculo{
	int modelo;

	public:
	vehiculo_transporte(int, string, string, long int, long int);
	void pedir_datos() override;
	void costo() override;
	void mostrar_datos() override;
};

vehiculo_transporte::vehiculo_transporte(int mode, string mar, string pla, long int aval, long int resul):impuesto_vehiculo(mar, pla, aval, resul){
	modelo = mode;
}

void vehiculo_transporte::pedir_datos(){
	cout << "escribe la marca del vehiculo: ";
	getline(cin, marca);

	cout << "escrive la placa del vehiculo: ";
	getline(cin, placa);

	cout << "escribe el avaluo del vehiculo: ";
	cin >> avaluo;
	limpiar_buffer();

	cout << "escribe el modelo del vehiculo: ";
	cin >> modelo;
}

void vehiculo_transporte::costo(){
	if (modelo >= MODELO_1 && modelo <= MODELO_2)
	{
		resultado = avaluo*PORCENTAJE_IMP_TRANS_1;
	}
	else
	{
		resultado = avaluo*PORCENTAJE_IMP_TRANS_2;
	}
	
}

void vehiculo_transporte::mostrar_datos(){
	cout << "MARCA DEL VEHICULO: " << marca;
	cout << "PLACA DEL VEHICULO: " << placa;
	cout << "AVALUO DEL VEHICULO: " << avaluo;
	cout << "MODELO DEL VEHICULO: " << modelo;
}

class sistema_vehiculo{
	static void mostrar_menu();
	static void procesar_vehiculo_carga();
	static void procesa_vehiculo_transporte();
	
	static void pausar();
	static void limpiar_pantalla();
	static void limpiar_buffer();

	public:
	static void ejecutar();
};

void sistema_vehiculo::mostrar_menu(){
	cout << "***SISTEMA DE IMPUESTO DE VEHICULOS***\n"
		 << "1. VEHICULO DE CARGA\n"
		 << "2. VEHICULO DE TRANSPORTE\n"
		 << "3. SALIR\n"
		 << "SELECIONA ---> ";
}

void sistema_vehiculo::procesar_vehiculo_carga(){
	limpiar_pantalla();
	vehiculo_pesado vehi_pesa(0, "_", "_", 0, 0);
	vehi_pesa.pedir_datos();
	vehi_pesa.costo();
	limpiar_pantalla();
	vehi_pesa.mostrar_datos();
}

void sistema_vehiculo::procesa_vehiculo_transporte(){
	limpiar_pantalla();
	vehiculo_transporte vehi_trans(0, "_", "_", 0, 0);
	vehi_trans.pedir_datos();
	vehi_trans.costo();
	limpiar_pantalla();
	vehi_trans.mostrar_datos();
}

void sistema_vehiculo::pausar(){
	system ("pause");
}

void sistema_vehiculo::limpiar_pantalla(){
	system ("cls");
}

void sistema_vehiculo::limpiar_buffer(){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void sistema_vehiculo::ejecutar(){
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
			procesar_vehiculo_carga();
			limpiar_buffer();
			pausar();
			break;
		case 2:
			procesa_vehiculo_transporte();
			limpiar_buffer();
			pausar();
			break;
		case 3:
			cout << "GRACIAS HASTA LUEGO...\n";
			pausar();
			break;
		default:
			cout << "OPCION NO VALIDA\n";
			pausar();
			break;
		}

	} while (opcion != 3);

}

int main() {
	sistema_vehiculo::ejecutar();
	return 0;
}

