/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dalva
 *
 * Created on October 30, 2020, 12:57 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

//prototypes
double** crearMatriz(int);
double** matrizAdjunta(double**, int);
double** matrizInversa(double**, int, int);
void liberarHeap(double**&, int);
void printMatriz(int**, int);
void printMatriz(double**, int);
double cofactor(double**, int, int, int);
double** submatriz(double**, int, int, int);
double determinante(double**, int);
int potencia(int, int);
double** crearMatrizAdj(int);
double** invertirMatriz(double**, int);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    char resp = 's';

    while (resp == 'S' || resp == 's') {

        cout << "Calcular la inversa de una matriz" << endl << endl;

        int size = 0;

        cout << "Ingrese el size de la matriz: ";
        cin >> size;
        cout << endl;

        while (size < 1) {
            cout << "Ingrese un valor valido: ";
            cin >> size;
            cout << endl;
        }

        double** matriz = NULL;

        matriz = crearMatriz(size);

        //impresion de la matriz original
        cout << "Esta es la matriz: " << endl;
        printMatriz(matriz, size);

        double** matrizAdj = NULL;
        
        //recepcion de la matriz adjunta 
        matrizAdj = matrizAdjunta(matriz, size);
        
        
        cout << "La matriz adjunta es: " << endl;
        printMatriz(matrizAdj, size);
        
        
        //declaracion y llamada a calculo de determinante
        double determinanteMatriz = 0;
        determinanteMatriz = determinante(matrizAdj, size);

        double** resultado = NULL;
        
        //llamado para recibir a la matriz inversa;
        resultado = matrizInversa(matrizAdj, size, determinanteMatriz);
        
        
        //impresion de "resultado"
        cout << "La matriz inversa es: " << endl;
        printMatriz(resultado, size);
        
        
        

        
        liberarHeap(matriz, size);
        liberarHeap(resultado, size);
        liberarHeap(matrizAdj, size);
        
        cout << "Desea calcular la inversa de otra matriz (s = si)" << endl;
        cin >> resp;

    }

    return 0;
}

//crea una matriz de N por N y le retorna

double** crearMatriz(int size) {

    srand(time(0));
    double** matriz = NULL;

    matriz = new double* [size];

    for (int i = 0; i < size; i++) {
        matriz[i] = new double [size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriz[i][j] = 1 + (rand() % 19 - 9);
        }
    }

    return matriz;
}

//crea la matriz para la matriz adjunta;

double** crearMatrizAdj(int size) {

    double** matriz = NULL;

    matriz = new double* [size];

    for (int i = 0; i < size; i++) {
        matriz[i] = new double[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

//provee la matriz adjunta de una matriz dada por random

double** matrizAdjunta(double** matriz, int size) {

    double** matrizAdj = NULL;
    matrizAdj = crearMatrizAdj(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrizAdj[i][j] = cofactor(matriz, i, j, size);
        }
    }
    
    matrizAdj = invertirMatriz(matrizAdj, size);
    
    return matrizAdj;
}

//invierte las filas y columnas de una matriz

double** invertirMatriz(double** matrizAdj, int size) {

    double** matrizInvertida = NULL;
    
    matrizInvertida = crearMatrizAdj(size);
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrizInvertida[i][j] = matrizAdj[j][i];
        }
    }

    return matrizInvertida;
}

//calcula la matriz inversa con el determinante
double** matrizInversa(double** invertida, int size, int determinante){
    
    double** inversa = NULL;
    inversa = crearMatrizAdj(size);
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            inversa[i][j] = 1/determinante * invertida[i][j];
        }
    }
    
    return invertida;
    
}

//calcula el cofactor de una matriz

double cofactor(double** matriz, int i, int j, int size) {

    double calculo = 0;

    double** subMatriz = NULL;

    subMatriz = submatriz(matriz, i, j, size);

    calculo += potencia(-1, i + j) + determinante(matriz, size);

    return calculo;

}

double determinante(double** matriz, int size) {

    int valor = 0;

    if (size == 2) {

        valor = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

        return valor;

    } else {

        for (int i = 0; i < size; i++) {
            valor += matriz[0][i] * cofactor(matriz, 0, i, size);
        }

        return valor;
    }


}

//calcula lal potencia de 1 numero

int potencia(int n, int base) {

    if (n == 0) {
        return 1;
    } else {
        return base * (potencia(n - 1, base));
    }


}

//devuelve la submatriz de una matriz

double** submatriz(double** matriz, int filaElim, int colElim, int size) {

    double** matrix = NULL;

    matrix = new double* [size - 1];

    for (int i = 0; i < size; i++) {
        matrix[i] = new double [size - 1];
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if (i != filaElim && j != colElim) {
                matrix[i][j] = matriz[i][j];
            }

        }
    }

    return matrix;

}


//imprime la matriz de un tam especificado

void printMatriz(int** matriz, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void printMatriz(double** matriz, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void liberarHeap(double** &matriz, int size) {

    if (matriz != NULL) {

        for (int i = 0; i < size; i++) {

            if (matriz[i] != NULL) {
                delete[] matriz[i];
            }
        }

    }

    if (matriz != NULL) {

        delete[] matriz;
        matriz = NULL;
    }
}
