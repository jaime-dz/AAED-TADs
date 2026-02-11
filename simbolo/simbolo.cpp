#include "simbolo.hpp"
int main()
{
    Simbolo s1;
    cout<<"VACIO:"<<endl;
    s1.mostrarSimbolo();
    cout<<"INSERTAR:"<<endl;

    s1.insertarTrazo(A);
    s1.mostrarSimbolo();
    s1.insertarTrazo(A);s1.insertarTrazo(A);s1.insertarTrazo(I);s1.insertarTrazo(B);s1.insertarTrazo(B);s1.insertarTrazo(D);s1.insertarTrazo(I);s1.insertarTrazo(I);
    s1.insertarTrazo(A);s1.insertarTrazo(D);

    cout<<"SIMETRIA:"<<endl;
    s1.mostrarSimbolo();
    s1.simetriaX().mostrarSimbolo();
    s1.simetriaY().mostrarSimbolo();
    s1.simetriaXY().mostrarSimbolo();

    cout<<"ELIMINAR:"<<endl;
    s1.eliminarTrazos(5);
    s1.mostrarSimbolo();

    return 0;
}