#ifndef GESTOR_HPP
#define GESTOR_HPP
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include "../cola/colaenla.h"
using namespace std;

typedef string trabajo;

struct Usuario
{
    Cola<trabajo> URGENTE;
    Cola<trabajo> NO_URGENTE;
};

class Gestor
{
    public:
        Gestor(int num_users);
        void verGestor();
        int verEmpleados();
        void insertarTrabajo(int u_id,const trabajo codigo_trabajo, bool Urgencia);
        void eliminarTrabajo();
        void cancelarTrabajo(int u_id);
    private:
        int empleados;
        std::vector<Usuario> Trabajadores;
        Cola<int> Impresora;
};

Gestor::Gestor(int num_users): Trabajadores(num_users), empleados(num_users){}

void Gestor::verGestor()
{
    Cola<int>copiaImpresora(Impresora);
    std::cout<<"La cola de turnos: ";
    while(!copiaImpresora.vacia())
    {
        std::cout<<copiaImpresora.frente()<<" ";
        copiaImpresora.pop();
    }
    std::cout<<std::endl;
}

int Gestor::verEmpleados()
{
    return empleados;
}

void Gestor::insertarTrabajo(int u_id, const trabajo codigo_trabajo, bool Urgencia)
{
    assert(u_id<empleados);
    if(Urgencia)
    {
        Trabajadores[u_id].URGENTE.push(codigo_trabajo);
    }
    else
    {
        Trabajadores[u_id].NO_URGENTE.push(codigo_trabajo);
    }
    if(!Impresora.vacia())
    {
        int og, aux;
        aux=og=Impresora.frente();
        if(og!=u_id)
        {
            Impresora.pop();
            Impresora.push(aux);
            aux=Impresora.frente();
            while (aux!=u_id && og!=aux)
            {
                Impresora.pop();
                Impresora.push(aux);
                aux=Impresora.frente();
            }
            if(aux==og)
                Impresora.push(u_id);
            else{
                while(aux!=og)
                {
                    Impresora.pop();
                    Impresora.push(aux);
                    aux=Impresora.frente();
                }
            }
        }
    }
    else
    {
        Impresora.push(u_id);
    }
}

void Gestor::eliminarTrabajo()
{
    assert(!Impresora.vacia());
    int usu=Impresora.frente();
    if(!Trabajadores[usu].URGENTE.vacia())
    {
        Trabajadores[usu].URGENTE.pop();
    }
    else if(!Trabajadores[usu].NO_URGENTE.vacia())
    {
        Trabajadores[usu].NO_URGENTE.pop();
    }
    if(!Impresora.vacia()) Impresora.pop();
    if(!Trabajadores[usu].URGENTE.vacia() || !Trabajadores[usu].NO_URGENTE.vacia())
    {
        Impresora.push(usu);
    }
}

void Gestor::cancelarTrabajo(int u_id)
{
    while(!Trabajadores[u_id].URGENTE.vacia())
        Trabajadores[u_id].URGENTE.pop();
    while(!Trabajadores[u_id].NO_URGENTE.vacia())
        Trabajadores[u_id].NO_URGENTE.pop();
    
        if(!Impresora.vacia())
        {
            int og,aux;
            aux=og=Impresora.frente();
            if(og!=u_id)
            {
                Impresora.pop();
                Impresora.push(aux);
                aux=Impresora.frente();
                while (aux!=u_id && og!=aux)
                {
                    Impresora.pop();
                    Impresora.push(aux);
                    aux=Impresora.frente();
                }
                if(aux!=og)
                {
                    Impresora.pop();
                    aux=Impresora.frente();
                    while (aux!=og)
                    {
                        Impresora.pop();
                        Impresora.push(aux);
                        aux=Impresora.frente();
                    }
                }
            }
            else Impresora.pop();
        }
}

#endif