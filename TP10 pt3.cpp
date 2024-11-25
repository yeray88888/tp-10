#include <iostream>
#include <vector>
using namespace std;

class Rectangulo {
public:
    float base;
    float altura;
    Rectangulo(float _base, float _altura) {
        base = _base;
        altura = _altura;
    }
    float calcularArea() const {
        return base * altura;
    }
    float calcularPerimetro() const {
        return 2 * (base + altura);
    }
};

int main() {
    vector<Rectangulo> rectangulos;
    int cantidadRectangulos;
    float base, altura;
    cout << "Ingrese la cantidad de rectangulos: ";
    cin >> cantidadRectangulos;
    for (int i = 0; i < cantidadRectangulos; i++) {
        cout << "Ingrese la base del rectangulo: ";
        cin >> base;
        cout << "Ingrese la altura del rectangulo: ";
        cin >> altura;
        Rectangulo rectangulo(base, altura);
        rectangulos.push_back(rectangulo);
    }
    cout << "\nArea y permetro de los rectangulos:" << endl;
    for (int i = 0; i < rectangulos.size(); i++) {
        cout << "Rectangulo " << i + 1 << ": " << endl;
        cout << "Area: " << rectangulos[i].calcularArea() << endl;
        cout << "Perimetro: " << rectangulos[i].calcularPerimetro() << endl;
        cout << "-----------------------" << endl;
    }
    return 0;
}
