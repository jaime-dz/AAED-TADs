#ifndef CUBILETE_HPP
#define CUBILETE_HPP
#include "../pila/pilaenla.hpp"
#include <iostream>
#include <cassert>
using namespace std;

struct tCubo{
    int tama;
    bool abajo;
    tCubo(int t=0,bool a=true):tama(t),abajo(a){}
};

void mostrarTorre(Pila<tCubo>& inicio)
{
    Pila<tCubo> copia=inicio;
    Pila<tCubo> inv;
    cout<<"La torre: ";
    while(!copia.vacia())
    {
        inv.push(copia.tope());
        copia.pop();
    }
    while(!inv.vacia())
    {
        cout<<inv.tope().tama;
        if(inv.tope().abajo)
            cout<<"T";
        else
            cout<<"F";
        inv.pop();
    }
    cout<<endl;
}

Pila<tCubo> juego(Pila<tCubo>& inicio)
{
    Pila<tCubo> Final;
    tCubo cubilete;

    cout<<"Que comience el juego!"<<endl;
    while(!inicio.vacia())
    {
        cubilete=inicio.tope();
        inicio.pop();
        if(!cubilete.abajo)
            cubilete.abajo=true;
        while (!Final.vacia() && Final.tope().tama <cubilete.tama)
        {
            inicio.push(Final.tope());
            Final.pop();
        }
        Final.push(cubilete);
        
    }
    cout<<endl;
    cout<<"Lo hemos logrado"<<endl;
    return Final;
}

#endif