#include <iostream>
using namespace std;

// Prototipos de funciones
float solicitarLado(char nombreLado);
bool contieneCeros(float ladoA, float ladoB);
float calcularArea(float ladoA, float ladoB);
void mostrarResultado(float ladoA, float ladoB, float area);
void ejecutarCalculadoraArea();

// Función principal limpia
int main() {
    ejecutarCalculadoraArea();
    return 0;
}

// Función orquestadora
void ejecutarCalculadoraArea() {
    float ladoA = solicitarLado('A');
    float ladoB = solicitarLado('B');

    // Validación de la regla de negocio principal
    if (contieneCeros(ladoA, ladoB)) {
        cout << "Ninguno de los valores puede ser 0" << endl;
    } else {
        float area = calcularArea(ladoA, ladoB);
        mostrarResultado(ladoA, ladoB, area);
    }
}

// Función para el ingreso de datos
float solicitarLado(char nombreLado) {
    float valor;
    cout << "Ingrese el valor para el lado " << nombreLado << ": ";
    cin >> valor;
    return valor;
}

// Función para validar la restricción de ceros
bool contieneCeros(float ladoA, float ladoB) {
    return (ladoA == 0 || ladoB == 0);
}

// Función para procesar la operación matemática
float calcularArea(float ladoA, float ladoB) {
    return ladoA * ladoB;
}

// Función para evaluar la condición final e imprimir la salida
void mostrarResultado(float ladoA, float ladoB, float area) {
    if (ladoA == ladoB) {
        cout << "El resultado del area es: " << area << " y es un cuadrado" << endl;
    } else {
        cout << "El resultado del area es: " << area << endl;
    }
}