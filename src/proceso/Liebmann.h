//
// Created by estape11 on 31/05/18.
//

#ifndef ANPI_LIEBMANN_H
#define ANPI_LIEBMANN_H


#include "EdgeNode.h"

template<typename T>
class Liebmann {
private:
    T lambda;
    bool end = false;
    EdgeNode<T> upEdge;
    EdgeNode<T> botEdge;
    EdgeNode<T> leftEdge;
    EdgeNode<T> rightEdge;
public:
    Liebmann(T, EdgeNode<T>, EdgeNode<T>, EdgeNode<T>, EdgeNode<T>);

    virtual ~Liebmann();

    /**
     * Genera la matriz agregando los bordes
     * @return matriz
     */
    anpi::Matrix <T> generateMat(anpi::Matrix <T>);

    /**
     * Imprime la matriz
     */
    void printMyMat(anpi::Matrix <T>);

    /**
     * Aproxima el valor de las temperaturas en cada uno de los nodos de una matriz
     * utilizando OpenMP para la optimizacion de los calculos paralelizacion)
     * @return matriz generada con los bordes incluidos
     */
    anpi::Matrix <T> solveLiebmannOMP(anpi::Matrix <T>, T);

    /**
     * Aproxima el valor de las temperaturas en cada uno de los nodos de una matriz
     * @return matriz generada con los bordes incluidos
     */
    anpi::Matrix <T> solveLiebmann(anpi::Matrix <T>, T);

    /**
     * @param matriz generada con los bordes incluidos
     * @param fila en la que se esta evaluando el nodo
     * @param cantidad total de columnas
     */
    T getNodeTem(anpi::Matrix <T> &, int, int);


    /**
     * Define el borde superior con una matriz dada
     */
    void setUpEdge(int, anpi::Matrix <T> &);

    /**
     * Define el borde inferior con una matriz dada
     */
    void setDownEdge(int, int, anpi::Matrix <T> &);

    /**
     * Define el borde derecho e izquierdo con una matriz dada
     */
    void setRLEdge(int, int, anpi::Matrix <T> &);

    /**
     * Obtiene el error entre un valor nuevo y el anterior a este
     * @return
     */
    T error(T, T);

    /**
     * Obtiene el error mayor entre cada uno de los hilos
     * @return
     */
    T getMax(std::vector <T>);

    /**
     * Remueve los bordes la matriz para ser impresa y devuelta con sus dimensiones originales
     * @return
     */
    anpi::Matrix <T> generateFinalMat(anpi::Matrix <T>);

};


#endif //ANPI_LIEBMANN_H
