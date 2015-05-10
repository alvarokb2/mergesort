/* 
 * File:   main.cpp
 * Author: alvarokb2
 *
 * Created on 24 de abril de 2015, 12:55
 */

#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mergesort.h"
#include "array.h"

using namespace std;

/*
 * 
 */
int compareInt(const int* __a, const int* __b){
    if(*__a<*__b) return -1;
    if(*__a>*__b) return 1;
    return 0;
}
int main(int argc, char** argv) {

    clock_t t_ini;
    clock_t t_fin;
    int elementos = 0;
    int opcion = 0;
    cout << "Set de datos:"<<endl<<"(1) 1000"<<endl;
    cout << "(2) 10000"<<endl;
    cout << "(3) 100000"<<endl;
    cout << "(4) 1000000"<<endl;
    cout << "(5) 10000000"<<endl;
    cout << "(6) 100000000"<<endl;
    cout << "ingrese opcion con el numero de elementos deseado: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            
            elementos = 1000;
            break;
        case 2:
            elementos = 10000;
            break;
        case 3:
            elementos = 100000;
            break;
        case 4:
            elementos = 1000000;
            break;
        case 5:
            elementos = 10000000;
            break;
        case 6:
            elementos = 100000000;
            break;
        default:
            opcion = 0;
            break;

    }
    

    Array<int> v(elementos);
    v.LlenarAleatorio();

    v.MostrarFL();
    cout << endl;
    
    t_ini = clock();
    mergeSort<int> ms(compareInt);
    ms.sort(&v[0], 0, elementos-1);
    t_fin = clock();
    
    double sec = (double)(t_fin - t_ini)/CLOCKS_PER_SEC;
    cout << "Tiempo del algoritmo: "<<sec * 1000<<endl<<endl;
    v.MostrarFL();
    return 0;
}

