//
// Created by estape11 on 01/06/18.
//

#include "EdgeNode.h"

template<typename T>
EdgeNode<T>::EdgeNode(T pUp, T pLow) {
    // TODO Auto-generated constructor stub
    upper = pUp;
    lower = pLow;
}

template<typename T>
EdgeNode<T>::EdgeNode() {
    // TODO Auto-generated constructor stub
}

template<typename T>
EdgeNode<T>::~EdgeNode() {
    // TODO Auto-generated destructor stub
}

template<typename T>
T EdgeNode<T>::getTempDif(int total) {
    T dif = (upper - lower) / total;
    return dif;
}
