/**
 * EJERCICIOS COMPLETOS DE FUNCIONES EN C++
 * Desde básico hasta avanzado - Guía práctica
 * 
 * Autor: KYRO
 * Fecha: 21/11/2025
 */

#include <iostream>
using namespace std;

// ===================================================================
// NIVEL 1: FUNCIONES BÁSICAS
// ===================================================================

/**
 * Función utilitaria
 * Funciones que te sirven para manejar el flujo
 * puede ser limpiar pantalla, pausar, limpiar el buffert
 * o crear un menu
 * ejemplo
 */
void limpiar_buffert_simple(){
    cin.clear();
    cin.ignore();
}

void pausar(){
    cout << "pulsa enter para continuar...";
    cin.get();
}

/**
 * Ejercicio 1: Función sin parámetros
 * Crea una función llamada saludar que no reciba parámetros 
 * y muestre "¡Hola Mundo!" en pantalla.
 */
void saludar() {
    cout << "¡Hola Mundo!" << endl;
}

/**
 * Ejercicio 2: Función con parámetros y retorno
 * Crea una función llamada sumar que reciba dos números enteros 
 * y retorne la suma de ambos.
 */
int sumar(int a, int b) {
    return a + b;
}

// ===================================================================
// NIVEL 2: PARÁMETROS Y REFERENCIAS  
// ===================================================================

/**
 * Ejercicio 3: Parámetros por valor vs referencia
 * duplicarPorValor: recibe entero por valor (copia)
 * duplicarPorReferencia: recibe entero por referencia (original modifica)
 */
void duplicarPorValor(int numero) {
    numero = numero * 2;
    cout << "Dentro de duplicarPorValor: " << numero << endl;
}

void duplicarPorReferencia(int &numero) {
    numero = numero * 2;
    cout << "Dentro de duplicarPorReferencia: " << numero << endl;
}

/**
 * Ejercicio 4: Intercambiar valores
 * Crea una función intercambiar que reciba dos números por referencia 
 * y intercambie sus valores.
 */
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ===================================================================
// NIVEL 3: SOBRECARGA Y VALORES POR DEFECTO
// ===================================================================

/**
 * Ejercicio 5: Sobrecarga de funciones multiplicar
 * Cuatro versiones sobrecargadas:
 */
int multiplicar(int a, int b) {
    return a * b;
}

double multiplicar(double a, double b) {
    return a * b;
}

int multiplicar(int a, int b, int c) {
    return a * b * c;
}

double multiplicar(double a, double b, double c) {
    return a * b * c;
}

/**
 * Ejercicio 6: Parámetros con valores por defecto
 * Crea una función mostrarInfo que reciba nombre (obligatorio), 
 * edad (por defecto 0) y ciudad (por defecto "Desconocida").
 */
void mostrarInfo(string nombre, int edad = 0, string ciudad = "Desconocida") {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Ciudad: " << ciudad << endl;
    cout << "-------------------" << endl;
}

// ===================================================================
// NIVEL 4: RECURSIVIDAD
// ===================================================================

/**
 * Ejercicio 7: Función recursiva factorial
 * Calcula el factorial de un número de forma recursiva.
 * factorial(n) = n * factorial(n-1)
 * Caso base: factorial(0) = 1, factorial(1) = 1
 */
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/**
 * Ejercicio 8: Función recursiva fibonacci  
 * Calcula el n-ésimo número de Fibonacci.
 * fibonacci(0) = 0, fibonacci(1) = 1
 * fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
 */
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ===================================================================
// NIVEL 5: CONST Y EFICIENCIA
// ===================================================================

/**
 * Ejercicio 9: Parámetros const y referencias
 * modificarString: recibe string por referencia y lo modifica
 * soloLeerString: recibe string por referencia constante (solo lectura)
 */
void modificarString(string &texto) {
    texto += " - MODIFICADO";
}

void soloLeerString(const string &texto) {
    cout << "Leyendo: " << texto << endl;
    // texto += " - ERROR"; // Esto no compilaría (const)
}

/**
 * Ejercicio 10: Funciones inline para optimización
 * Funciones pequeñas y frecuentes para mejor rendimiento
 */
inline int cuadrado(int x) {
    return x * x;
}

inline int cubo(int x) {
    return x * x * x;
}

inline bool esPar(int x) {
    return (x % 2 == 0);
}

// ===================================================================
// FUNCIONES DE DEMOSTRACIÓN Y PRUEBAS
// ===================================================================

/**
 * Función para demostrar todos los ejercicios
 * Muestra el uso práctico de cada concepto aprendido
 */
