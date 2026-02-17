#include "gestorimp.hpp"
#include <iostream>
#include <string>
#include <cassert>

int main()
{
    Gestor g{10};
    std::cout<<g.verEmpleados()<<" empleados."<<std::endl;
    trabajo a="12534334";
    trabajo b="128834334";
    trabajo c="111534334";

    g.insertarTrabajo(2,a,false);
    g.insertarTrabajo(2,b,true);
    g.insertarTrabajo(3,c,false);

    g.verGestor();

    g.eliminarTrabajo();
    
    g.verGestor();

    return 0;
}