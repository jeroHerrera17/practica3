#ifndef OTRASFUNCIONES_H
#define OTRASFUNCIONES_H

#include <string>
using namespace std;
//realiza la validacion de si una clave se encuentra en un string de un archivo
bool laClaveCoincide(string archivo, string clave);

//funcion que convierte el string del archivo usuarios.txt en una arreglo para asi hacer un uso mas facil de este
void crearArregloUsuarios(string usuarios, string usuariosDic[100][3]);
#endif // OTRASFUNCIONES_H
