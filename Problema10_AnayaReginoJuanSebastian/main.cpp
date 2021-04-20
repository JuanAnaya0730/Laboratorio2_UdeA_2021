/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 10. Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo
usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su equivalente arábigo:
M: 1000
D: 500
C: 100
L: 50
X: 10
V: 5
I: 1

Los números romanos se forman usando estos caracteres en base a dos reglas:
 ->Si un carácter esta seguido por uno de igual o menor valor, su valor se suma al total.
 ->Si un carácter esta seguido por uno de mayor valor, su valor se resta del total.

Ejemplo: CC=200, CD=400, DC=600, DCLXVI=666, CLXXIV=174.
Nota: la salida del programa debe ser:
El número ingresado fue: DCLXVI
Que corresponde a: 666.

*/

#include <iostream>

using namespace std;

int main()
{
    int arabigos[7]={1000,500,100,50,10,5,1}, numero=0, b=0, s=0;
    char romanos[7]={'M','D','C','L','X','V','I'}, a[200]="", *ptr=NULL, *ptr2=NULL;

    // Se imprime en pantalla la funcion del programa
    cout << "Este programa convierte numeros romanos a su equivalente en decimal.\n"
            "NOTA: Ingrese el numero romano en letras mayusculas.\n\n";

    // Se le pide al usuario que ingrese el numero romano a convertir
    cout << "Ingrese el numero romano: ";
    cin >> a;

    // Este ciclo se encargara de convertor el numero ingresado a decimal
    for(int i=0; a[i]!='\0'; i+=2){
        for(int h=0; h<7; h++){
            if(a[i]==romanos[h]){
                ptr=&romanos[h];
                b=arabigos[h];
                break;
            }
        }

        for(int h=0; h<7; h++){
            if(a[i+1]==romanos[h]){
                ptr2=&romanos[h];
                s=arabigos[h];
                break;
            }
        }

        if(ptr<=ptr2)
            numero+=(b+s);
        else
            numero+=(s-b);
        b=0;
        s=0;
    }

    // Se imprime en pantalla el numero ingresado
    cout << "\nIngresado fue: " << a << endl;

    // Se imprime el numero romano convertido a decimal
    cout << "Que corresponde a: " << numero << endl;

    cout << endl;

    return 0;
}
