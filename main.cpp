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
int** crearMatriz(int);
double** matrizAdjunta(int**, int);
int** matrizInversa(int**, double);
void liberarHeap(int**&, int);
void liberarHeap(double**&, int);
void printMatriz(int**, int);
double cofactor(int**, int, int, int);
int** submatriz(int**, int, int, int);
int determinante(int**, int);
int potencia(int, int);
double** crearMatriz(int);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char resp = 's';
    
    while(resp == 'S' || resp =='s'){
        
        cout << "Calcular la inversa de una matriz" <<endl << endl;
        
        int size = 0;
        
        cout << "Ingrese el size de la matriz: ";
        cin  >> size;
        cout << endl;
        
        while(size < 1){
            cout << "Ingrese un valor valido: ";
            cin >> size;
            cout << endl;
        }
        
        int** matriz = NULL;
        
        matriz = crearMatriz(size);
        
        printMatriz(matriz, size);
        
        
        
        
        liberarHeap(matriz, size);
        
        cout << "Desea calcular la inversa de otra matriz (s = si)" << endl;
        cin >> resp;
        
    }

    return 0;
}

//crea una matriz de N por N y le retorna
int** crearMatriz(int size){
    
    srand(time(0));
    int** matriz = NULL;
    
    matriz = new int* [size];
    
    for(int i = 0; i < size; i++){
        matriz[i] = new int[size];
    }
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matriz[i][j] = 1 + (rand() % 19-9);
        }
    }
    
    return matriz;
}

//crea la matriz para la matriz adjunta;
double** crearMatriz(int size){
    
    double matriz = NULL;
    
    matriz = new double* [size];
    
    for(int i = 0; i < size; i++){
        matriz[i] = new double[size];
    }
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matriz[i][j] = 0.0;
        }
    }
    
    return matriz;
}

//provee la matriz adjunta de una matriz dada por random
double** matrizAdjunta(int** matriz, int size){
    
    
    
    
    for(int i = 0; i  < size; i++){
        for(int j = 0; j < size; j++){
            
        }
    }
    
}


//calcula el cofactor de una matriz

double cofactor(int** matriz, int i, int j, int size){
    
    double calculo = 0;
    
    int** subMatriz = NULL;
    
    subMatriz = submatriz(matriz, i, j, size);
    
    calculo += potencia(-1, i+j) + determinante(matriz);
    
    return calculo;
    
}

int determinante(int** matriz, int size){
    
    int valor = 0;
    
    if(size == 2){
        
        valor = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
        
        return valor;
        
    }else{
       
        for(int i = 0; i < size; i++){
            valor += matriz[0][i] * cofactor(matriz, 0, i);
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
int** submatriz(int** matriz, int filaElim, int colElim, int size){
    
    int matrix = NULL;
    
    matrix = new int* [size-1];
    
    for(int i = 0; i < size; i++){
        matrix[i] = new int [size - 1];
    }
    
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            if(i != filaElim && j != colElim){
                matrix[i][j] = matriz[i][j];
            }
            
        }
    }
    
    return matrix;
    
}


//imprime la matriz de un tam especificado
void printMatriz(int** matriz, int size){
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void liberarHeap(int** &matriz, int size){
    
     if(matriz != NULL){
        
        for(int i = 0; i < size; i++){
            
            if(matriz[i] != NULL){
                delete[] matriz[i];
            }
        }
        
    }
    
    if(matriz != NULL){
        
        delete[] matriz;
        matriz = NULL;
    }
}

void liberarHeap(double** &matriz, int size){
    
     if(matriz != NULL){
        
        for(int i = 0; i < size; i++){
            
            if(matriz[i] != NULL){
                delete[] matriz[i];
            }
        }
        
    }
    
    if(matriz != NULL){
        
        delete[] matriz;
        matriz = NULL;
    }
}
