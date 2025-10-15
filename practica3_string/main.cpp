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

    cout << "como deseas ingresar??(ingrese el numero correspondiente)" << endl << "1.Usuario Administrador" << endl << "2.Usuario comun" << endl;
    cin >> caso;

    switch(caso)
    {
    //usuario administrador
    case 1:
    {
        string clave = "", nuevoUsuario = "", parametro = "";
        int desReg, continuar = 0;
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
                continuar = 0;
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
                agregarAlArchivo("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/usuarios.txt", parametro);

                cout << "ahora, ingrese la clave del usuario: ";
                cin >> parametro;
                parametro += '-';
                agregarAlArchivo("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/usuarios.txt", parametro);

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
                agregarAlArchivo("C:/Users/JEROH/OneDrive/Desktop/practica3/practica3_string/datos/usuarios.txt", parametro);

                cout << "ingreso exitoso, deseas agregar otro usuario?, presiona 1 para SI: ";
                cin >> continuar;
            }
            while(continuar == 1);
            break;
        case 2:
            cout << "esta no es una opcion valida, se tomara como un no, hasta luegoooo" << endl;
            break;
        }
        }

    }

    //usuario comun
    case 2:{
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
        cout << "que deseas hacer?" << endl << "1.Consultar Saldo" << endl << "2.Retirar dinero, tienes que calcular la cantidad deseada" << endl << ": ";
        cin >> funcionRea;

        switch(funcionRea){
        case 1:
        {
            cout << "Tu saldo actual (menos el costo de consulta es: " << saldo-1000 << endl;
            saldo -= 1000;
            usuariosDic[fi][2] = saldo;
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
                    retirarValido =false;
                }
            }while(retirarValido == false);
            saldo -= valorRetirar;
            cout << "tu nuevo saldo es: " << saldo << endl;
            usuariosDic[fi][2] = saldo;
        }
        default:{

        }
        //FINALIZA LA EJECUCION.
        }


        break;
        }
    }
    return 0;
}
