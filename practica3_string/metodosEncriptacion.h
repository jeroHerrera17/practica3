#ifndef METODOSENCRIPTACION_H
#define METODOSENCRIPTACION_H

#include <string>
using namespace std;

// Convierte un número entero (0–255) en una cadena binaria de 8 bits
string aBinario(unsigned char c) ;

// Muestra cada carácter de la cadena con su código ASCII y binario
string Binario(const string& texto) ;

//primer metodo de codificacion
string primerMetodo(const string& texto, int n);
#endif // METODOSENCRIPTACION_H
