#include <string>

using namespace std;

//realiza la validacion de si una clave se encuentra en un string de un archivo
bool laClaveCoincide(string archivo, string clave){
    string usuarioAdmin = "", claveAdmin = "";
    bool esClave = false, claveCoincide = false;

    for(size_t i = 0; i < sizeof(archivo) ; i++){
        char c = archivo[i];
        if(c == '\n'){
            esClave = false;
            if(clave == claveAdmin){
                claveCoincide = true;
                break;
            }
            else{
                usuarioAdmin = "";
                claveAdmin = "";
            }
        }
        if((c != '-') && (esClave == false) && (c != '\n')){
            usuarioAdmin += c;
        }
        else if((c != '-') && (esClave == true) && (c != '\n')){
            claveAdmin += c;
        }
        else if(c != '\n'){
            esClave = true;
        }
    }
    return claveCoincide;
}

//funcion que convierte el string del archivo usuarios.txt en una arreglo para asi hacer un uso mas facil de este
void crearArregloUsuarios(string usuarios, string usuariosDic[100][3]){
    int fila = 0, colum = 0;
    string parametro = "";
    for(char c : usuarios){
        if(c == '-'){
            usuariosDic[fila][colum] = parametro;
            parametro = "";
            colum += 1;
        }
        else if(c == '\n'){
            usuariosDic[fila][colum] = parametro;
            parametro = "";
            colum = 0;
            fila += 1;
        }
        else{
            parametro += c;
        }
    }
}
