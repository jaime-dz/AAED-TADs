#ifndef LISTAE0_HPP
#define LISTAE0_HPP
#include <cstddef>
#include <cassert>
template <typename T> class Lista{
    struct nodo;
public:
    typedef nodo* posicion;
    Lista();
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    void insertar(const T& x, posicion& p);
    void eliminar(posicion& p);

private:
    struct nodo{
        T elto;
        nodo* sig;
        nodo(const T& e,nodo* p=nullptr):elto(e),sig(p){}
    };
    nodo* L;
    size_t n;
};

template <typename T>
inline Lista<T>::Lista():L(nullptr),n(0){}

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
    return L;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{
    return nullptr;
}

template <typename T>
void Lista<T>::insertar(const T& x,posicion& p)
{
    if(p==primera())
        p=L=new nodo(x,p);
    else{
        posicion q=anterior(p);
        p=q->sig=new nodo(x,p);
    }
    ++n;
}

template <typename T>
void Lista<T>::eliminar(posicion& p)
{
    assert(p!=fin());
    if(p==primera())
    {
        L=p->sig;
        delete p;
        p=primera();
    }
    else
    {
        posicion q=anterior(p);
        q->sig=p->sig;
        delete p;
        p=q->sig;
    }
    --n;
}

#endif