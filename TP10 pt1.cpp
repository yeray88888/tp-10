#include <iostream>
#include <vector>
using namespace std;

class Alumno {
private:
    string nombre;
    float nota1, nota2, nota3;

public:
    Alumno(string _nombre, float _nota1, float _nota2, float _nota3) {
        nombre = _nombre;
        nota1 = _nota1;
        nota2 = _nota2;
        nota3 = _nota3;
    }

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Nota 3: " << nota3 << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    vector<Alumno> alumnos; 
    int cantidadAlumnos;
    string nombre;
    float nota1, nota2, nota3;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantidadAlumnos;
    for (int i = 0; i < cantidadAlumnos; i++) {
        cout << "Ingrese el nombre del alumno: ";
        cin >> nombre;
        cout << "Ingrese la nota 1: ";
        cin >> nota1;
        cout << "Ingrese la nota 2: ";
        cin >> nota2;
        cout << "Ingrese la nota 3: ";
        cin >> nota3;
        Alumno alumno(nombre, nota1, nota2, nota3);
        alumnos.push_back(alumno);
    }
    cout << "\nDatos de los alumnos:" << endl;
    for (int i = 0; i < alumnos.size(); i++) {
        alumnos[i].mostrarDatos();
    }
    return 0;
}
