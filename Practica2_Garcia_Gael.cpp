#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double VALOR_PI = 3.14;
constexpr double VALOR_CERO = 0.0;
constexpr int OPCION_DETERMINAR = 1;
constexpr int OPCION_CALCULAR = 2;
constexpr int OPCION_SALIR = 3;

enum class TipoFigura {
    Cuadrado,
    Rectangulo,
    Circulo,
    TrianguloEquilatero,
    TrianguloIsosceles,
    TrianguloEscaleno,
    Ninguna
};

TipoFigura clasificarFigura(double ladoA, double ladoB, double ladoC) {
    if (ladoA > VALOR_CERO && ladoB == VALOR_CERO && ladoC == VALOR_CERO) {
        return TipoFigura::Circulo;
    } else if (ladoA > VALOR_CERO && ladoB > VALOR_CERO && ladoC == VALOR_CERO) {
        if (ladoA == ladoB) {
            return TipoFigura::Cuadrado;
        } else {
            return TipoFigura::Rectangulo;
        }
    } else if (ladoA > VALOR_CERO && ladoB > VALOR_CERO && ladoC > VALOR_CERO) {
        if ((ladoA + ladoB > ladoC) && (ladoA + ladoC > ladoB) && (ladoB + ladoC > ladoA)) {
            if (ladoA == ladoB && ladoB == ladoC) {
                return TipoFigura::TrianguloEquilatero;
            } else if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
                return TipoFigura::TrianguloIsosceles;
            } else {
                return TipoFigura::TrianguloEscaleno;
            }
        } else {
            return TipoFigura::Ninguna;
        }
    } else {
        return TipoFigura::Ninguna;
    }
}

void mostrarDeterminacion(TipoFigura figura) {
    if (figura == TipoFigura::Circulo) {
        std::cout << "La figura es un circulo\n";
    } else if (figura == TipoFigura::Cuadrado) {
        std::cout << "La figura es un cuadrado\n";
    } else if (figura == TipoFigura::Rectangulo) {
        std::cout << "La figura es un rectangulo\n";
    } else if (figura == TipoFigura::TrianguloEquilatero) {
        std::cout << "La figura es un triangulo equilatero\n";
    } else if (figura == TipoFigura::TrianguloIsosceles) {
        std::cout << "La figura es un triangulo isosceles\n";
    } else if (figura == TipoFigura::TrianguloEscaleno) {
        std::cout << "La figura es un triangulo escaleno\n";
    } else {
        std::cout << "Los valores no indican figura\n";
    }
}

double calcularArea(TipoFigura figura, double ladoA, double ladoB, double ladoC) {
    double area = VALOR_CERO;
    if (figura == TipoFigura::Cuadrado || figura == TipoFigura::Rectangulo) {
        area = ladoA * ladoB;
    } else if (figura == TipoFigura::Circulo) {
        area = VALOR_PI * (ladoA * ladoA);
    } else if (figura == TipoFigura::TrianguloEquilatero) {
        area = (std::sqrt(3.0) / 4.0) * (ladoA * ladoA);
    } else if (figura == TipoFigura::TrianguloEscaleno || figura == TipoFigura::TrianguloIsosceles) {
        // Usamos fórmula de Herón para ambos triángulos por fiabilidad matemática
        double semiperimetro = (ladoA + ladoB + ladoC) / 2.0;
        area = std::sqrt(semiperimetro * (semiperimetro - ladoA) * (semiperimetro - ladoB) * (semiperimetro - ladoC));
    }
    return area;
}

void mostrarArea(TipoFigura figura, double area) {
    std::cout << std::fixed << std::setprecision(2);
    if (figura == TipoFigura::Cuadrado) {
        std::cout << "El area del CUADRADO es " << area << "\n";
    } else if (figura == TipoFigura::Rectangulo) {
        std::cout << "El area del RECTANGULO es " << area << "\n";
    } else if (figura == TipoFigura::Circulo) {
        std::cout << "El area del CIRCULO es " << area << "\n";
    } else if (figura == TipoFigura::TrianguloEquilatero) {
        std::cout << "El area del TRIANGULO EQUILATERO es " << area << "\n";
    } else if (figura == TipoFigura::TrianguloIsosceles) {
        std::cout << "El area del TRIANGULO ISOSCELES es " << area << "\n";
    } else if (figura == TipoFigura::TrianguloEscaleno) {
        std::cout << "El area del TRIANGULO ESCALENO es " << area << "\n";
    }
}

void procesarMenu() {
    int opcionMenu = 0;
    double ladoA = VALOR_CERO;
    double ladoB = VALOR_CERO;
    double ladoC = VALOR_CERO;
    TipoFigura figuraActual = TipoFigura::Ninguna;

    do {
        std::cout << "\n1. Determine figura.\n";
        std::cout << "2. Calcule area.\n";
        std::cout << "3. Salir.\n";
        std::cout << "Opcion: ";
        std::cin >> opcionMenu;

        if (opcionMenu == OPCION_DETERMINAR) {
            std::cout << "A= "; std::cin >> ladoA;
            std::cout << "B= "; std::cin >> ladoB;
            std::cout << "C= "; std::cin >> ladoC;
            figuraActual = clasificarFigura(ladoA, ladoB, ladoC);
            mostrarDeterminacion(figuraActual);
        } else if (opcionMenu == OPCION_CALCULAR) {
            if (figuraActual == TipoFigura::Ninguna) {
                std::cout << "Primero debera determinar la figura en la opcion 1\n";
            } else {
                double areaCalculada = calcularArea(figuraActual, ladoA, ladoB, ladoC);
                mostrarArea(figuraActual, areaCalculada);
            }
        } else if (opcionMenu == OPCION_SALIR) {
            std::cout << "Hasta la proxima\n";
        } else {
            std::cout << "Opcion no valida\n";
        }
    } while (opcionMenu != OPCION_SALIR);
}

int main() {
    procesarMenu();
    return 0;
}