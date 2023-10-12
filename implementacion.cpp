#include "modelos.h"



using namespace std;


    string espacio(5, ' ');
    //int screenWidth = getTerminalWidth();


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
                    cout << endl <<espacio <<"\033[1;32mButaca reservada con exito.\033[0m" << endl;
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
            if (butaca.numero == num && butaca.reservada == true) {
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
    string barraC(11, '-');
    cout << endl << endl << espacio <<"Butacas disponibles: " << "\033[1;32m Color Verde \033[0m" << endl;
    cout << espacio <<"Butacas reservadas: " << "\033[1;31m Color Rojo \033[0m"<< endl << endl;

    cout << espacio << barraC << "\033[1;33m[----PANTALLA----]\033[0m" << barraC << endl << endl << endl;
    cout << espacio;
    for (const Butaca& butaca : butacas) {
        if (!butaca.reservada) {
            if(butaca.numero == 14 || butaca.numero == 18){
                cout << endl << espacio ;
            }
            cout << "\033[1;32m [- \033[0m" << butaca.numero <<"\033[1;32m -] \033[0m";
            }
        else {
            if(butaca.numero == 14 || butaca.numero == 18){
                cout << endl << espacio;
            }
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


    int Cine::mostrarButacasOcupadas(){
    int cantButacas = 1;
    cout << espacio <<"Butacas reservadas: "<< endl << endl;
    cout << espacio;
    for (const Butaca& butaca : butacas) {
        if (butaca.reservada) {
            if(cantButacas == 5 || cantButacas == 9){
                cout << endl << espacio;
            }
            cout << "\033[1;32m [- \033[0m" << butaca.numero <<"\033[1;32m -] \033[0m";
            cantButacas++;
            }

        }
        return cantButacas;
    }
