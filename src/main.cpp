#include <iostream>
#include "Matrix.hpp"
#include "PlotQuiver.h"
#include "EdgeNode.cpp"
#include "Liebmann.cpp"
#include "boost/program_options.hpp"

int main(int argc, char **argv) {
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
    double lambda = 1.5;
    double error = 1.0;
    try {
        /** Define and parse the program options
         */
        namespace po = boost::program_options;
        po::options_description desc("Options");
        desc.add_options()
                ("help", "Muestra la lista de opciones")
                (",t", po::value<double>(), "Indica temperatura en borde superior")
                (",b", po::value<double>(), "Indica temperatura en borde inferiror")
                (",l", po::value<double>(), "Indica temperatura en borde izquierdo")
                (",d", po::value<double>(), "Indica temperatura en borde derecho")
                (",i", po::value<std::string>(), "Indica cual o cuales bordes aislar")
                (",p", po::value<std::string>(), "Indica nombre del archivo con perfil termico")
                (",h", po::value<int>(), "Indica numero de pixeles horizontales en la solucion")
                (",v", po::value<int>(), "Indica numero de pixeles verticales en la solucion")
                (",q", "Desactiva toda forma de visualizacion")
                (",f", "Activa el calculo de flujo de calor")
                (",g", po::value<int>(), "Indica tamano de rejilla de visualizacion para el flujo de calor");

        po::variables_map vm;
        try {
            po::store(po::parse_command_line(argc, argv, desc),
                      vm); // can throw

            if (vm.count("help")) {
                std::cout << "<< ANPI Proyecto 3 - Propagacion de calor - EMD >>" << std::endl
                          << desc << std::endl;
                return SUCCESS;
            } else if (vm.count("-t") && vm.count("-b") && vm.count("-l") && vm.count("-d") && vm.count("-h") &&
                       vm.count("-v") && !vm.count("-f") && !vm.count("-q")) {

                double superior = vm["-t"].as<double>();
                double inferior = vm["-b"].as<double>();
                double derecho = vm["-d"].as<double>();
                double izquierdo = vm["-l"].as<double>();
                EdgeNode<double> up(superior, superior);
                EdgeNode<double> down(inferior, inferior);
                EdgeNode<double> r(derecho, derecho);
                EdgeNode<double> l(izquierdo, izquierdo);
                //std::cout<<"Superior: "<<superior<<std::endl;

                anpi::Matrix<double> mat((unsigned int) vm["-h"].as<int>(), (unsigned int) vm["-v"].as<int>());

                Liebmann<double> liebmann(lambda, up, down, l, r);

                anpi::Matrix<double> matrizTemp;
                matrizTemp = liebmann.generateMat(mat);

                //liebmann.printMyMat(matrizTemp);

                std::cout << "Procesando.." << std::endl;

                auto t_startOMP = std::chrono::high_resolution_clock::now();
                matrizTemp=liebmann.solveLiebmannOMP(matrizTemp, error); //
                auto t_endOMP = std::chrono::high_resolution_clock::now();
                double timeOMP((std::chrono::duration<double, std::milli>(t_endOMP - t_startOMP).count()) / 1000);
                std::cout << "Tiempo tomado: " << timeOMP << std::endl;

                matrizTemp = liebmann.generateFinalMat(matrizTemp);

                plotpy::PlotQuiver<double> plt;
                plt.initialize(matrizTemp);
                plt.plotColor();//esta sirve para imprimir sin las  flechas
                //plt.plotQuiver();//esta es para que imprima las flechas
                plt.showPlots();//muestra la grafica*/
            } else if (vm.count("-t") && vm.count("-b") && vm.count("-l") && vm.count("-d") && vm.count("-h") &&
                       vm.count("-v") && vm.count("-f") && !vm.count("-q")) {

                double superior = vm["-t"].as<double>();
                double inferior = vm["-b"].as<double>();
                double derecho = vm["-d"].as<double>();
                double izquierdo = vm["-l"].as<double>();
                EdgeNode<double> up(superior, superior);
                EdgeNode<double> down(inferior, inferior);
                EdgeNode<double> r(derecho, derecho);
                EdgeNode<double> l(izquierdo, izquierdo);
                //std::cout<<"Superior: "<<superior<<std::endl;

                anpi::Matrix<double> mat((unsigned int) vm["-h"].as<int>(), (unsigned int) vm["-v"].as<int>());

                Liebmann<double> liebmann(lambda, up, down, l, r);

                anpi::Matrix<double> matrizTemp;
                matrizTemp = liebmann.generateMat(mat);

                //liebmann.printMyMat(matrizTemp);

                std::cout << "Procesando.." << std::endl;

                auto t_startOMP = std::chrono::high_resolution_clock::now();
                matrizTemp=liebmann.solveLiebmannOMP(matrizTemp, error); //
                auto t_endOMP = std::chrono::high_resolution_clock::now();
                double timeOMP((std::chrono::duration<double, std::milli>(t_endOMP - t_startOMP).count()) / 1000);
                std::cout << "Tiempo tomado: " << timeOMP << std::endl;

                matrizTemp = liebmann.generateFinalMat(matrizTemp);

                plotpy::PlotQuiver<double> plt;
                plt.initialize(matrizTemp);
                plt.plotColor();//esta sirve para imprimir sin las  flechas
                plt.plotQuiver();//esta es para que imprima las flechas
                plt.showPlots();//muestra la grafica*/
            } else if (vm.count("-t") && vm.count("-b") && vm.count("-l") && vm.count("-d") && vm.count("-h") &&
                       vm.count("-v") && vm.count("-q")) {

                double superior = vm["-t"].as<double>();
                double inferior = vm["-b"].as<double>();
                double derecho = vm["-d"].as<double>();
                double izquierdo = vm["-l"].as<double>();
                EdgeNode<double> up(superior, superior);
                EdgeNode<double> down(inferior, inferior);
                EdgeNode<double> r(derecho, derecho);
                EdgeNode<double> l(izquierdo, izquierdo);
                //std::cout<<"Superior: "<<superior<<std::endl;

                anpi::Matrix<double> mat((unsigned int) vm["-h"].as<int>(), (unsigned int) vm["-v"].as<int>());

                Liebmann<double> liebmann(lambda, up, down, l, r);

                anpi::Matrix<double> matrizTemp;
                matrizTemp = liebmann.generateMat(mat);

                //liebmann.printMyMat(matrizTemp);

                std::cout << "Procesando.." << std::endl;

                auto t_startOMP = std::chrono::high_resolution_clock::now();
                matrizTemp=liebmann.solveLiebmannOMP(matrizTemp, error); //
                auto t_endOMP = std::chrono::high_resolution_clock::now();
                double timeOMP((std::chrono::duration<double, std::milli>(t_endOMP - t_startOMP).count()) / 1000);
                std::cout << "Tiempo tomado: " << timeOMP << std::endl;

                matrizTemp = liebmann.generateFinalMat(matrizTemp);

                return SUCCESS;
            }

            po::notify(vm); // throws on error, so do after help in case
            // there are any problems
        }
        catch (po::error &e) {
            std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return ERROR_IN_COMMAND_LINE;
        }

    }
    catch (std::exception &e) {
        std::cerr << "Unhandled Exception reached the top of main: "
                  << e.what() << ", application will now exit" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;

    }

    return SUCCESS;
}