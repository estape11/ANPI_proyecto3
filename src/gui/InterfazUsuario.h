//
// Created by estape11 on 03/06/18.
//

#ifndef ANPI_USERINTERFACE_H
#define ANPI_USERINTERFACE_H


class InterfazUsuario {
public:
    InterfazUsuario();
    void init();
private:
    void setUpMat(int,int);
    EdgeNode<double> getEdge(std::string);
    void calcMat(anpi::Matrix<double>,Liebmann<double>);
    void graphMat(anpi::Matrix<double>,Liebmann<double>);
};


#endif //ANPI_USERINTERFACE_H
