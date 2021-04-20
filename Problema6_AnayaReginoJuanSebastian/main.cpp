/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 6. Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por mayúsculas, los demás caracteres no deben ser alterados.
Ejemplo: se recibe Man-zana debe mostrar MAN-ZANA.
Nota: la salida del programa debe ser: Original: Man-zana. En mayuscula: MAN-ZANA.

Analisis de Variables.
cadena: Cadena char que almacenara la cadena ingresada. luego pasara a almacenar la misma
        cadena en mayusculas.
P_posicion: Este puntero ira almacenando las posiciones de memoria de cada una de las posiciones
            de la cadena ingresada.

*/

#include <iostream>

using namespace std;

int main()
{
    char cadena[200]="", *P_posicion;

    //  Se imprime en pantalla la funcion del programa.
    cout << "Este programa recibe una cadena de caracteres y cambia las letras minusculas por mayusculas.\n"
            "Nota: Los caracteres diferentes a letras minusculas no seran modificados.\n\n";

    //  Se le pide al usuario que ingrese una cadena de caracteres.
    cout << "Escriba la cadena de caracteres: ";
    cin >> cadena;

    //  Aqui se imprime la cadena original.
    cout << "\nOriginal: " << cadena <<  endl;

    //  Este ciclo se encarga de ir cambiando una a una las letras minusculas por mayusculas.
    for(int i=0; cadena[i]!='\0'; i++){
        P_posicion=&cadena[i];
        if(*P_posicion>=97 && *P_posicion<=122){
            *P_posicion-=32;
        }
    }

    //  Aqui se imprime la cadena ingresada convertida a mayuscula.
    cout << "En mayuscula: " << cadena << endl;

    cout << endl;

    return 0;
}
