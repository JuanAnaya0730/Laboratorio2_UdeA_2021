/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 14. Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
imprima la matriz rotada 90, 180 y 270 grados.

*/


#include <iostream>

using namespace std;

#define N 5

void imprimir_matriz(int array[5][5], int orden);
int len_numero(int numero);
void rotar90(int array[5][5], int *P_matriz);

int main()
{
    int matriz[5][5]={}, enteros=1;

    // Se imprime en panatalla la funcion del programa
    cout << "Este programa llena una matriz 5x5 con numeros del 1 al 25 y se imprime en pantalla "
            "la matriz rotada 90, 180 y 270 grados respectivamente.\n\n";

    // Se llena la matriz con numeros del 1 al 25
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matriz[i][j]=enteros;
            enteros++;
        }
    }

    // Se imprime la matriz original
    cout << "Matriz original: ";
    imprimir_matriz(matriz, N);

    // Se impime la matriz rotada 90°, 180° y 270°
    for(int i=90; i<=270; i+=90){
        rotar90(matriz, matriz[0]);
        cout << "Matriz rotada " << i << " grados: ";
        imprimir_matriz(matriz,5);
    }

    return 0;
}

void rotar90(int array[5][5], int *P_matriz){
    int arrayaux[5][5]={};

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            arrayaux[i][j]=array[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=N-1; j>=0; j--){
            *P_matriz=arrayaux[j][i];
            P_matriz++;
        }
    }
}

void imprimir_matriz(int array[5][5], int orden){
    int mayores[100]={}, guiones=(orden*3)+1, espacios;

    for(int i=0; i<orden; i++){
        for(int h=0; h<orden; h++){
            if(len_numero(array[h][i])>mayores[i]){
                mayores[i]=len_numero(array[h][i]);
            }
        }
    }

    for(int h=0; h<orden; h++){
        guiones+=mayores[h];
    }

    cout << "\n ";
    for(int h=0; h<guiones; h++){
        cout << "-";
    }
    for(int i=0; i<orden; i++){
        cout << endl;
        cout << " | ";
        for(int h=0; h<orden; h++){
            espacios=len_numero(array[i][h]);
            cout << array[i][h];
            while(espacios<mayores[h]){
                cout << " ";
                espacios++;
            }
            cout << " | ";
        }
        cout << "\n ";
        for(int h=0; h<guiones; h++){
            cout << "-";
        }
    }
    cout << endl << endl;
}

int len_numero(int numero){
    int contador=0;
    while(numero!=0){
        numero/=10;
        contador++;
    }
    return contador;
}
