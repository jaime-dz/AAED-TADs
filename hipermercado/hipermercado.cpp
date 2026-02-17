#include "hipermercado.hpp"
int main()
{
    LineaCajas l;
    l.abrirCaja(1,1);
    l.abrirCaja(2,2);

    l.cobrar(1.5,1);
    std::cout<<"Cambio de turno: "<<l.cambiarTurno()<<std::endl;

    l.cobrar(3.5,2);
    std::cout<<"Cerrar caja 2: "<<l.cerrarCaja(2)<<std::endl;

    l.sustituirCajero(1,3);
    l.abrirCaja(2,4);

    return 0
}