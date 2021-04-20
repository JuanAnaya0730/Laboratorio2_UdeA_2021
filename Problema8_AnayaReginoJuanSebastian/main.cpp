/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 8. Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
generando una cadena que no tiene números y otra con los números que había en la cadena original.
Ejemplo: Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
Nota: la salida del programa debe ser:
Original: abc54rst.
Texto: abcrst. Numero: 54.

Analisis de Variables.
cadena: Cadena char que almacenara los caracteres ingresados al programa.
cNumeros: Cadena char que almacenara los caracteres numericos de 'cadena'.
cTexto: Cadena char que almacenara los caracteres no numericos de 'cadena'.
P_cadena: Este puntero ira almacenando las posiciones de memoria de cada uno
          de los caracteres de la cadena 'cadena'.
P_cNumeros: Este puntero ira almacenando las posiciones de memoria de cada uno
            de los caracteres de la cadena 'cNumeros'.
P_cTexto: Este puntero ira almacenando las posiciones de memoria de cada uno
          de los caracteres de la cadena 'cTexto'.

*/

#include <iostream>

using namespace std;

int main()
{
    char cadena[200]={}, cNumeros[200]={}, cTexto[200]={};
    char *P_cadena = NULL, *P_cNumeros = NULL, *P_cTexto = NULL;

    //  Se imprime en pantalla la funcion del programa.
    cout << "Este programa recibe una cadena de caracteres y separa los caracteres numericos de los no numericos.\n\n";

    //  Se apunta hacia las cadenas de caracteres cNumeros y cTexto respectivamente.
    P_cNumeros=&cNumeros[0];
    P_cTexto=&cTexto[0];

    //  Se le pide al usuario que ingrese una cadena de caracteres.
    cout << "Ecriba la cadena de caracteres: ";
    cin >> cadena;

    //  Este ciclo se encargará de separar los caracteres numericos de la cadena original.
    for(int i=0; cadena[i]!='\0'; i++){
        P_cadena=&cadena[i];
        if(*P_cadena>=48 && *P_cadena<=57){
            *P_cNumeros=*P_cadena;
            P_cNumeros++;
        }
        else{
            *P_cTexto=*P_cadena;
            P_cTexto++;
        }
    }

    //  Se imprime en pantalla la cadena original.
    cout << "\nOriginal: " << cadena << endl;

    //  Se imprime en pantala una cadena con todos los caracteres no numericos de la cadena original.
    cout << "Texto: " << cTexto << endl;

    //  Se imprime en pantalla una cadena con todos los caracteres numericos de la cadena original.
    cout << "Numero: " << cNumeros << endl;

    cout << endl;

    return 0;
}
