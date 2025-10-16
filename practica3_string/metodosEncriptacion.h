#ifndef METODOSENCRIPTACION_H
#define METODOSENCRIPTACION_H

#include <string>
using namespace std;
//convierte un string de binarios a su mensaje (string) original
string binarioAtexto(const string &binario);

// Convierte un número entero (0–255) en una cadena binaria de 8 bits
string aBinario(unsigned char c) ;

// Muestra cada carácter de la cadena con su código ASCII y binario
string Binario(const string& texto) ;

//primer metodo de codificacion
string primerMetodo(const string& texto, int n);

//segundo metodo de codificacion
string segundoMetodo(const string& texto, int n);

//funcion que revierte la codificacion aplicada por el primer metodo
string reversaPrimerMetodo(const string& texto, int n);

//funcion que revierte la codificacion aplicada por el segundo metodo
string reversaSegundoMetodo(const string& texto, int n);
#endif // METODOSENCRIPTACION_H
