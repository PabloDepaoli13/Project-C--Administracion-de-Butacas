#include "modelos.h"
#include "funciones.h"




using namespace std;

int main()
{
    string mensajeBienvenida = "******** Bienvenido a Cine Max ********";

    centerText(mensajeBienvenida);


    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Cine cineNew("Cine Max");



    // Agregar butacas al teatro
    cineNew.butacas.push_back(Butaca(1, 25.0));
    cineNew.butacas.push_back(Butaca(2, 30.0));
    cineNew.butacas.push_back(Butaca(3, 35.0));
    cineNew.butacas.push_back(Butaca(4, 45.0));
    cineNew.butacas.push_back(Butaca(5, 45.0));
    cineNew.butacas.push_back(Butaca(6, 45.0));
    cineNew.butacas.push_back(Butaca(8, 45.0));
    cineNew.butacas.push_back(Butaca(9, 45.0));
    cineNew.butacas.push_back(Butaca(10, 45.0));

    // Implementar un bucle para interactuar con el sistema
    while (true) {
        string space(5, ' ');
        dibujarMenuPricipal();



        int opcion, valorNuevo;
        valorNuevo = devolverOpcionVerificada(opcion);

        if(valorNuevo == 6){
            return false;
        }

        int numeroButaca;
        switch (valorNuevo) {
            case 1:
                cout << endl <<  endl << space << "Numero de butaca a consultar: ";
                cin >> numeroButaca;
                cout << endl;
                cineNew.consultarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 2:
                cout << endl << endl << space <<"Numero de butaca a reservar: ";
                cin >> numeroButaca;
                cout << endl;
                cineNew.reservarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 3:
                cout << endl << endl << space <<"Numero de butaca a liberar: ";
                cin >> numeroButaca;
                cineNew.liberarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 4:
                cout << endl << endl << space <<"Numero de butaca a actualizar: ";
                cin >> numeroButaca;
                cout << endl;
                cineNew.actualizarButaca(numeroButaca);
                presioneParaContinuar();
                break;

            case 5:
                cout << endl << endl << space << "Resultado: " << endl << endl << endl;
                cineNew.mostrarButacasDisponibles();
                presioneParaContinuar();
                break;
            default:
                cout <<  endl << endl << space <<"Opcion no valida." << endl;
                cout <<  endl << space <<"Presione Enter para volver a escribir una opcion." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();


                break;
        }
    borrarPantalla();
    }


    return 0;
}
