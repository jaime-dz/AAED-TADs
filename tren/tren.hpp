#ifndef TREN_HPP
#define TREN_HPP
#include "../pila/pilaenla.hpp"
#include <iostream>
#include <cassert>
using namespace std;

class Tren{
public:
    typedef int vagon;
    Tren();
    void DesIzq();
    void DesDer();
    void insertar(const vagon& x);
    void eliminar();
    const vagon observar();
    bool vacio();
private:
    Pila<vagon> IZQ;
    Pila<vagon> DER;
};

Tren::Tren(){}
void Tren::DesIzq()
{
    assert(!vacio());
    if(!DER.vacia())
    {
        IZQ.push(DER.tope());
        DER.pop();
    }
    else
    {
        cout<<"No hay vagon que mover"<<endl;
    }
}

void Tren::DesDer()
{
    assert(!vacio());
    if(!IZQ.vacia())
    {
        DER.push(IZQ.tope());
        IZQ.pop();
    }
    if(IZQ.vacia())
    {
        IZQ.push(DER.tope());
        DER.pop();
    }
}

void Tren::eliminar()
{
    assert(!vacio());
    if(!IZQ.vacia())
    {
        IZQ.pop();
    }
    if(!DER.vacia())
    {
        IZQ.push(DER.tope());
        DER.pop();
    }
}

void Tren::insertar(const vagon& x)
{
    if(!IZQ.vacia())
    {
        DER.push(IZQ.tope());
        IZQ.pop();
    }
    IZQ.push(x);
}

const Tren::vagon Tren::observar()
{
    assert(!vacio());
    return IZQ.tope();
}

bool Tren::vacio() noexcept
{
    return IZQ.vacia() && DER.vacia();
}

#endif