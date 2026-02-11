#ifndef SIMBOLO_HPP
#define SIMBOLO_HPP
#include "../lista/listaenla.hpp"
#include <iostream>
#include <cassert>
using namespace std;
enum Trazo{A,B,D,I};

class Simbolo{
public:
    Simbolo();
    void insertarTrazo(Trazo x);
    void eliminarTrazos(int n);
    Simbolo simetriaX();
    Simbolo simetriaY();
    Simbolo simetriaXY();
    void mostrarSimbolo();
private:
    Lista<Trazo> S;
    Simbolo(const Lista<Trazo>& listaTrazos);
};

Simbolo::Simbolo()
{}

Simbolo::Simbolo(const Lista<Trazo>& listaTrazos):S(listaTrazos)
{}

void Simbolo::insertarTrazo(Trazo x)
{
    S.insertar(x,S.primera());
}

void Simbolo::eliminarTrazos(int n)
{
    assert(S.primera()!=S.fin());
    while(S.primera()!=S.fin() && n>0)
    {
        S.eliminar(S.primera());
        n--;
    }
}

Simbolo Simbolo::simetriaX()
{
    Lista<Trazo> copia=S;
    Lista<Trazo>::posicion p=copia.primera();
    while(p!=copia.fin())
    {
        switch(copia.elemento(p))
        {
            case A:
                copia.elemento(p)=B;
                break;
            case B:
                copia.elemento(p)=A;
                break;
        }
        p=copia.siguiente(p);
    }
    return Simbolo(copia);
}

Simbolo Simbolo::simetriaY()
{
    Lista<Trazo> copia=S;
    Lista<Trazo>::posicion p=copia.primera();
    while(p!=copia.fin())
    {
        switch(copia.elemento(p))
        {
            case I:
                copia.elemento(p)=D;
                break;
            case D:
                copia.elemento(p)=I;
                break;
        }
        p=copia.siguiente(p);
    }
    return Simbolo(copia);
}

Simbolo Simbolo::simetriaXY()
{
    Lista<Trazo> copia=S;
    Lista<Trazo>::posicion p=copia.primera();
    while(p!=copia.fin())
    {
        switch(copia.elemento(p))
        {
            case A:
                copia.elemento(p)=B;
                break;
            case B:
                copia.elemento(p)=A;
                break;
            case I:
                copia.elemento(p)=D;
                break;
            case D:
                copia.elemento(p)=I;
                break;
        }
        p=copia.siguiente(p);
    }
    return Simbolo(copia);
}

void Simbolo::mostrarSimbolo()
{
    Lista<Trazo>::posicion p=S.primera();
    cout<<" El simbolo: ";
    while(p!=S.fin())
    {
        switch(S.elemento(p))
        {
            case A:
                cout<<"A ";
                break;
            case B:
                cout<<"B ";
                break;
            case I:
                cout<<"I ";
                break;
            case D:
                cout<<"D ";
                break;
        }
        p=S.siguiente(p);        
    }
    cout<<endl;
}

#endif