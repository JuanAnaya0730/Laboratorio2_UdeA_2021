/*
                          INFORMATICA II
Grupo 04

Juan Sebastian Anaya Regino
CC: 1007545962

Problema 12. Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa
que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado
mágico.
Nota: un ejemplo de cuadrado mágico es el siguiente:
4 9 2
3 5 7
8 1 6

*/

#include <iostream>

using namespace std;

int buscar(int array[100][100], int numero, int orden);
bool sumasiguales(int array[100], int orden);
void imprimirmatriz(int array[100][100], int orden);
int len_numero(int numero);

int main()
{
    int n, a[100][100]={}, valores[500]={}, auxiliar=0, posiciones;
    bool seguir = true;

    // Se imprime en patalla la funcion del programa
    cout << "Este programa recibe numeros enteros que formaran una matriz cuadrada e imprimira "
            "en pantalla si la matriz ingresada corresponde a un cuadrado magico.\n\n";

    // Se le pide al usuario que ingrese el orden de la matriz
    cout << "Indique el orden de la matriz cuadrada: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << endl;
        for(int h=0; h<n; h++){
            cout << "Valor para la posicion fila(" << i+1 << ") columna(" << h+1 << "): ";
            cin >> a[i][h];
            if(buscar(a, a[i][h], n)>1){
                cout << "\nNo se pueden repetir valores." << endl;
                seguir = false;
                break;
            }
        }
        if(seguir==false){
            break;
        }
    }
    if(seguir==true){

        imprimirmatriz(a,n);

        posiciones=0;

        //filas
        for(int i=0; i<n; i++){
            for(int h=0; h<n; h++){
                auxiliar+=a[i][h];
            }
            valores[posiciones]=auxiliar;
            posiciones++;
            auxiliar=0;
        }

        //columnas
        for(int i=0; i<n; i++){
            for(int h=0; h<n; h++){
                auxiliar+=a[h][i];
            }
            valores[posiciones]=auxiliar;
            posiciones++;
            auxiliar=0;
        }

        //diagonal 1
        for(int i=0; i<n; i++){
            for(int h=0; h<n; h++){
                if(h==i){
                    auxiliar+=a[h][i];
                }
            }
        }
        valores[posiciones]=auxiliar;
        posiciones++;

        auxiliar=0;
        //diagonal 2
        for(int i=0; i<n; i++){
            for(int h=n-1; h>=0; h--){
                if((i+h)==n-1){
                    auxiliar+=a[i][h];
                }
            }
        }
        valores[posiciones]=auxiliar;
        posiciones++;

        if(sumasiguales(valores, n)==true){
            cout << "\n\nEs un cuadrado magico." << endl;
        }
        else{
            cout << "\n\nNo es un cuadrado magico." << endl;
        }

    }

    cout << endl;

    return 0;
}

int buscar(int array[100][100], int numero, int orden){
    int encontrado=0;
    for(int i=0; i<orden; i++){
        for(int h=0; h<orden; h++){
            if(array[i][h]==numero){
                encontrado+=1;
            }
        }
    }

    return encontrado;
}

bool sumasiguales(int array[100], int orden){
    bool iguales=true;
    for(int i=0; i<(orden*2)+2; i++){
        if(array[1]!=array[i]){
            iguales=false;
            return iguales;
        }
    }

    return iguales;
}

void imprimirmatriz(int array[100][100], int orden){
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
}

int len_numero(int numero){
    int contador=0;
    while(numero!=0){
        numero/=10;
        contador++;
    }

    return contador;
}
