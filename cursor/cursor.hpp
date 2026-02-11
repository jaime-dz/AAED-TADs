#ifndef CURSOR_HPP
#define CURSOR_HPP
#include "../pila/pilaenla.hpp"
#include <iostream>
#include <cassert>
class Cursor{
public:
    Cursor();
    void Avanzar();
    void Retrasar();
    void Final();
    void Principio();
    void Suprimir();
    void Borrar();
    void Insertar(const char& x);
    void Sobreescribir(const char& x);
    ~Cursor();
private:
    Pila<char> D;
    Pila<char> I;
};

inline void Cursor::Avanzar()
{
    assert(!D.vacia());
    I.push(D.tope());
    D.pop();
}

inline void Cursor::Retrasar()
{
    assert(!I.vacia());
    D.push(I.tope());
    I.pop();
}

void Cursor::Final()
{
    while(!D.vacia())
    {
        I.push(D.tope());
        D.pop();
    }
}

void Cursor::Principio()
{
    while(!I.vacia())
    {
        D.push(I.tope());
        I.pop();
    }
}

inline void Cursor::Suprimir()
{
    assert(!D.vacia());
    D.pop();
}

inline void Cursor::Borrar()
{
    assert(!I.vacia());
    I.pop();
}

inline void Cursor::Insertar(const char& x)
{
    I.push(x);
}

inline void Cursor::Sobreescribir(const char& x)
{
    assert(!I.vacia());
    I.pop();
    I.push(x);
}

Cursor::~Cursor()
{
    D.~Pila();
    I.~Pila();
}

#endif