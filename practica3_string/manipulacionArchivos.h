#ifndef MANIPULACIONARCHIVOS_H
#define MANIPULACIONARCHIVOS_H

#include <string>
using namespace std;

// Lee todo el contenido del archivo y lo devuelve como string
string leerArchivoCompleto(const string& nombreArchivo) ;

// Escribe (sobrescribe) texto en el archivo
void escribirArchivo(const string& nombreArchivo, const string& texto) ;
/*
// Agrega texto al final del archivo (sin borrar lo anterior)
void agregarAlArchivo(const string& nombreArchivo, const string& texto) ;
*/
#endif // MANIPULACIONARCHIVOS_H
