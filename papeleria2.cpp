#include <iostream>
using namespace std;

class papeleria{
    string productos;
    double valor_base;
    double precio_cobrado;  
    double impuesto;
    double resultado;
    double precio_esperado;
    bool cumple_ganancia;   

    const float iva = 0.16;
    const float aranceles = 0.07;
    const float descuento_inv = 0.05;
    const float descuento_prom = 0.1;
    const float ganancia_mise = 0.5;
    const float ganancia_dibu = 0.3;
    
public:
    papeleria(string, double, double, double);
    papeleria();
    void menu();
    void pedir_datos();
    void selector(int &, double &, string &);
    double calcular_iva_arancel(double &);
    double calcular_total_mise(double &);
    double calcular_descu_promo(double &);
    double calcular_total_dibu(double &); 
    double precio_esperado_mise(double &); 
    double precio_esperado_dibu(double &); 
    void verificar_ganancia();             
    void mostrar_datos();
};


papeleria::papeleria(string b, double c, double d, double e){
    productos = b;
    valor_base = c;
    precio_cobrado = d; 
    precio_esperado = e;
    impuesto = 0;
    resultado = 0;
    cumple_ganancia = false;
}

papeleria::papeleria(){
}

void papeleria::menu(){
    cout << "\n*** MENU PAPELERIA ***" << endl;
    cout << "1. Procesar Miscelanea" << endl;
    cout << "2. Procesar Dibujo" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion ---> ";
}

void papeleria::pedir_datos(){
    int opcion;
    do
    {
    system("cls");
    cout << "Digite el material: ";
    getline(cin, productos);
    
    cout << "Digite el valor base: ";
    cin >> valor_base;
    cin.ignore();

    cout << "Digite el precio cobrado: "; 
    cin >> precio_cobrado;
    cin.ignore();

        menu();
        selector(opcion, valor_base, productos);  
    } while (opcion != 3);
     
}

void papeleria::selector(int &opc, double &val_bas, string &prod){
    cin >> opc;

    switch (opc)
    {
    case 1: 
        resultado = calcular_total_mise(val_bas);
        precio_esperado = precio_esperado_mise(val_bas);
        verificar_ganancia();
        mostrar_datos();
        cin.ignore();
        system("pause");
        break;
        
    case 2: 
        resultado = calcular_total_dibu(val_bas);
        precio_esperado = precio_esperado_dibu(val_bas);
        verificar_ganancia();
        mostrar_datos();
        cin.ignore();
        system("pause");
        break;
        
    case 3:
        cout << "Saliendo..." << endl;
        system("pause");
        break;
        
    default:
        cout << "Opcion invalida" << endl;
        system("pause");
        break;
    }
}

double papeleria::calcular_iva_arancel(double &val_bas){
    return val_bas * (iva + aranceles);
}

double papeleria::calcular_total_mise(double &val_bas){
   impuesto = calcular_iva_arancel(val_bas);
   return val_bas + impuesto;
}

double papeleria::calcular_descu_promo(double &val_bas){
    return val_bas * (descuento_inv + descuento_prom);  
}

double papeleria::calcular_total_dibu(double &val_bas){ 
   double descuentos = calcular_descu_promo(val_bas);
   return val_bas - descuentos;
}

double papeleria::precio_esperado_mise(double &val_bas){  
    double costo_total = calcular_total_mise(val_bas);
    return costo_total * (1 + ganancia_mise);
}

double papeleria::precio_esperado_dibu(double &val_bas){  
    double costo_total = calcular_total_dibu(val_bas);
    return costo_total * (1 + ganancia_dibu);
}

void papeleria::verificar_ganancia(){  
    double precio_esperado;
    if (productos == "miscelanea") {
        precio_esperado = precio_esperado_mise(valor_base);
    } else {
        precio_esperado = precio_esperado_dibu(valor_base);
    }
    cumple_ganancia = (precio_cobrado >= precio_esperado);
}

void papeleria::mostrar_datos(){
    cout << "Producto: " << productos << endl;
    cout << "Costo total: " << resultado << endl;
    cout << "Cumple ganancia: ";
    if (cumple_ganancia == true) {
    cout << "SI\n";
    } else {
    cout << "NO\n";
    }
}

int main(){
    papeleria p("", 0, 0, 0);
    p.pedir_datos();
    return 0;
}