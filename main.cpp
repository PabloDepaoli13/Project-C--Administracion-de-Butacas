#include "funciones.h"





using namespace std;

int main()
{
    string mensajeBienvenida = "******** Bienvenido a Cine Max ********";

    centerText(mensajeBienvenida);


    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    Cine cineNew("Cine Max");



    // Agregar butacas al teatro
    cineNew.butacas.push_back(Butaca(10, 25.0));
    cineNew.butacas.push_back(Butaca(11, 30.0));
    cineNew.butacas.push_back(Butaca(12, 35.0));
    cineNew.butacas.push_back(Butaca(13, 45.0));
    cineNew.butacas.push_back(Butaca(14, 45.0));
    cineNew.butacas.push_back(Butaca(15, 80.0));
    cineNew.butacas.push_back(Butaca(16, 80.0));
    cineNew.butacas.push_back(Butaca(17, 45.0));
    cineNew.butacas.push_back(Butaca(18, 45.0));
    cineNew.butacas.push_back(Butaca(19, 45.0));
    cineNew.butacas.push_back(Butaca(20, 45.0));
    cineNew.butacas.push_back(Butaca(21, 45.0));
    cineNew.snack.push_back(Snack(1,"Chisitos" ,120.0));
    // Implementar un bucle para interactuar con el sistema
    while (true) {
        string space(5, ' ');
        dibujarMenuPricipal();



        int opcion, valorNuevo, eleccionSnack;
        valorNuevo = devolverOpcionVerificada(opcion);

        if(valorNuevo == 7){
            salidaPrograma();
            break;
        }

        int numeroButaca;
        switch (valorNuevo) {
            case 1:
                cineNew.mostrarButacasDisponibles();
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                cout << endl <<  endl << space << "Numero de butaca a consultar: ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                cin >> numeroButaca;
                cout << endl;

                cineNew.consultarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 2:
                cineNew.mostrarButacasDisponibles();
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                cout << endl <<  endl << space << "Numero de butaca a reservar: ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

                cin >> numeroButaca;
                cout << endl;

                cineNew.reservarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 3:
                cineNew.mostrarButacasDisponibles();

                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                cout << endl <<  endl << space << "Numero de butaca a liberar: ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                cin >> numeroButaca;

                cineNew.liberarButaca(numeroButaca);
                cout << endl <<  endl << space << "Numero de butaca a actualizar: ";
                presioneParaContinuar();
                break;
            case 4:
                int cantButacasOcup;
                cantButacasOcup = cineNew.mostrarButacasOcupadas();
                if(cantButacasOcup == 1){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                    cout << endl << endl << space <<"No existen butacas reservadas para actualizar. ";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                    cout << endl <<  endl << space << "Numero de butaca a actualizar: ";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                    cin >> numeroButaca;
                    cout << endl;

                    cineNew.actualizarButaca(numeroButaca);
                }

                presioneParaContinuar();
                break;

            case 5:
                cout << endl << endl << space << "Resultado: " << endl << endl << endl;

                cineNew.mostrarButacasDisponibles();
                presioneParaContinuar();
                break;
            case 6:
                borrarPantalla();
                eleccionSnack = 0;
                dibujarMenuSnack();
                cout << endl <<  endl << space << "Tu opcion: ";cin >> eleccionSnack;
                //Cine::comprarSnacks(eleccionSnack);
                break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << endl << endl << space <<"Opcion no valida. " << endl << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                cout <<  endl << "Presione Enter para volver a escribir una opcion." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();


                break;
        }
    borrarPantalla();
    }


    return 0;
}
