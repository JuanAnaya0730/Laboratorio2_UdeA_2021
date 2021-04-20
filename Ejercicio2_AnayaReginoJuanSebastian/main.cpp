/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 2. Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
y luego imprima cuantas veces se repite cada letra en el arreglo.
Ejemplo: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir: ABARSECAAB
A: 4
B: 2
C: 1
Y así sucesivamente.

Analisis de Variables.
abecedario: Arreglo que almacena el abecedario en mayusculas.
arraygenerado: Arreglo que almacenara un arreglo generado aleatoriamente.
nrandycontador: Variable que en un principio almacenara numeros aleatorios y luego pasara a ser un contador
                del numero de veces que se repita una letra en el arreglo 'arraygenerado'.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    char abecedario[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char arraygenerado[200];
    int nrandycontador;

    srand(time(NULL));

    /* Se imprime en pantalla la funcion del programa */
    cout << "Este programa genera un arreglo de letras aleatoreamente y lo imprime, ademas "
            "imprime cuantas veces se repite cada letra del arreglo.\n\n";

    // Aqui es generado un arreglo que contendrá 200 letras aleatorias entre A y Z.
    for(int i=0; i<200; i++){
        nrandycontador= rand()%26;
        arraygenerado[i]=abecedario[nrandycontador];
    }

    // Aqui es imprimido el arreglo generado anteriormente.
    cout << "Array: " << arraygenerado << "\n\n";

    // Aqui se buscara cuantas veces se repite cada letra del arreglo abecedario en el arreglo arraygenerado.
    for(int h=0; h<26; h++){
        nrandycontador=0;
        for(int i=0; i<200; i++){
            if(arraygenerado[i]==abecedario[h]){
                nrandycontador+=1;
            }
        }
        cout << abecedario[h] << ": " << nrandycontador << endl;
    }

    cout << endl;

    return 0;
}
