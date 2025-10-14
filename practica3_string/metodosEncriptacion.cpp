#include <iostream>
#include <string>
using namespace std;

// Convierte un número entero (0–255) en una cadena binaria de 8 bits
string aBinario(unsigned char c) {
    string binario = "";
    for (int i = 7; i >= 0; i--) {
        binario += ((c >> i) & 1) ? '1' : '0';
    }
    return binario;
}

// Muestra cada carácter de la cadena con su código ASCII y binario
string Binario(const string& texto) {
    string textoBinario = "";

    for (size_t i = 0; i < texto.size(); i++) {
        unsigned char c = texto[i];
        textoBinario += aBinario(c);
    }

    return textoBinario;
}

//primer metodo de codificacion
string primerMetodo(const string& texto, int n){
    string textoEncriptado = "";
    int salto, num0, num1;
    for(int i = 0; i < n; i ++){
        if(texto[i] == '0'){
            textoEncriptado += '1';
        }
        else{
            textoEncriptado += '0';
        }
    }
    for(int i = 0; i < int(sizeof(texto))-n; i += n){
        string bloque = "";
        num0 = 0;
        num1 = 0;
        if(i == 0){
            for(int j = 0; j < n; j++){
                if (texto[j+i] == '0'){
                    num0 ++;
                }
                else{
                    num1++;
                }
                bloque += texto[j+n];
            }
        }
        else{
            for(int j = 0; j < n; j++){
                if (texto[j+i] == '0'){
                    num0 ++;
                }
                else{
                    num1++;
                }
                bloque += texto[j+i+n];
            }
        }
        if(num0 == num1){
            salto = 1;
        }
        else if(num0 > num1){
            salto = 2;
        }
        else{
            salto = 3;
        }
        for(int k = 0; k < n; k ++){
            if((k+1)%salto == 0){
                if(bloque[k] == '0'){
                    textoEncriptado += '1';
                }
                else{
                    textoEncriptado += '0';
                }
            }
            else{
                textoEncriptado += bloque[k];
            }
        }
    }
    return textoEncriptado;
}

