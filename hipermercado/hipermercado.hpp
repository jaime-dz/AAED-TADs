#ifndef HIPERMERCADO_HPP
#define HIPERMERCADO_HPP
#include <iostream>
#include <cassert>
struct Caja
{
    size_t idCajero;
    double facturacion;
    bool abierta;
    Caja(size_t cajero=0,double caja_facturacion=0.0,bool caja_abierta=false):
        idCajero{cajero}, facturacion{caja_facturacion}, abierta{caja_abierta}{}        
};

class LineaCajas
{
    public:
        LineaCajas()=default;
        void abrirCaja(int numC,size_t id);
        double cerrarCaja(int numC);
        void cobrar(double total, int numC);
        void sustituirCajero(int numC,size_t id);
        double cambiarTurno();
        double cerrarCajas();
        ~LineaCajas()=default;
    private:
        static const int max_cajas=50;
        Caja cajas[max_cajas];
};

void LineaCajas::abrirCaja(int numC,size_t id)
{
    assert(numC<max_cajas && !cajas[numC].abierta);
    cajas[numC].abierta=true;
    cajas[numC].facturacion=0.0;
    cajas[numC].idCajero=id;
}

double LineaCajas::cerrarCaja(int numC)
{
    assert(numC<max_cajas && cajas[numC].abierta);
    cajas[numC].abierta=false;
    double Fact=cajas[numC].facturacion;
    cajas[numC].facturacion=0.0;
    cajas[numC].idCajero=0;
    return Fact;
}

void LineaCajas::cobrar(double total, int numC)
{
    assert(numC<max_cajas && cajas[numC].abierta);
    cajas[numC].facturacion+=total;
}

void LineaCajas::sustituirCajero(int numC,size_t id)
{
    assert(numC<max_cajas && cajas[numC].abierta);
    cajas[numC].idCajero=id;
}

double LineaCajas::cambiarTurno()
{
    double Fact=0.0;
    for(int numC=0,numC<max_cajas;numC++)
    {
        if(cajas[numC].abierta)
        {
            Fact+=cajas[numC].facturacion;
            cajas[numC].facturacion=0.0;
        }
    }
    return Fact;
}

double LineaCajas::cerrarCajas()
{
    double Fact=0.0;
    for(int numC=0;numC<max_cajas;numC++)
    {
        if(cajas[numC].abierta)
        {
            Fact+=cajas[numC].facturacion;
            cajas[numC].facturacion=0.0;
            cajas[numC].idCajero=0;
            cajas[numC].abierta=false;
        }
    }
    return Fact;
}

#endif