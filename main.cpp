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

#include "lista.h"
#include "mergesort.h"
#include "array.h"

using namespace std;

/*
 * 
 */
int compareInt(const int* __a, const int* __b){
    if(__a<__b) return -1;
    if(__a>__b) return 1;
    return 0;
}

int main(int argc, char** argv) {
/*
    lista Lista;

    Lista.Add(3);
    Lista.Add(6);
    Lista.Add(2);
    Lista.Add(4);
    Lista.Add(2);
    Lista.Add(1);
    Lista.Add(3);

    Lista.Mostrar(ASCENDENTE);
    
    Lista.MergeSort(Lista.getPlista());
    */
    Array<int> v(5);
    v[0] = 6;
    v[1] = 1;
    v[2] = 3;
    v[3] = 5;
    v[4] = 2;
    for(int i =0;i<5;i++){
        cout << v[i];
    }
    cout << endl;
    mergeSort<int> ms(compareInt);
    ms.sort(&v[0],0,4);
    
    for(int i =0;i<5;i++){
        cout << v[i];
    }    
    return 0;
}

