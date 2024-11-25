#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Empleado {
public:
    string nombre;
    float salario;
    string departamento;
    Empleado(string _nombre, float _salario, string _departamento) {
        nombre = _nombre;
        salario = _salario;
        departamento = _departamento;
    }
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "-----------------------" << endl;
    }
};

bool compararPorSalario(const Empleado& e1, const Empleado& e2) {
    return e1.salario > e2.salario; 
}

int main() {
    vector<Empleado> empleados;
    int cantidadEmpleados;
    string nombre, departamento;
    float salario;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> cantidadEmpleados;
    for (int i = 0; i < cantidadEmpleados; i++) {
        cout << "Ingrese el nombre del empleado: ";
        cin.ignore(); 
        getline(cin, nombre);
        cout << "Ingrese el salario del empleado: ";
        cin >> salario;
        cout << "Ingrese el departamento del empleado: ";
        cin.ignore(); 
        getline(cin, departamento);
        Empleado empleado(nombre, salario, departamento);
        empleados.push_back(empleado);
    }
    sort(empleados.begin(), empleados.end(), compararPorSalario);
    cout << "\nEmpleados ordenados por salario de mayor a menor:" << endl;
    for (int i = 0; i < empleados.size(); i++) {
        empleados[i].mostrarDatos();
    }
    return 0;
}
