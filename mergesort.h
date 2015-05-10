#ifndef MERGESORT_H
#define	MERGESORT_H

template <class T>
class mergeSort {
private:
    int (*_compareMethod)(const T*, const T*);
public:
    mergeSort();
    mergeSort(int (*)(const T*, const T*));
    void sort(T*, const int&, const int&);
};

template <class T>
mergeSort<T>::mergeSort() {
    this->_compareMethod = NULL;
};

template <class T>
mergeSort<T>::mergeSort(int (*__method)(const T*, const T*)) : _compareMethod(__method) {
};

template <class T>
void mergeSort<T>::sort(T* __list, const int& __start, const int& __end) {
    if (this->_compareMethod == NULL) return;
    if (__end - __start < 1) return;
    int mid = (__start + __end) / 2;
    this->sort(__list, __start, mid);
    this->sort(__list, mid + 1, __end);
    int size = (__end - __start + 1);
    T* aux = (T*) malloc(size * sizeof (T));
    int left = __start;
    int right = mid + 1;
    int pos = 0;
    do {
        if (left <= mid && right <= __end) {
            if (this->_compareMethod(&__list[left], &__list[right]) > 0) {
                *(aux + pos) = *(__list + right);
                right++;
            } else {
                *(aux + pos) = *(__list + left);
                left++;
            }
        } else {
            if (left > mid && right <= __end) {
                *(aux + pos) = *(__list + right);
                right++;
            } else if (left <= mid && right > __end) {
                *(aux + pos) = *(__list + left);
                left++;
            }
        }
        pos++;
    } while (pos < (__end - __start + 1));
    //memcmp(__list + __start, aux + pos, size * sizeof(T));
    pos = 0;
    for (int i = __start; i <= __end; i++) {
        *(__list + i) = *(aux + pos);
        pos++;
    }
    free(aux);
    aux = NULL;
};


#endif	/* MERGESORT_H */

