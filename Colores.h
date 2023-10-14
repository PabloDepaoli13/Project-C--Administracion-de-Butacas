#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

HANDLE hConsoleNew = GetStdHandle(STD_OUTPUT_HANDLE);

void pintarColor(string colorNew){
    if(colorNew == "original"){
        SetConsoleTextAttribute(hConsoleNew, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }else if(colorNew == "rojo"){
        SetConsoleTextAttribute(hConsoleNew, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }else if(colorNew == "verde"){
        SetConsoleTextAttribute(hConsoleNew, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }else if(colorNew == "azul"){
        SetConsoleTextAttribute(hConsoleNew, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }else if(colorNew == "amarillo"){
        SetConsoleTextAttribute(hConsoleNew, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    }else{
       cout << "Problema con el dato de color, no fue encontrado";
    }

}


#endif // COLORES_H_INCLUDED
