#include <iostream>
#include <string>
#include "manipulacionArchivos.h"
#include "metodosEncriptacion.h"
#include "otrasFunciones.h"
using namespace std;

int main()
{
    string administradores, usuarios;
    int caso;
    administradores = leerArchivoCompleto("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/sudo.txt");
    usuarios = leerArchivoCompleto("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/usuarios.txt");

    /*string us = Binario("1046667210-jerito-150300\n1043240909-juasjuas-123003\n1031031313-nidea102-900000");
    string ad = Binario("jeronimo-1046667210\nsara-31052025\nlaura-2031029\njose julian-21029301");
    us = primerMetodo(us, 4);
    ad = segundoMetodo(ad, 4);
    cout << us << endl << endl << ad << endl;
    */

    administradores = reversaSegundoMetodo(administradores, 4); //SEGUNDO METODOOOO
    usuarios = reversaPrimerMetodo(usuarios, 4); //PRIMER METODOOOOOO

    cout <<"administradores: " << administradores << endl << "usuarios: " << usuarios << endl;

    administradores = binarioAtexto(administradores);
    usuarios = binarioAtexto(usuarios);

    cout <<"administradores: " << administradores << endl << "usuarios: " << usuarios << endl;

    cout << "como deseas ingresar??(ingrese el numero correspondiente)" << endl << "1.Usuario Administrador" << endl << "2.Usuario comun" << endl;
    cin >> caso;

    switch(caso)
    {
    case 1:
    {
        string clave = "", nuevoUsuario = "", parametro = "";
        int desReg;
        char continuar;
        bool claveCoincide = false, parametroValido;

        cout << "---acceder como usuario administrador---" << endl;

        do
        {
            cout << "ingrese su clave: ";
            cin >> clave;
            claveCoincide = laClaveCoincide(administradores, clave);
        }
        while(claveCoincide == false);
        cout << "bienvenido administrador <3" << endl << "deseas registrar un usuario?(seleccione el numero de la opcion, en caso de no seleccionar alguno se tomara como un no)" << endl << "1.si \n" << endl;
        cin >> desReg;
        switch(desReg)
        {
        case 1:
        {
            do{
                continuar = '0';
                cout << "perfecto!, primero, ";
                do{
                    parametroValido = true;
                    cout << "ingresa su cedula, solo numeros y 10 caracteres: ";
                    cin >> parametro;
                    for(char c: parametro){
                        if(c < '0' || c > '9'){
                            parametroValido = false;
                        }
                    }
                    if(parametro.size() != 10){
                        parametroValido = false;
                    }
                    cout << endl;
                    size_t posicion = usuarios.find(parametro);
                    if (posicion != string::npos){
                        parametroValido = false;
                        cout<< endl << "este usuario ya existe." << endl;
                    }
                }
                while(parametroValido == false);
                parametro += '-';
                usuarios += parametro;

                cout << "ahora, ingrese la clave del usuario: ";
                cin >> parametro;
                parametro += '-';
                usuarios += parametro;

                do{
                    parametroValido = true;
                    cout << "por ultimo, ingresa su saldo(solo numeros y mayores que 0): ";
                    cin >> parametro;
                    for(char c:parametro){
                        if(c < '0' || c > '9'){
                            parametroValido = false;
                        }
                    }
                }
                while(parametroValido == false);
                parametro += '\n';
                usuarios += parametro;

                cout << "ingreso exitoso, deseas agregar otro usuario?, presiona 1 para SI: ";
                cin >> continuar;
            }
            while(continuar == '1');
            break;
        case 2:
            cout << "esta no es una opcion valida, se tomara como un no, hasta luegoooo" << endl;
            break;
        }
        }
        break;
    }

    case 2:
    {
        int fi;
        string usuariosDic[100][3], cedula = "", clave = "";
        bool cedulaValida, claveValida;
        crearArregloUsuarios(usuarios, usuariosDic);
        //Validar que su cedula si se ecuentren entre los usuarios registrados
        do{
            cedulaValida = false;
            cout << "ingresa tu cedula de ciudadania: ";
            cin >> cedula;
            for(int i = 0; i < 100; i++){
                if(cedula == usuariosDic[i][0]){
                    cedulaValida = true;
                    fi = i;
                    break;
                }
            }
        }while(cedulaValida == false);
        cout << endl;
        //validar que la clave ingresada si coincida con la guardada con la cedula
        do{
            claveValida = false;
            cout << "ingresa tu clave usuario -" << cedula << ": ";
            cin >> clave;
            if(clave == usuariosDic[fi][1]){
                claveValida = true;
            }
        }while(claveValida == false);
        cout << endl << "----BIENVENIDO " << cedula << "----" << endl;

        //termina la validacion, empieza las funciones que desee hacer el usuario.
        int saldo = stoi(usuariosDic[fi][2]), funcionRea;
        if (saldo < 1000){
            cout << "Tu saldo es menor que 1000 (especificamente " << saldo << "), por lo que no puedes realizar ninguna funcion" << endl;
            cout << "ADIOOOOOS <3 <3 <3";
            break;
        }
        bool continuar;
        do{
            continuar = false;
            int cont;
            cout << "que deseas hacer?" << endl << "1.Consultar Saldo" << endl << "2.Retirar dinero, tienes que calcular la cantidad deseada" << endl << ": ";
            cin >> funcionRea;

            switch(funcionRea){
            case 1:
            {
                cout << "Tu saldo actual (menos el costo de consulta es: " << saldo-1000 << endl;
                saldo -= 1000;
                usuariosDic[fi][2] = saldo;
                break;
            }
            case 2:
            {
                cout << "Cuanto deseas retirar? (a este calor se le sumaran los 1000 de costo de uso)" << endl << "RECUERDA que tu saldo actual es " << saldo;
                int valorRetirar;
                bool retirarValido;
                do{
                    retirarValido = true;
                    cout << endl << ": ";
                    cin >> valorRetirar;
                    if(valorRetirar+1000 > saldo){
                        cout << "este valor es mayor que tu saldo actual, ingresa otro";
                        retirarValido =false;
                    }
                }while(retirarValido == false);
                saldo -= valorRetirar+1000;
                cout << "tu nuevo saldo es: " << saldo << endl;
                usuariosDic[fi][2] = saldo;
                break;
            }
            default:{
                cout << "esta no es una funcionalidad valida, Hasta luegooooo" << endl;
                break;
            }
                //FINALIZA LA EJECUCION.
            }
            cout << "deseas realizar otra funcion?, presiona 1 para realizar otra funcion: ";
            cin >> cont;
            if(cont == 1){
                continuar = true;
            }
        }while (continuar == true);
        usuarios = "";
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 3; j++){
                usuarios += usuariosDic[i][j];
                if (j != 2){
                    usuarios += '-';
                }
            }
            usuarios += '\n';
        }
        break;
    }
    }


    //para finalizar se vuelven a encriptar los textos y se sobreescriben sobre los archivos txt ya existentes
    administradores = Binario(administradores);
    usuarios = Binario(usuarios);

    administradores = segundoMetodo(administradores, 4);
    usuarios = primerMetodo(usuarios, 4);

    escribirArchivo("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/sudo.txt", administradores);
    escribirArchivo("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/usuarios.txt", usuarios);
    return 0;
}
