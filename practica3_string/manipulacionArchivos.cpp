#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Lee todo el contenido del archivo y lo devuelve como string
string leerArchivoCompleto(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string contenido = "", linea;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para lectura.\n";
        return "";
    }

    while (getline(archivo, linea)) {
        contenido += linea + '\n';
    }

    archivo.close();
    return contenido;
}

// Escribe (sobrescribe) texto en el archivo
void escribirArchivo(const string& nombreArchivo, const string& texto) {
    ofstream archivo(nombreArchivo); // ios::trunc es por defecto → borra el contenido previo
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para escritura.\n";
        return;
    }

    archivo << texto;
    archivo.close();
    cout << "Archivo escrito correctamente.\n";
}

// Agrega texto al final del archivo (sin borrar lo anterior)
void agregarAlArchivo(const string& nombreArchivo, const string& texto) {
    ofstream archivo(nombreArchivo, ios::app); // modo append
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para agregar.\n";
        return;
    }

    archivo << texto;
    archivo.close();
    cout << "Texto agregado correctamente.\n";
}
