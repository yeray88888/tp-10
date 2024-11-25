#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Libro {
public:
    string titulo;
    string autor;
    int anioPublicacion;
    Libro(string _titulo, string _autor, int _anioPublicacion) {
        titulo = _titulo;
        autor = _autor;
        anioPublicacion = _anioPublicacion;
    }
    void mostrarDatos() const {
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Año de publicación: " << anioPublicacion << endl;
        cout << "-----------------------" << endl;
    }
};

bool compararPorAnio(const Libro& l1, const Libro& l2) {
    return l1.anioPublicacion < l2.anioPublicacion; 
}

int main() {
    vector<Libro> libros;
    int cantidadLibros;
    string titulo, autor;
    int anioPublicacion;
    cout << "Ingrese la cantidad de libros: ";
    cin >> cantidadLibros;

    for (int i = 0; i < cantidadLibros; i++) {
        cout << "Ingrese el título del libro: ";
        cin.ignore(); 
        getline(cin, titulo);
        cout << "Ingrese el autor del libro: ";
        getline(cin, autor);
        cout << "Ingrese el año de publicación: ";
        cin >> anioPublicacion;
        Libro libro(titulo, autor, anioPublicacion);
        libros.push_back(libro);
    }
    sort(libros.begin(), libros.end(), compararPorAnio);
    cout << "\nLibros ordenados por año de publicación (de más antiguo a más reciente):" << endl;
    for (int i = 0; i < libros.size(); i++) {
        libros[i].mostrarDatos();
    }
    return 0;
}
