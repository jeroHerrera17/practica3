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

        for(int j = 0; j < n; j++){
            if (texto[j+i] == '0'){
                num0 ++;
            }
            else{
                num1++;
            }
            bloque += texto[j+i+n];
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

//segundo metodo de codificacion
string segundoMetodo(const string& texto, int n){
    string textoEncriptado = "", bloque = "";
    for(int i = 0; i < int(sizeof(texto)); i += n){
        for(int j = 0; j < n; j++){
            bloque += texto[j+i];
        }
        textoEncriptado += bloque[n-1];
        for(int k = 0; k < n-1; k++){
            textoEncriptado += bloque[k];
        }
        bloque = "";
    }
    return textoEncriptado;
}

//funcion que revierte la codificacion aplicada por el primer metodo
string reversaPrimerMetodo(const string& texto, int n){
    string textoDesencriptado = "";
    int salto, num0, num1;
    for(int i = 0; i < n; i ++){
        if(texto[i] == '0'){
            textoDesencriptado += '1';
        }
        else{
            textoDesencriptado += '0';
        }
    }
    for(int i = 0; i < int(sizeof(texto))-n; i += n){
        string bloque = "";
        num0 = 0;
        num1 = 0;

        for(int j = 0; j < n; j++){
            if (textoDesencriptado[j+i] == '0'){
                num0 ++;
            }
            else{
                num1++;
            }
            bloque += texto[j+i+n];
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
                    textoDesencriptado += '1';
                }
                else{
                    textoDesencriptado += '0';
                }
            }
            else{
                textoDesencriptado += bloque[k];
            }
        }
    }
    return textoDesencriptado;
}


//funcion que revierte la codificacion aplicada por el segundo metodo
string reversaSegundoMetodo(const string& texto, int n){
    string textoDesencriptado = "", bloque = "";
    for(int i = 0; i < int(sizeof(texto)); i += n){
        for(int j = 0; j < n; j++){
            bloque += texto[j+i];
        }
        for(int k = 1; k < n; k++){
            textoDesencriptado += bloque[k];
        }
        textoDesencriptado += bloque[0];
        bloque = "";
    }
    return textoDesencriptado;
}

