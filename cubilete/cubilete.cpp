#include "cubilete.hpp"
int main()
{
    Pila<tCubo> Torre;
    tCubo C1(1,false),C2(2,false),C3(3,true),C4(4,false),C5(5,false);
    Torre.push(C5);Torre.push(C4);Torre.push(C2);Torre.push(C1);Torre.push(C3);
    mostrarTorre(Torre);
    Pila<tCubo> Apilada=juego(Torre);
    mostrarTorre(Apilada);
    return 0;
}