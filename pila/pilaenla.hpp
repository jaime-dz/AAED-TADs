#ifndef PILA_ENLA_H
#define PILA_ENLA_H
#include <cstddef>
#include <cassert>

template <typename T> class Pila{
public:
    Pila();
    bool vacia() const;
    size_t tama() const;
    const T& tope() const;
    void pop();
    void push(const T&x);
    Pila(const Pila& P);
    Pila& operator=(const Pila&P);
    ~Pila();
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo*p=nullptr):elto(e),sig(p){}
    };
    nodo* tope_;
    size_t n_eltos;
    void copiar(const Pila& P);
    
};

template <typename T>
inline Pila<T>::Pila():tope_(nullptr),n_eltos(0){}

template <typename T>
inline bool Pila<T>::vacia() const
{
    return (n_eltos==0);
}

template <typename T>
inline size_t Pila<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline const T& Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo*p =tope_;
    tope_=p->sig;
    delete p;
    --n_eltos;
}

template <typename T>
inline void Pila<T>::push(const T&x)
{
    tope_=new nodo(x,tope_);
    ++n_eltos;
}

template <typename T>
inline Pila<T>::Pila(const Pila&P):Pila()
{
    copiar(P);
}

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila& P)
{
    if(this!=&P)
    {
        this->~Pila();
        copiar(P);
    }
    return *this;
}

template <typename T>
Pila<T>::~Pila()
{
    nodo* p;
    while(tope_)
    {
        p=tope_->sig;
        delete tope_;
        tope_=p;
    }
    n_eltos=0;
}

template <typename T>
void Pila<T>::copiar(const Pila&P)
{
    if(!P.vacia())
    {
        tope_=new nodo(P.tope_->elto);
        n_eltos=1;
        nodo*p = tope_;
        nodo*q=P.tope_->sig;
        while(q)
        {
            p->sig=new nodo(q->elto);
            ++n_eltos;
            p=p->sig;
            q=q->sig;
        }
    }
}

#endif