#ifndef PLOTPY_H
#define PLOTPY_H

#include <python2.7/Python.h>
#include <stdlib.h>
#include <string>
#include <vector>

namespace plotpy {

    /**
     * Esta clase permite la graficacion con escalas de colores la temperatura de una placa y el flujo.
     * @tparam T
     */
    template<typename T>
    class PlotQuiver {

    private:
        anpi::Matrix <T> _data; // guarda los datos para la graficacion

    public:
        PlotQuiver();

        ~PlotQuiver();

        /**
         * Inicicaliza con los datos en la matriz
         * @param data Matriz con los datos de la grafica.
         */
        void initialize(anpi::Matrix <T> data);

        /**
         * Muestra los datos
         */
        void showPlots();

        /**
           * @param data Matriz con los datos de la grafica.
           * @param varName string con el nombre de la variable en el programa de python
           * @return String con la instruccion completa para python
           */
        std::string getData(anpi::Matrix <T> data, std::string varName);

        /**
         * Muestra la grafica de color
         */
        void plotColor();

        /**
         * Despliega las flechas
         */
        void plotQuiver();
    };


    template<typename T>
    PlotQuiver<T>::PlotQuiver() {}


    template<typename T>
    PlotQuiver<T>::~PlotQuiver() {}


    template<typename T>
    void PlotQuiver<T>::initialize(anpi::Matrix <T> data) {
        Py_Initialize();
        PyRun_SimpleString("import numpy as np");
        PyRun_SimpleString("import pylab as plt");
        std::string auxFun = "def getAuxMats(Z):\n";
        auxFun.append("	k = 1\n");
        auxFun.append("	delX = 1\n");
        auxFun.append("	delY = 1\n");
        auxFun.append("	if((len(Z[0])+len(Z))//(2)>=10):\n");
        auxFun.append("		n=(len(Z[0])+len(Z))//(2*10)\n");
        auxFun.append("	else:\n");
        auxFun.append("		n=1\n");
        auxFun.append("	dx = np.linspace(0,(len(Z[0])-n),len(Z[0])//n)	\n");
        auxFun.append("	dy = np.linspace(0,(len(Z)-n),len(Z)//n)	\n");
        auxFun.append("	X,Y = np.meshgrid(dx,dy)\n");
        auxFun.append("	u = np.zeros((len(X),len(X[0])))\n");
        auxFun.append("	v = np.zeros((len(X),len(X[0])))\n");
        auxFun.append("	a,b=0,0\n");
        auxFun.append("	for x in range(len(X)):\n");
        auxFun.append("		for y in range(len(X[0])):\n");
        auxFun.append("			if(a!=0 and a!=len(Z)-1 and b!=0 and b!=len(Z[0])-1):\n");
        auxFun.append("				v[x][y]= k*(Z[a+1][b]-Z[a-1][b])/(2*delX)\n");
        auxFun.append("				u[x][y]= -k*(Z[a][b+1]-Z[a][b-1])/(2*delY)	\n");
        auxFun.append("			else:\n");
        auxFun.append("				v[x][y]= 0\n");
        auxFun.append("				u[x][y]= 0\n");
        auxFun.append("			b+=n\n");
        auxFun.append("		a+=n\n");
        auxFun.append("		b=0\n");
        auxFun.append("	return [X,Y,u,v]\n");
        PyRun_SimpleString(auxFun.c_str());
        _data = data;

        std::string tmp1 = getData(data, "z");
        PyRun_SimpleString(tmp1.c_str());
    }


    template<typename T>
    std::string PlotQuiver<T>::getData(anpi::Matrix <T> mat, std::string varName) {
        std::string tmp1 = varName + " = np.array([";
        for (int i = 0; i < mat.rows(); ++i) {
            tmp1.append("[");
            for (int j = 0; j < mat.cols(); ++j) {
                tmp1.append(std::to_string(mat[i][j]) + ",");
            }
            tmp1.append("],");
        }
        tmp1.append("])");
        return tmp1;
    }

    template<typename T>
    void PlotQuiver<T>::showPlots() {
        PyRun_SimpleString("plt.show()");
    }

    template<typename T>
    void PlotQuiver<T>::plotColor() {
        PyRun_SimpleString("plt.imshow(z)");
        PyRun_SimpleString("plt.colorbar()");
    }

    template<typename T>
    void PlotQuiver<T>::plotQuiver() {
        PyRun_SimpleString("auxVar = getAuxMats(z)");
        PyRun_SimpleString("plt.quiver(auxVar[0],auxVar[1],auxVar[2],auxVar[3],width=.005,linewidth=0.002, scale=150)");
    }

}

#endif // PLOTPY_H
