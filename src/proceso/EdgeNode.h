#ifndef ANPI_EDGENODE_H
#define ANPI_EDGENODE_H

/**
  *  Clase para los bordes de la placa metalica con un rango.
  */

template<typename T>
class EdgeNode {
private:
    T upper; // temperatura del borde superior
    T lower; // temperatura del borde inferior
public:
    EdgeNode(T, T);

    EdgeNode();

    virtual ~EdgeNode();

    /**
      * @param total int para saber cuantas filas  columnas tiene la matriz
      * @return dato tipo T que sabe de cuanto en cuanto varia el borde.
      */
    T getTempDif(int);

    T getLow() { return lower; }

    T getUp() { return upper; }
};


#endif //ANPI_EDGENODE_H
