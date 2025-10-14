#include <iostream>
#include <string>
#include "manipulacionArchivos.h"
#include "metodosEncriptacion.h"
using namespace std;

int main()
{
    string cadenaOri = "AbCd", cadenaBin, cadenaEncrip;
    cadenaBin = Binario(cadenaOri);
    cadenaEncrip = primerMetodo(cadenaBin, 4);
    cout << cadenaBin << endl << cadenaEncrip << endl;

}
