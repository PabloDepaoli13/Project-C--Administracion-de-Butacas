#include "modelos.h"


using namespace std;

string espacio(5, ' ');

    bool Cine::consultarButaca(int numero) {
        for (const Butaca& butaca : butacas) {
            if (butaca.numero == numero) {
                cout << espacio <<"---------------------" << endl;
                cout << espacio << "Numero de butaca: " << butaca.numero << endl;
                cout << espacio <<"Precio: " << butaca.precio << endl;

                if(butaca.reservada){
                    cout << espacio <<"Butaca reservada por: " << butaca.nombre << " " << butaca.apellido << endl;
                    cout << espacio <<"---------------------" << endl;
                }else{
                    cout << espacio <<"Estado: Disponible"<< endl;
                    cout << espacio <<"---------------------" << endl;
                }
                return true;
            }
        }
        cout << "Butaca no encontrada." << endl;
        return false;
    }

    bool Cine::reservarButaca(int numero) {
        for (Butaca& butaca : butacas) {
            if (butaca.numero == numero) {
                if (!butaca.reservada) {
                    cout << endl << espacio <<"Ingrese su nombre: "; cin >> butaca.nombre;
                    cout << espacio <<"Ingrese su apellido: "; cin >> butaca.apellido; cout << endl;
                    butaca.reservada = true;
                    cout << endl <<espacio <<"Butaca reservada con exito." << endl;
                    return true;
                } else {
                    cout << espacio <<"La butaca ya esta reservada." << endl;
                    return false;
                }
            }
        }
        cout << "Butaca no encontrada." << endl;
        return false;
    }

    bool Cine::liberarButaca(int numero) {
        for (Butaca& butaca : butacas) {
            if (butaca.numero == numero) {
                if (butaca.reservada) {
                    butaca.nombre = "";
                    butaca.apellido = "";
                    butaca.reservada = false;
                    cout << espacio <<"Butaca liberada con exito." << endl;
                    return true;
                } else {
                    cout << espacio <<"La butaca no esta reservada." << endl;
                    return false;
                }
            }
        }
        cout << espacio <<"Butaca no encontrada." << endl;
        return false;
    }

    bool Cine::actualizarButaca(int num) {
        for (Butaca& butaca : butacas) {
            if (butaca.numero == num) {
                cout << espacio <<"Datos Anteriores" << endl;
                cout << espacio <<"---------------------" << endl;
                cout << espacio <<"Nombre: " << butaca.nombre << endl;
                cout << espacio <<"Apellido: " << butaca.apellido << endl;
                cout << espacio <<"---------------------" << endl;
                cout << espacio <<"Datos Nuevos" << endl;
                cout << espacio <<"---------------------" << endl;
                cout << espacio <<"Nombre nuevo: "; cin >> butaca.nombre;
                cout << espacio <<"Apellido nuevo: "; cin >> butaca.apellido;
                cout << espacio <<"---------------------" << endl;
                cout << espacio <<"Datos actualizados con exito." << endl;
                return true;
            }
        }
        cout << espacio << "Butaca no encontrada." << endl;
        return false;
    }

    /*void Cine::mostrarButacasDisponibles(){
            cout << espacio <<"Butacas disponibles:" << endl;
            cout << espacio <<"---------------------" << endl;
    for (const Butaca& butaca : butacas) {
        if (!butaca.reservada) {
            cout << espacio <<"Numero de butaca: " << butaca.numero << endl;
            cout << espacio <<"Precio: " << butaca.precio << endl;
            cout << espacio <<"Estado: Disponible" << endl;
            cout << espacio <<"---------------------" << endl;
            }
        }
    }*/

    void Cine::mostrarButacasDisponibles(){
    for (const Butaca& butaca : butacas) {
        if (!butaca.reservada) {
            cout << "\033[1;32m [- \033[0m" << butaca.numero <<"\033[1;32m -] \033[0m";
            }
        else {
            cout << "\033[1;31m [- \033[0m" << butaca.numero <<"\033[1;31m -] \033[0m";
            }
        }

       /* cout << espacio <<"Butacas disponibles:" << endl;
            cout << espacio <<"---------------------" << endl;
    for (const Butaca& butaca : butacas) {
        if (!butaca.reservada) {
            cout << espacio <<"Numero de butaca: " << butaca.numero << endl;
            cout << espacio <<"Precio: " << butaca.precio << endl;
            cout << espacio <<"Estado: Disponible" << endl;
            cout << espacio <<"---------------------" << endl;
            }
        }*/
    }