void demostrarEjercicios() {
    cout << "=== DEMOSTRACIÓN DE EJERCICIOS COMPLETOS ===" << endl << endl;
    
    // NIVEL 1
    cout << "1. NIVEL 1: FUNCIONES BÁSICAS" << endl;
    saludar();
    cout << "Suma: 5 + 3 = " << sumar(5, 3) << endl << endl;
    
    // NIVEL 2  
    cout << "2. NIVEL 2: PARAMETROS Y REFERENCIAS" << endl;
    int x = 5;
    cout << "Valor original: " << x << endl;
    
    duplicarPorValor(x);
    cout << "Despues de duplicarPorValor: " << x << " (no cambia)" << endl;
    
    duplicarPorReferencia(x);
    cout << "Despues de duplicarPorReferencia: " << x << " (sí cambia)" << endl;
    
    int a = 10, b = 20;
    cout << "Antes de intercambiar: a=" << a << ", b=" << b << endl;
    intercambiar(a, b);
    cout << "Despues de intercambiar: a=" << a << ", b=" << b << endl << endl;
    
    // NIVEL 3
    cout << "3. NIVEL 3: SOBRECARGA Y VALORES POR DEFECTO" << endl;
    cout << "multiplicar(3, 4) = " << multiplicar(3, 4) << endl;
    cout << "multiplicar(2.5, 3.5) = " << multiplicar(2.5, 3.5) << endl;
    cout << "multiplicar(2, 3, 4) = " << multiplicar(2, 3, 4) << endl;
    cout << "multiplicar(1.5, 2.5, 3.5) = " << multiplicar(1.5, 2.5, 3.5) << endl;
    
    cout << "\nValores por defecto:" << endl;
    mostrarInfo("Ana", 25, "Madrid");
    mostrarInfo("Carlos", 30);
    mostrarInfo("Maria");
    cout << endl;
    
    // NIVEL 4
    cout << "4. NIVEL 4: RECURSIVIDAD" << endl;
    cout << "factorial(5) = " << factorial(5) << endl;
    cout << "factorial(0) = " << factorial(0) << endl;
    cout << "fibonacci(7) = " << fibonacci(7) << endl;
    cout << "fibonacci(10) = " << fibonacci(10) << endl << endl;
    
    // NIVEL 5
    cout << "5. NIVEL 5: CONST Y EFICIENCIA" << endl;
    string texto = "Hola Mundo";
    cout << "Texto original: " << texto << endl;
    
    modificarString(texto);
    cout << "Despues de modificar: " << texto << endl;
    
    soloLeerString(texto);
    
    int numero = 4;
    cout << "cuadrado(" << numero << ") = " << cuadrado(numero) << endl;
    cout << "cubo(" << numero << ") = " << cubo(numero) << endl;
    cout << "esPar(" << numero << ") = " << (esPar(numero) ? "true" : "false") << endl; //condicional ternario (esPar(numero) ? "true" : "false")
    //condicion? si es verdadero: si es falso
    //NIVEL 1 
    limpiar_buffert_simple();
    pausar();
}

/**
 * Función principal - Punto de entrada del programa
 * Coordina la ejecución de todas las demostraciones
 */
int main() {
    cout << "INICIANDO PRACTICA DE FUNCIONES C++" << endl;
    cout << "=======================================" << endl << endl;
    
    demostrarEjercicios();
    
    cout << endl << "TODOS LOS EJERCICIOS COMPLETADOS EXITOSAMENTE" << endl;
    cout << "Conceptos dominados: funciones basicas, parámetros, " << endl;
    cout << "referencias, sobrecarga, recursividad, optimización" << endl;
    
    return 0;
}

// ===================================================================
// BUENAS PRÁCTICAS Y CONCEPTOS CLAVES
// ===================================================================

/**
 * BUENAS PRÁCTICAS IMPLEMENTADAS
 * 
 * Nombres descriptivos para funciones y variables
 * Comentarios documentando propósito y parámetros
 * Organización por niveles de dificultad
 * Separación clara de responsabilidades
 * Uso apropiado de const para parámetros de solo lectura
 * Funciones inline para operaciones pequeñas y frecuentes
 * Manejo correcto de referencias vs valores
 * Casos base bien definidos en recursión
 * 
 * CONCEPTOS CLAVE CUBIERTOS
 * 
 * Declaración e implementación de funciones
 * Parámetros por valor y por referencia
 * Valores de retorno
 * Sobrecarga de funciones
 * Parámetros con valores por defecto
 * Recursividad y casos base
 * Optimización con funciones inline
 * Const-correctness
 * Organización y modularidad
 * 
 * CLAVE PARA ENTENDER CODIGO
 * 
 * Siempre analizen linea por linea
 * Si no entienden has una prueba de escritorio, siguiendo el flujo
 */