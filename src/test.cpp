#include <iostream>
#include <python2.7/Python.h>
#include <chrono>
#include "Matrix.hpp"
#include "PlotQuiver.h"
#include "EdgeNode.cpp"
#include "Liebmann.cpp"
#include "InterfazUsuario.cpp"

using namespace anpi;


int main() {
    InterfazUsuario gui;
    gui.init();
    /*
    //basicamente entre mas alto el numero mas calor  hay
    //Bordes con rangos de temperaruta
    EdgeNode<double> up(100,100);
    EdgeNode<double> down(0,0);
    EdgeNode<double> r(50,50);
    EdgeNode<double> l(75,75);

    //tamano de la placa metalica
    Matrix<double> mat(512,512);
    Liebmann<double> lieb(1.5,up,down,l,r);
    Matrix<double> a;
    a= lieb.generateMat(mat);
    std::cout<<"Computing...."<<std::endl;
    //lieb.printMyMat(a);
    auto t_startOMP = std::chrono::high_resolution_clock::now();
    lieb.solveLiebmannOMP(a,1);
    auto t_endOMP = std::chrono::high_resolution_clock::now();
    double timeOMP = double(std::chrono::duration<double, std::milli>(t_endOMP - t_startOMP).count()) / 1000;
    //lieb.printMyMat(a);
    std::cout<<"time OMP "<<timeOMP<<std::endl;
    a = lieb.generateFinalMat(a);
    plotpy::PlotQuiver<double> plt;
    plt.initialize(a);
    plt.plotColor();//esta sirve para imprimir sin las  flechas
    plt.plotQuiver();//esta es para que imprima las flechas
    plt.showPlots();//muestra la grafica
    */
    return 0;

}
