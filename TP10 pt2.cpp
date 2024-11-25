#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

bool compararPorEdad(const Persona& p1, const Persona& p2) {
    return p1.edad < p2.edad;
}

int main() {
    vector<Persona> personas;
    int cantidadPersonas;
    string nombre;
    int edad;
    cout << "Ingrese la cantidad de personas: ";
    cin >> cantidadPersonas;
    for (int i = 0; i < cantidadPersonas; i++) {
        cout << "Ingrese el nombre de la persona: ";
        cin >> nombre;
        cout << "Ingrese la edad de la persona: ";
        cin >> edad;
        Persona persona(nombre, edad);
        personas.push_back(persona);
    }
    sort(personas.begin(), personas.end(), compararPorEdad);
    cout << "\nPersonas ordenadas por edad:" << endl;
    for (int i = 0; i < personas.size(); i++) {
        personas[i].mostrarDatos();
    }
    return 0;
}
