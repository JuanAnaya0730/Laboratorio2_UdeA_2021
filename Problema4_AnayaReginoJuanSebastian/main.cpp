/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 4. Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
y retorne dicho número. Escriba un programa de prueba.
Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.

Analisis de Variables.
cadena: Esta cadena contendra los valores numericos ingresados por el usuario.

*/

#include <iostream>

using namespace std;

long long int char_a_int(char nchar[20]);

int main()
{
    char cadena[20]="";

    /* Se imprime en pantalla la funcion del programa */
    cout << "Este programa convierte una cadena de caracteres numericos a un numero entero.\n\n";

    // Se le pide al usuario que ingrese los numeros a convertir
    cout << "Ingrese la cadena de numeros: ";
    cin >> cadena;

    // Se imprime la cadena original y transformada a entero
    cout << "\nchar ingresado: " << cadena << endl;
    cout << "char convertido a entero: " << char_a_int(cadena) << endl;

    cout << endl;

    return 0;
}

long long int char_a_int(char nchar[20]){
/*
    Esta funcion convertirá una cadena de caracteres
    a un numero entero.

    Analis de variables:
    nchar: Cadena que de caracteres numericos que sera convertida en entero.
    nint: Esta variable almacenara el contenido de 'nchar' convertido a entero.
*/
    long long int nint;

    nint=0;

    for(int i=0; nchar[i]!='\0'; i++){
        nint=nint*10+nchar[i]-48;
    }

    return nint;
}
