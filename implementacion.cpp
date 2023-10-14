#include "modelos.h"
#include "Colores.h"



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
                    pintarColor("verde");
                    cout << endl <<espacio <<"Butaca reservada con exito." << endl;
                    pintarColor("original");
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
                    pintarColor("verde");
                    cout << espacio <<"Butaca liberada con exito." << endl;
                    pintarColor("original");
                    return true;
                } else {
                    pintarColor("rojo");
                    cout << endl << espacio <<"La butaca no esta reservada." << endl;
                    pintarColor("original");
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
                pintarColor("verde");
                cout << espacio <<"Datos actualizados con exito." << endl;
                pintarColor("original");
                return true;
            }
        }
        pintarColor("rojo");
        cout << espacio << "Butaca no encontrada." << endl;
        pintarColor("original");
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
    pintarColor("verde");
    cout << endl << endl << espacio <<"Butacas disponibles: " << " Color Verde " << endl;
    pintarColor("rojo");
    cout << espacio <<"Butacas reservadas: " << " Color Rojo "<< endl << endl;
    pintarColor("original");

    cout << espacio << barraC;
    pintarColor("amarillo");
    cout << "[----PANTALLA----]";
    pintarColor("original");
    cout << barraC << endl << endl << endl;
    cout << espacio;
    for (const Butaca& butaca : butacas) {
        if (!butaca.reservada) {
            if(butaca.numero == 14 || butaca.numero == 18){
                cout << endl << espacio ;
            }
            pintarColor("verde");
            cout << " [- " << butaca.numero <<" -] ";
            pintarColor("original");
            }
        else {
            if(butaca.numero == 14 || butaca.numero == 18){
                cout << endl << espacio;
            }
            pintarColor("rojo");
            cout << " [- " << butaca.numero <<" -] ";
            pintarColor("original");
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
            pintarColor("rojo");
            cout << " [- " << butaca.numero <<" -] ";
            pintarColor("original");
            cantButacas++;
            }

        }
        return cantButacas;
    }

    void Cine::comprarSnacks(int num)
    {
        switch(num)
        {
        case 1:

            break;

        case 2:
            break;

        case 3:
            break;

        default:
            break;

        }

    }
