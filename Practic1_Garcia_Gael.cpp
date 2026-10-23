#include <iostream>
using namespace std;

void identificarFigura(float A, float B, float C) {
    if (A > 0 && B == 0 && C == 0) {
        cout << "La figura es un circulo\n";
    } else if (A > 0 && B > 0 && C == 0) {
        if (A == B) cout << "La figura es un cuadrado\n";
        else cout << "La figura es un rectangulo\n";
    } else if (A > 0 && B > 0 && C > 0) {
        if (A + B > C && A + C > B && B + C > A) {
            if (A == B && B == C) cout << "La figura es un triangulo equilatero\n";
            else if (A == B || A == C || B == C) cout << "La figura es un triangulo isosceles\n";
            else cout << "La figura es un triangulo escaleno\n";
        } else {
            cout << "Los valores no indican figura\n";
        }
    } else {
        cout << "Los valores no indican figura\n";
    }
}

int main() {
    int opcion;
    float A, B, C;
    
    do {
        cout << "\n======================================";
        cout << "\n       CLASIFICADOR DE FIGURAS";
        cout << "\n======================================";
        cout << "\n1. Clasificar Figura";
        cout << "\n2. Salir";
        cout << "\nSeleccione una opcion: "; cin >> opcion;

        switch (opcion) {
            case 1: 
                cout << "A: "; cin >> A;
                cout << "B: "; cin >> B;
                cout << "C: "; cin >> C;
                identificarFigura(A, B, C);
                break;
        }
    } while (opcion != 2);

    return 0;
}