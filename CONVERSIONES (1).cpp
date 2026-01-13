#include <iostream>
#include <limits>
using namespace std;

const long int DOLAR = 4000;
const float PI = 3.14;
const int MEDIO_CIRCULO = 180;
const int OPCION = 5;

class conversion{
protected:
	float resultado_1;
public:
	conversion(float);
	void virtual pedir_datos() = 0;
	void virtual mostrar() = 0;
	void virtual calculo() = 0;
};

conversion::conversion(float resul_1){
	resultado_1 = resul_1;
}

class pesos_a_dolares:public conversion{
private:
	long int pesos;
public:
	pesos_a_dolares(long int, float);
	void pedir_datos() override;
	void mostrar() override;
	void calculo() override;
};

pesos_a_dolares::pesos_a_dolares(long int peso, float resul_1):conversion(resul_1){
	pesos = peso;
}

void pesos_a_dolares::pedir_datos(){
	cout << "escribe la cantidad de pesos: ";
	cin >> pesos;
}

void pesos_a_dolares::calculo(){
	resultado_1 = pesos/DOLAR;
}

void pesos_a_dolares::mostrar(){
	cout << "la conversion de '" << pesos << "' a dolares es: " << resultado_1 << endl;
}

class dolar_a_pesos:public conversion{
private:
	double dolar;
public:
	dolar_a_pesos(double, float);
	void pedir_datos() override;
	void mostrar() override;
	void calculo() override;
};

void dolar_a_pesos::pedir_datos(){
	cout << "escribe la cantidad de dolares: ";
	cin >> dolar;
}

void dolar_a_pesos::calculo(){
	resultado_1 = (dolar*DOLAR);
}

void dolar_a_pesos::mostrar(){
	cout << "la conversion de '" << dolar << "' a pesos es: " << resultado_1 << endl;
}

dolar_a_pesos::dolar_a_pesos(double dol, float resul_1):conversion(resul_1){
	dolar = dol;
}

class grados_a_radianes:public conversion{
private:
	int grados;
public:
	grados_a_radianes(int, float);
	void pedir_datos() override;
	void mostrar() override;
	void calculo() override;
};

grados_a_radianes::grados_a_radianes(int grad, float resul_1):conversion(resul_1){
	grados = grad;
}
void grados_a_radianes::pedir_datos(){
	cout << "escribe los grados:";
	cin >> grados;
}

void grados_a_radianes::calculo(){
	resultado_1 = (grados * (PI/MEDIO_CIRCULO));
}

void grados_a_radianes::mostrar(){
	cout << "la conversion de '" << grados << "' a radianes es: " << resultado_1 << endl;
}

class radianes_a_grados:public conversion{
private:
	float radianes;
public:
	radianes_a_grados(float, float);
	void pedir_datos() override;
	void mostrar() override;
	void calculo() override;
};

radianes_a_grados::radianes_a_grados(float radi, float resul_1):conversion(resul_1){
	radianes = radi;
}
void radianes_a_grados::pedir_datos(){
	cout << "escribe los radianes:";
	cin >> radianes;
}

void radianes_a_grados::calculo(){
	resultado_1 = (radianes * (MEDIO_CIRCULO/PI));
}

void radianes_a_grados::mostrar(){
	cout << "la conversion de '" << radianes << "' a grados es: " << resultado_1 << endl;
}

class sistema_conversion{
private:
	static void limpiar_buffert();
	static void pausar();
	static void limpiar_pantalla();
	
	static void mostrar_menu();
	static int validar_opcion();
	
	static void procesa_pesos_a_dolares();
	static void procesar_grados_a_radianes();
	static void procesar_radianes_a_grados();
	static void procesa_dolar_a_pesos();
public:
	static void ejecutar();
};

void sistema_conversion::limpiar_buffert(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void sistema_conversion::pausar(){
	system("pause");
}

void sistema_conversion::limpiar_pantalla(){
	system("cls");
}

void sistema_conversion::mostrar_menu(){
	cout << "***MENU_MULTI_ACCION***\n"
		<< "1. CONVERSION DE PESOS A DOLARES\n"
		<< "2. CONVERSION DE GRADOS A RADIANES\n"
		<< "3. CONVERSION DE RADIANES A GRADOS\n"
		<< "4. CONVERSION DE DOLAR A PESOS\n"
		<< "5. SALIR\n"
		<< "SELECCIONA UNA OPCION ---> ";
}

int sistema_conversion::validar_opcion(){
	int opcion;
	
	while(true){
		limpiar_pantalla();
		mostrar_menu();
		if(cin >> opcion){
			limpiar_buffert();
			if(opcion >= 1 && opcion <= 5){
				return opcion;
			}
			else {
				cout << "DEBE ESTAR EN LOS RANGOS 1 Y 5\n";
				pausar();
			}
		} else {
			limpiar_buffert();
			cout << "NO ES VALIDO LETRAS\n";
			pausar();
		}
	}
}

void sistema_conversion::procesa_pesos_a_dolares(){
	limpiar_pantalla();
	pesos_a_dolares peso_dolar(0,0);
	peso_dolar.pedir_datos();
	peso_dolar.calculo();
	limpiar_pantalla();
	peso_dolar.mostrar();
}

void sistema_conversion::procesar_grados_a_radianes(){
	limpiar_pantalla();
	grados_a_radianes grado_radian(0,0);
	grado_radian.pedir_datos();
	grado_radian.calculo();
	limpiar_pantalla();
	grado_radian.mostrar();
}

void sistema_conversion::procesar_radianes_a_grados(){
	limpiar_pantalla();
	radianes_a_grados radian_grado(0,0);
	radian_grado.pedir_datos();
	radian_grado.calculo();
	limpiar_pantalla();
	radian_grado.mostrar();
}

void sistema_conversion::procesa_dolar_a_pesos(){
	limpiar_pantalla();
	dolar_a_pesos dolar_pesos(0,0);
	dolar_pesos.pedir_datos();
	dolar_pesos.calculo();
	limpiar_pantalla();
	dolar_pesos.mostrar();
	
}

void sistema_conversion::ejecutar(){
	int opcion;
	
	do{
		opcion = validar_opcion();
		
		switch(opcion){
		case 1:
			procesa_pesos_a_dolares();
			limpiar_buffert();
			pausar();
			break;
		case 2:
			procesar_grados_a_radianes();
			limpiar_buffert();
			pausar();
			break;
		case 3:
			procesar_radianes_a_grados();
			limpiar_buffert();
			pausar();
			break;
		case 4:
			procesa_dolar_a_pesos();
			limpiar_buffert();
			pausar();
			break;
		case 5:
			cout << "HASTA LUEGO...\n";
			pausar();
			break;
		}
		
	}while(opcion != OPCION);
}

int main() {
	sistema_conversion::ejecutar();
	return 0;
}

