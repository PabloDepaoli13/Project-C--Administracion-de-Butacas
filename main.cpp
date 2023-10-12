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
                cineNew.mostrarButacasDisponibles();

                cout << endl <<  endl << space << "\033[1;33mNumero de butaca a consultar: \033[0m";
                cin >> numeroButaca;
                cout << endl;

                cineNew.consultarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 2:
                cineNew.mostrarButacasDisponibles();

                cout << endl << endl << space <<"\033[1;33mNumero de butaca a reservar: \033[0m";
                cin >> numeroButaca;
                cout << endl;

                cineNew.reservarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 3:
                cineNew.mostrarButacasDisponibles();

                cout << endl << endl << space <<"\033[1;33mNumero de butaca a liberar: \033[0m";
                cin >> numeroButaca;

                cineNew.liberarButaca(numeroButaca);
                presioneParaContinuar();
                break;
            case 4:
                int cantButacasOcup;
                cantButacasOcup = cineNew.mostrarButacasOcupadas();
                if(cantButacasOcup == 1){
                    cout << endl << endl << space <<"\033[1;31m No existen butacas reservadas para actualizar. \033[0m";
                }else{
                    cout << endl << endl << space <<"\033[1;33mNumero de butaca a actualizar: \033[0m";
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
