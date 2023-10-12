#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

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
    vector<Butaca> butacas;
    string nombre;

    Cine(string n) : nombre(n){}

    bool consultarButaca(int num);

    bool reservarButaca(int num);

    bool liberarButaca(int num);

    bool actualizarButaca(int num);

    void mostrarButacasDisponibles();



};


#endif // MODELOS_H_INCLUDED
