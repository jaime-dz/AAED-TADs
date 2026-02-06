#include <cassert>
#include "pilavec1.h"

Pila::Pila(size_t tamaMax):elementos(new T[tamaMax]),Lmax(tamaMax),n_eltos(0)
{}

bool Pila::vacia() const
{
    return (n_eltos==0);
}

size_t Pila::tama() const
{
    return n_eltos;
}

size_t Pila::tamaMax() const
{
    return Lmax;
}

const Pila::T& Pila::tope() const
{
    assert(!vacia());
    return elementos[n_eltos-1];
}

void Pila::pop()
{
    assert(!vacia());
    --n_eltos;
}

void Pila::push(const T& x)
{
    assert(n_eltos<Lmax);
    elementos[n_eltos]=x;
    ++n_eltos;
}

Pila::Pila(const Pila& P): elementos(new T[P.Lmax]), Lmax(P.Lmax),n_eltos(P.n_eltos)
{
    for(size_t i=0;i<n_eltos;++i)
    {
        elementos[i]=P.elementos[i];
    }
}

Pila& Pila::operator=(const Pila& P)
{
    if(this!=&P)
    {
        if(Lmax!=P.Lmax)
        {
            T* p = elementos;
            elementos=new T[P.Lmax];
            Lmax=P.Lmax;
            delete[] p;
        }
        n_eltos=P.n_eltos;
        for(size_t i=0;i<n_eltos;++i)
        {
            elementos[i]=P.elementos[i];
        }
    }
    return *this;
}

Pila::~Pila()
{
    delete[] elementos;
}