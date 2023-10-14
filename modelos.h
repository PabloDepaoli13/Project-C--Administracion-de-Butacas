#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>


using namespace std;

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
    vector<Snack> snack;
    vector<Butaca> butacas;
    string nombre;

    Cine(string n) : nombre(n){}

    bool consultarButaca(int num);

    bool reservarButaca(int num);

    bool liberarButaca(int num);

    bool actualizarButaca(int num);

    void mostrarButacasDisponibles();

    int mostrarButacasOcupadas();

    void comprarSnacks(int num);

};




#endif // MODELOS_H_INCLUDED
