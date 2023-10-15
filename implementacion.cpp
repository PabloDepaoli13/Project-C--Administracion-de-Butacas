#include "modelos.h"
#include "Colores.h"
#include <limits>



using namespace std;

    int getTerminalWidth2() {
        CONSOLE_SCREEN_BUFFER_INFO csbis;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbis);
    return csbis.srWindow.Right - csbis.srWindow.Left + 1;
}

    string espacio(5, ' ');


    bool esCadenaSoloLetras(const string &cadena) {
    for (char caracter : cadena) {
        if (!isalpha(caracter)) {
            return false;
            }
        }
    return true;
    }

    bool Cine::consultarButaca(int numero) {
        for (const Butaca& butaca : butacas) {
            if (butaca.numero == numero) {
                cout << espacio <<"---------------------" << endl;
                cout << espacio << "Numero de butaca: " << butaca.numero << endl;
                cout << espacio <<"Precio: $" << butaca.precio << endl;

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
        pintarColor("rojo");
        cout << espacio <<"Butaca no encontrada." << endl;
        pintarColor("original");
        return false;
    }

    bool Cine::reservarButaca(int numero) {
        for (Butaca& butaca : butacas) {
            if (butaca.numero == numero) {
                if (!butaca.reservada) {
                    do {
                    cout << endl << espacio <<"Ingrese su nombre" << ": ";
                    cin >> butaca.nombre;
                    cout << endl << espacio << "Ingrese su apellido" << ": ";
                    cin >> butaca.apellido;cout << endl;

                    if (!esCadenaSoloLetras(butaca.nombre) || !esCadenaSoloLetras(butaca.apellido)) {
                        pintarColor("rojo");
                        cout << espacio << "Los nombres y apellidos solo pueden contener letras. Por favor, intentelo de nuevo." << endl;
                        pintarColor("original");
                    }else if(butaca.nombre.length() < 3 || butaca.apellido.length() < 3){
                        pintarColor("rojo");
                        cout << espacio << "Los nombres y apellidos deben contener como minimo de 3 letras. Por favor, intentelo de nuevo." << endl;
                        pintarColor("original");
                    }
                    } while (!esCadenaSoloLetras(butaca.nombre) || !esCadenaSoloLetras(butaca.apellido) || butaca.nombre.length() < 3 || butaca.apellido.length() < 3);
                    butaca.reservada = true;
                    pintarColor("verde");
                    cout << endl << espacio <<"Butaca " << numero << " reservada con exito." << endl;
                    pintarColor("original");
                    return true;
                } else {
                    cout << espacio <<"La butaca ya esta reservada." << endl;
                    return false;
                }
            }
        }
        cout << espacio <<"Butaca no encontrada." << endl;
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
                do {
                    cout << endl << espacio <<"Nombre nuevo" << ": ";
                    cin >> butaca.nombre;
                    cout << endl << espacio << "Apellido nuevo" << ": ";
                    cin >> butaca.apellido;cout << endl;

                    if (!esCadenaSoloLetras(butaca.nombre) || !esCadenaSoloLetras(butaca.apellido)) {
                        pintarColor("rojo");
                        cout << espacio << "Los nombres y apellidos solo pueden contener letras. Por favor, intentelo de nuevo." << endl;
                        pintarColor("original");
                    }else if(butaca.nombre.length() < 3 || butaca.apellido.length() < 3){
                        pintarColor("rojo");
                        cout << espacio << "Los nombres y apellidos deben contener como minimo de 3 letras. Por favor, intentelo de nuevo." << endl;
                        pintarColor("original");
                    }
                } while (!esCadenaSoloLetras(butaca.nombre) || !esCadenaSoloLetras(butaca.apellido) || butaca.nombre.length() < 3 || butaca.apellido.length() < 3);
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

    bool Cine::comprarSnacks(int num)
    {
        int encontrado = 0;
        int numProducto, cantidad = 0;
        bool bucle = true;
        int tamanoPantalla = getTerminalWidth2();
        string barrasText(tamanoPantalla, '-');

        int numButaca;

         if(num == 1){
                cout << endl << barrasText << endl;
                cout << endl << espacio << "Lista de productos:" << endl;
                cout << espacio <<"---------------------" << endl;

                for (const Snack& snack : snacks) {
                        cout << espacio <<"Snack: " << snack.nombre << endl;
                        cout << espacio <<"Precio: $" << snack.precio << endl;
                        cout << espacio <<"---------------------" << endl;

                }
                cout << barrasText << endl << endl;
                cin.get();
                cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                cin.get();
                return true;

         }else if(num == 2){

           while(bucle){
                pintarColor("amarillo");
                cout << endl << espacio << "Indique el numero de su butaca reservada: "; cin >> numButaca;
                pintarColor("original");
                for (const Butaca& butaca : butacas) {

                        if (numButaca == butaca.numero && butaca.reservada == true) {
                        encontrado = 1;
                        system("cls");
                        cout << barrasText << endl;
                        pintarColor("verde");
                        cout << endl << espacio << "Butaca localizada" << endl;
                        pintarColor("original");
                        cout << endl << espacio << "Lista de productos:" << endl;
                        cout << espacio <<"---------------------" << endl;

                        for (const Snack& snack : snacks) {
                            cout << espacio <<"Numero de producto: " << snack.numProducto << endl;
                            cout << espacio <<"Snack: " << snack.nombre << endl;
                            cout << espacio <<"Precio: " << snack.precio << endl;
                            cout << espacio <<"---------------------" << endl;

                        }
                        cout << barrasText << endl << endl << endl;
                        cout << espacio <<"Escriba el numero de producto que desea llevar: "; cin >> numProducto;
                        switch(numProducto)
                        {
                        case 1:
                            cout << endl << endl << espacio << "Ingrese la cantidad (CANTIDAD MAXIMA: 6): "; cin >> cantidad;
                            while(cantidad < 0 || cantidad > 6){
                                cout << endl << endl << espacio << "La cantidad de producto debe ser de 1 a 6." << endl;
                                cout << endl <<  espacio << "Ingrese la cantidad: "; cin >> cantidad;
                            }
                            pintarColor("verde");
                            cout << espacio << "Producto agregado con exito";
                            pintarColor("original");
                            cin.get();
                            cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                            cin.get();

                            break;
                        case 2:
                            cout << endl << endl << espacio << "Ingrese la cantidad (CANTIDAD MAXIMA: 6): "; cin >> cantidad;
                            while(cantidad < 0 || cantidad > 6){
                                cout << endl << endl << espacio << "La cantidad de producto debe ser de 1 a 6." << endl;
                                cout << endl <<  espacio << "Ingrese la cantidad: "; cin >> cantidad;
                            }
                            pintarColor("verde");
                            cout << espacio << "Producto agregado con exito";
                            pintarColor("original");
                            cin.get();
                            cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                            cin.get();
                            break;
                        case 3:
                            cout << endl << endl << espacio << "Ingrese la cantidad (CANTIDAD MAXIMA: 6): "; cin >> cantidad;
                            while(cantidad < 0 || cantidad > 6){
                                cout << endl << endl << espacio << "La cantidad de producto debe ser de 1 a 6." << endl;
                                cout << endl <<  espacio << "Ingrese la cantidad: "; cin >> cantidad;
                            }
                            pintarColor("verde");
                            cout << espacio << "Producto agregado con exito";
                            pintarColor("original");
                            cin.get();
                            cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                            cin.get();
                            break;
                        case 4:
                            cout << endl << endl << espacio << "Ingrese la cantidad (CANTIDAD MAXIMA: 6): "; cin >> cantidad;
                            while(cantidad < 0 || cantidad > 6){
                                cout << endl << endl << espacio << "La cantidad de producto debe ser de 1 a 6." << endl;
                                cout << endl <<  espacio << "Ingrese la cantidad: "; cin >> cantidad;
                            }

                            pintarColor("verde");
                            cout << espacio << "Producto agregado con exito";
                            pintarColor("original");
                            cin.get();
                            cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                            cin.get();
                            break;
                        default:
                            pintarColor("rojo");
                            cout << endl << espacio << "Opcion incorrecta. Por favor, escriba un numero que figure en los productos.";
                            pintarColor("original");
                            cin.get();
                            cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                            cin.get();
                            break;

                        }
                        for (Persona& persona : personas) {
                            if(persona.numButaca == numButaca){
                                for(Snack& snack : snacks){
                                    if(snack.numProducto == numProducto){
                                        persona.precioProducto = snack.precio;
                                        persona.nombreSnack = snack.nombre;
                                        persona.cantProducto = cantidad;

                                        }
                                    }

                                }
                            }
                            pintarColor("amarillo");
                            cout << endl << espacio <<"Se ha agregado correctamente el producto a tu pago final." << endl;
                            pintarColor("original");
                            cout << endl << endl << espacio << "Presione enter para volver a intentar..." << endl;
                            cin.get();
                    }
                }




                if(encontrado == 0){
                        pintarColor("rojo");
                        cout << endl << espacio <<"Opcion incorrecta, numero de butaca no encontrado" << endl;
                        pintarColor("original");
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl << endl << espacio << "Presione enter para continuar..." << endl;
                        cin.get();
                        bucle = false;
                }
                bucle = false;


            }
                return true;
            }else if(num == 3){
                return false;
            }else{
            pintarColor("rojo");
            cout << endl << espacio <<"Opcion incorrecta, por favor coloque un numero que figure en las opciones." << endl;
            pintarColor("original");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << endl << endl << espacio << "Presione enter para volver a intentar..." << endl;
            cin.get();

        }


}

    bool Cine::pagarCuentas(int numButa){
        int tamanoPantalla = getTerminalWidth2();
        int cantPersonas = 0;
        string barrasText(tamanoPantalla, '-');
        string barrasSeparador(40, '-');
        double sumaTotal = 0;
        pintarColor("amarillo");
        cout << espacio <<"IMPORTE TOTAL" << endl << endl;
        pintarColor("original");
        cout << barrasText << endl << endl;
        for(const Persona& persona : personas){
            if(numButa == persona.numButaca){
                    sumaTotal = persona.precioButaca + (persona.precioProducto * persona.cantProducto);
                    cout << espacio <<"Numero de butaca: " << persona.numButaca << endl;
                    cout << espacio <<"Nombre: " << persona.nombre << endl;
                    cout << espacio <<"Apellido: " << persona.apellido << endl;
                    cout << endl << endl << barrasSeparador << endl << endl;
                    cout << espacio <<"Producto comprado: " << persona.nombreSnack << endl;
                    cout << espacio <<"Cantidad de producto: " << persona.cantProducto << endl;
                    cout << endl << endl << barrasSeparador << endl << endl;
                    cout << espacio <<"Cobro de la butaca reservada: $" << persona.precioButaca << endl;
                    cout << espacio <<"Cobro por los productos: $" << persona.precioProducto * persona.cantProducto << endl;
                    cout << endl << endl << barrasSeparador << endl << endl;
                    cout << espacio << "Coste Total: $" << sumaTotal << endl;
                    cout << barrasText << endl << endl;
                    cantPersonas++;
                    cout << endl << endl << espacio << "Presione enter para volver al Menu principal..." << endl;
                    cin.get();
                    cin.get();

            }

        }
        if(cantPersonas == 0){
                pintarColor("rojo");
                cout << espacio <<"Opcion no valida, no se encontro la butaca reservada." << endl;
                pintarColor("original");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << endl << espacio << "Presione enter para volver al Menu principal..." << endl;
                cin.get();
        }
        return false;
    }
