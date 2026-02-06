#include <cassert>
#include "pilavec0.h"

Pila::Pila():n_eltos(0){}

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