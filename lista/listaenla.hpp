#ifndef LISTAENLA_HPP
#define LISTAENLA_HPP
#include <cstddef>
#include <utility>
#include <cassert>
template <typename T> class Lista{
    struct nodo;
public:
    typedef nodo* posicion;
    Lista();
    bool vacia() const;
    size_t tama() const;
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    Lista(const Lista& Lis);
    Lista& operator=(const Lista& Lis);
    ~Lista();
private:
    struct nodo{
        T elto;
        nodo* sig;
        nodo(const T& e =T(), nodo* p=nullptr):elto(e),sig(p){}
    };
    nodo* L;
    size_t n;
};

template <typename T>
inline Lista<T>::Lista():L(new nodo),n(0)
{
    L->sig=L; //Circular
}

template <typename T>
inline bool Lista<T>::vacia() const
{
    return n==0;
}

template <typename T>
inline size_t Lista<T>::tama() const
{
    return n;
}

template <typename T>
inline void Lista<T>::insertar(const T& x, posicion p)
{
    p->sig=new nodo(x,p->sig);
    if(p==fin())
        L=p->sig;
    ++n;
}

template <typename T>
inline void Lista<T>::eliminar(posicion p)
{
    assert(p!=fin());
    posicion q=p->sig;
    if(q==fin())
        L=p;
    p->sig=q->sig;
    delete q;
    --n;
}

template <typename T>
inline const T& Lista<T>::elemento(posicion p) const
{
    assert(p!=fin());
    return p->sig->elto;
}

template <typename T>
inline T& Lista<T>::elemento(posicion p)
{
    assert(p!=fin());
    return p->sig->elto;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    assert(p!=fin());
    return p->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
    assert(p!=primera());
    posicion q=primera();
    while(q->sig!=p) q=q->sig;
    return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{
    return L->sig;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{
    return L;
}

template <typename T>
Lista<T>::Lista(const Lista& Lis):Lista()
{
    if(!Lis.vacia())
    {
        for(nodo* p=Lis.L->sig;p!=Lis.L;p=p->sig)
        {
            L=L->sig=new nodo(p->sig->elto;L->sig);
        }
        n=Lis.n;
    }
}

template <typename T>
inline Lista<T>& Lista<T>::operator=(const Lista& Lis)
{
    Lista L1(Lis);
    std::swap(L,L1.L);
    std::swap(n,L1-n);
    return *this;
}

template <typename T>
Lista<T>::~Lista()
{
    nodo* p;
    while(L!=L->sig)
    {
        p=L->sig;
        L->sig=p->sig;
        delete p;
    }
    delete L;
}

#endif