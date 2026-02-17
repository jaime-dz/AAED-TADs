#ifndef TRES_HPP
#define TRES_HPP
#include "../lista/listaenla.hpp"
#include <iostream>
#include <cassert>
using namespace std;

struct casilla{
    size_t fila,columna;
    casilla(size_t f=0, size_t c=0):fila{f},columna{c}
    {}
};

enum class Ficha{Vacio,X,O};

class Tablero{
public:
    Tablero();
    void colocar_ficha(Ficha ficha, const casilla& casilla);
    Lista<casilla> casillas_libres() const;
    Ficha obtener_ficha_casilla(const casilla& casilla) const;
    bool comprobar_ganador(Ficha jugador) const;
    bool comprobar_empate() const;
    ~Tablero()=default;
private:
    Ficha tablero[3][3];
};

Tablero::Tablero()
{
    for (size_t i=0;i<3;i++)
    {
        for(size_t j=0;j<3;j++)
        {
            tablero[i][j]=Ficha::Vacio;
        }
    }
}

void Tablero::colocar_ficha(Ficha ficha, const casilla& casilla)
{
    assert(casilla.fila<3 && casilla.columna<3);
    assert(ficha!=Ficha::Vacio && tablero[casilla.fila][casilla.columna]==Ficha::Vacio);
    assert(comprobar_ganador(Ficha::X)==false && comprobar_ganador(Ficha::O)==false);
    tablero[casilla.fila][casilla.columna]=ficha;
}

Lista<casilla> Tablero::casillas_libres() const
{
    Lista<casilla> Libres;
    for(size_t i=0;i<3;i++)
        for(size_t j=0;j<3;j++)
            if(tablero[i][j]==Ficha::Vacio)
                Libres.insertar(casilla(i,j),Libres.fin());
    return Libres;
}

Ficha Tablero::obtener_ficha_casilla(const casilla& casilla) const
{
    assert(casilla.fila<3 && casilla.columna<3);
    return tablero[casilla.fila][casilla.columna];
}

bool Tablero::comprobar_empate() const
{
    size_t contador=0;
    for(size_t i=0;i<3;i++)
        for(size_t j=0;j<3;j++)
            if(tablero[i][j]!=Ficha::Vacio)
                contador++;
    assert(contador==9);
    return !comprobar_ganador(Ficha::X) && !comprobar_ganador(Ficha::O);
}

bool Tablero::comprobar_ganador(Ficha jugador) const
{
    assert(jugador!=Ficha::Vacio);
    bool ganador=false;
    size_t contador=0;
    for(size_t i=0;i<3;i++)
    {
        for(size_t j=0;j<3;j++)
        {
            if(tablero[i][j]==jugador) contador++;
        }
        if(contador==3) {ganador=true;}
        else    {contador=0;}
    }
    if(!ganador)
    {
        for(size_t i=0;i<3;i++)
        {
            for(size_t j=0;j<3;j++)
            {
                if(tablero[i][j]==jugador) contador++;
            }
            if(contador==3) {ganador=true;}
            else    {contador=0;}
        }
        if(!ganador)
        {
            for(size_t i=0;i<3;i++)
            {
                for(size_t j=0;j<3;j++)
                {
                    if(tablero[i][j]==jugador) contador++;
                }
                if(contador==3) {ganador=true;}
                else    {contador=0;}
            }
            if(!ganador)
            {
                for(size_t i=0,j=2;i<3;i++,j--)
                {
                    if(tablero[i][j]==jugador) contador++;
                }
            }
            if(contador==3) {ganador=true;}
        }
    }
    return ganador;
}

std::ostream& operator<<(std::ostream& os, const Lista<casilla>& l)
{
    auto pos=l.primera();
    while(pos!=l.fin())
    {
        os<<"\t{"<<l.elemento(pos).fila<<", "<<l.elemento(pos).columna<<" }\n";
        pos=l.siguiente(pos);
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Tablero& T)
{
    for(size_t i=0;i<3;i++)
    {
        for(size_t j=0;j<3;j++)
        {
            switch(T.obtener_ficha_casilla({ i,j }))
            {
                case Ficha::Vacio:
                    os<<"|   |";
                    break;
                case Ficha::X:
                    os<<"| X |";
                    break;
                case Ficha::O:
                    os<<"| O |";
                    break;
            }
        }
        os<<std::endl;
    }
    return os;
}


#endif