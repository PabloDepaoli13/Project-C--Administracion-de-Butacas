#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <cctype>

using namespace std;

class Persona{

public:

    int numButaca;
    int cantProducto;
    double precioProducto, precioButaca;
    string nombreSnack, nombre, apellido;
    bool cuentaPaga;

    Persona(int n, string nom, string ape ,string nS, double pB, double pP, int cP, bool cuentP): numButaca(n), nombre(nom) , apellido(ape) , nombreSnack(nS), precioButaca(pB), precioProducto(pP), cantProducto(cP), cuentaPaga(cuentP){}
};


class Snack{

public:
    int numProducto;
    double precio;
    string nombre;


    Snack(int num,string n, double p) : numProducto(num), nombre(n), precio(p) {}

};

class Butaca {
public:

    int numero;
    bool reservada;
    double precio;
    string nombre, apellido;


    Butaca(int num, double p) : numero(num), nombre("") , apellido(""), reservada(false), precio(p) {}
};

class Cine {
public:
    vector<Snack> snacks;
    vector<Butaca> butacas;
    vector<Persona> personas;
    string nombre;

    Cine(string n) : nombre(n){}

    bool consultarButaca(int num);

    bool reservarButaca(int num);

    bool liberarButaca(int num);

    bool actualizarButaca(int num);

    void mostrarButacasDisponibles();

    int mostrarButacasOcupadas();

    bool comprarSnacks(int num);

    bool pagarCuentas(int numButa);

};




#endif // MODELOS_H_INCLUDED
