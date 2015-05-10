/* 
 * File:   array.h
 * Author: alvarokb2
 *
 * Created on 9 de mayo de 2015, 16:50
 */

#ifndef ARRAY_H
#define	ARRAY_H

template <class T>
class Array {
public:
    Array(int nElem);
    ~Array();
    
    T& operator[](int index) {
        return pt[index];
    }

private:
    T *pt;
    int nElementos;
};


template <class T>
Array<T>::Array(int nElem) : nElementos(nElem){
    pt = new T[nElementos];
}

template <class T>
Array<T>::~Array(){
    delete [] pt;
}

#endif	/* ARRAY_H */