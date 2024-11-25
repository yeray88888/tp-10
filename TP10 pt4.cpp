#include <iostream>
#include <vector>
using namespace std;

class CuentaBancaria {
public:
    int numeroCuenta;
    string nombreTitular;
    float saldo;
    CuentaBancaria(int _numeroCuenta, string _nombreTitular, float _saldo) {
        numeroCuenta = _numeroCuenta;
        nombreTitular = _nombreTitular;
        saldo = _saldo;
    }

    void mostrarDatos() const {
        cout << "Número de cuenta: " << numeroCuenta << endl;
        cout << "Nombre del titular: " << nombreTitular << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "-----------------------" << endl;
    }

    void depositar(float cantidad) {
        saldo += cantidad;
        cout << "Depósito exitoso. Nuevo saldo: " << saldo << endl;
    }

    void retirar(float cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }
};

int main() {
    vector<CuentaBancaria> cuentas;
    int cantidadCuentas;
    int numeroCuenta;
    string nombreTitular;
    float saldo, cantidad;
    cout << "Ingrese la cantidad de cuentas bancarias: ";
    cin >> cantidadCuentas;
    for (int i = 0; i < cantidadCuentas; i++) {
        cout << "Ingrese el número de cuenta: ";
        cin >> numeroCuenta;
        cout << "Ingrese el nombre del titular: ";
        cin.ignore();
        getline(cin, nombreTitular);
        cout << "Ingrese el saldo inicial: ";
        cin >> saldo;
        CuentaBancaria cuenta(numeroCuenta, nombreTitular, saldo);
        cuentas.push_back(cuenta);
    }
    cout << "\nDatos de todas las cuentas bancarias:" << endl;
    for (int i = 0; i < cuentas.size(); i++) {
        cuentas[i].mostrarDatos();
    }
    int opcion, cuentaSeleccionada;
    do {
        cout << "\nSeleccione una cuenta por su índice (1 a " << cuentas.size() << ") o 0 para salir: ";
        cin >> cuentaSeleccionada;
        if (cuentaSeleccionada > 0 && cuentaSeleccionada <= cuentas.size()) {
            cout << "\n1. Depósito\n2. Retiro\n3. Mostrar datos\n4. Salir\nSeleccione una opción: ";
            cin >> opcion;
            switch (opcion) {
            case 1:
                cout << "Ingrese la cantidad a depositar: ";
                cin >> cantidad;
                cuentas[cuentaSeleccionada - 1].depositar(cantidad);
                break;
            case 2:
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cantidad;
                cuentas[cuentaSeleccionada - 1].retirar(cantidad);
                break;
            case 3:
                cuentas[cuentaSeleccionada - 1].mostrarDatos();
                break;
            case 4:
                break;
            default:
                cout << "Opción no válida." << endl;
            }
        }
    } while (cuentaSeleccionada != 0);
    return 0;
}
