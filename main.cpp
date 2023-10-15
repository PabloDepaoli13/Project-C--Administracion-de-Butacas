#include "funciones.h"





using namespace std;

int main()
{
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, 800, 600, TRUE);
    //ESTABLECIENDO EL TAMAÑO DE LA CONSOLA

    string mensajeBienvenida = "******** BIENVENIDO A CINE MAX ********";

    centerText(mensajeBienvenida);
    int anchoPantalla = getTerminalWidth();


    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    Cine cineNew("Cine Max");




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
    cineNew.snacks.push_back(Snack(1,"Chisitos" ,120.0));
    cineNew.snacks.push_back(Snack(2,"Doritos" ,160.0));
    cineNew.snacks.push_back(Snack(3,"3D" ,140.0));
    cineNew.snacks.push_back(Snack(4,"Lays" ,140.0));


    while (true) {
        string space(5, ' ');
        dibujarMenuPricipal();


        bool valorSalida = true, valorSalida2 = true;
        int opcion, valorNuevo, eleccionSnack;
        valorNuevo = devolverOpcionVerificada(opcion);

        if(valorNuevo == 8){
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

                if(cineNew.reservarButaca(numeroButaca))
                {
                    for (const Butaca& butaca : cineNew.butacas) {
                        if(butaca.numero == numeroButaca){
                            cineNew.personas.push_back(Persona(butaca.numero,butaca.nombre,butaca.apellido,"",butaca.precio,0,0, false));
                            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                            cout << endl << space <<"Cliente registrado con exito, ya puede a pagar su butaca." << endl;
                            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                        }
                    }

                }
                presioneParaContinuar();
                break;
            case 3:
                cineNew.mostrarButacasDisponibles();

                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
                cout << endl <<  endl << space << "Numero de butaca a liberar: ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                cin >> numeroButaca;
                cineNew.liberarButaca(numeroButaca);
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
                cout << endl << endl << space << "Resultado: ";

                cineNew.mostrarButacasDisponibles();
                presioneParaContinuar();
                break;
            case 6:
                while(valorSalida){
                    borrarPantalla();
                    eleccionSnack = 0;
                    dibujarMenuSnack();
                    cout << endl <<  endl << space << "Tu opcion: ";cin >> eleccionSnack;
                    valorSalida = cineNew.comprarSnacks(eleccionSnack);

                }
                break;
                case 7:
                while(valorSalida2){
                    int eleccionButaca = 0;
                    string barraPantalla(anchoPantalla, '-');
                    cout << endl <<  endl << space << "Escriba su numero de butaca: "; cin >> eleccionButaca;
                    borrarPantalla();
                    cout << barraPantalla << endl << endl;
                    valorSalida2 = cineNew.pagarCuentas(eleccionButaca);
                    cout << endl << endl << barraPantalla << endl << endl;
                }
                break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << endl << endl << space <<"Opcion no valida. " << endl << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                cout <<  endl << space << "Presione Enter para volver a escribir una opcion." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
        }
    borrarPantalla();
    }


    return 0;
}
