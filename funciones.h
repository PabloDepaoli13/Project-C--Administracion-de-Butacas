#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "modelos.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <cctype>


    //Manejo de colores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int tiempoTranscurrido = 0;




int getTerminalWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}


void centerText(const string& text) {
    string continuarText = "Precione enter para continuar";
    int screenWidth = getTerminalWidth();
    int textWidth = text.length();
    int nextWidth = continuarText.length();

    if (screenWidth >= textWidth) {
        int padding = (screenWidth - textWidth) / 2;
        int padding2 = (screenWidth - nextWidth) / 2;

        string spaces(padding, ' ');
        string spaces2(screenWidth, '-');
        string spaces3(padding2, ' ');


        while (true) {
        system("cls");

        if (_kbhit()) {
            // Si se presiona una tecla
            if (_getch() == 13) { // 13 es el código ASCII de Enter
                break; // Sale del bucle si se presiona Enter
            }
        }
        if (tiempoTranscurrido % 2 == 0) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << spaces2 << endl;
            cout << spaces2 << endl << endl << endl << endl;
            cout << spaces << text << spaces << endl << endl;
            cout << spaces3 << continuarText << spaces << endl << endl;
            cout << spaces2 << endl;
            cout << spaces2<< endl << endl;

        } else {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << spaces2 << endl;
            cout << spaces2 << endl << endl << endl << endl;
            cout << spaces << text << spaces << endl << endl;
            cout << spaces3 << continuarText << spaces << endl << endl;
            cout << spaces2 << endl;
            cout << spaces2<< endl << endl;

        }

        this_thread::sleep_for(chrono::milliseconds(400));

        tiempoTranscurrido++;
    }

    } else {
    // La pantalla es más estrecha que el texto, imprime el texto tal como es.

        cout << "Error en el centrado del texto" << endl;
    }
}


void borrarPantalla(){
    system("cls");
}

void presioneParaContinuar(){
        cin.get();
        cout << endl << endl << "Precione enter para continuar..." << endl;
        cin.get();
}


void dibujarMenuPricipal(){
    int screenWidth = getTerminalWidth();
    string pregunta = "Que funcion desea realizar:";
    int padding = (screenWidth - pregunta.length()) / 2;

    string space(padding, ' ');

    string barrasText(screenWidth, '-');



    cout << barrasText << endl << endl;


    cout  << space << "Que funcion desea realizar:" << endl;
        cout << space <<"1. Consultar informacion de una butaca" << endl;
        cout << space <<"2. Reservar butaca" << endl;
        cout << space <<"3. Liberar butaca" << endl;
        cout << space <<"4. Actualizar butaca" << endl;
        cout << space <<"5. Mostrar butacas disponibles" << endl;
        cout << space <<"6. Salir" << endl;


    cout << endl << endl << barrasText << endl;
}

int devolverOpcionVerificada(int opcion){

    string space(5, ' ');
    int screenWidth = getTerminalWidth();
    string barra(screenWidth, '-');
    cout << endl << space << "Su opcion: "; cin >> opcion;
    cout << endl;
    cout << barra;

    return opcion;
}


#endif // FUNCIONES_H_INCLUDED
