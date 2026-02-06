#ifndef LISTAVEC_H
#define LISTAVEC_H
#include <cstddef>
#include <utility>
#include <cassert>
template <typename T> class Lista{
public:
    typedef size_t posicion;
    explicit Lista(size_t tamaMax=0);
    bool vacia() const;
    size_t tama() const;
    size_t tamaMax() const;
    void insertar(const T&x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    Lista(const Lista& L);
    Lista& operator=(const Lista& L);
    ~Lista();
private:
    T* elementos;
    size_t Lmax, n;
};

template <typename T>
inline Lista<T>::Lista(size_t tamaMax): elementos(new T[tamaMax]),Lmax(tamaMax),n(0)
{}

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
inline size_t Lista<T>::tamaMax() const
{
    return Lmax;
}

template <typename T>
void Lista<T>::insertar(const T&x, posicion p)
{
    assert(p>=primera() && p<=fin());
    assert(tama()<tamaMax());
    for(posicion q=fin();q>p;--q)
    {
        elementos[q]=elementos[q-1];
    }
    elementos[p]=x;
    ++n;
}

template <typename T>
void Lista<T>::eliminar(posicion p)
{
    assert(p>=primera()&&p<=fin());
    --n;
    for(posicion q=p;q<fin();++q)
    {
        elementos[q]=elementos[q+1];
    }
}

template <typename T>
inline const T& Lista<T>::elemento(posicion p) const
{
    assert(p>=primera() && p<=fin());
    return elementos[p];
}

template <typename T>
inline T& Lista<T>::elemento(posicion p)
{
    assert(p>=primera() && p<=fin());
    return elementos[p];
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    assert(p>=primera() && p<=fin());
    return p+1;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
    assert(p>=primera() && p<=fin());
    return p-1;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{
    return 0;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{
    return n;
}

template <typename T>
Lista<T>::Lista(const Lista& L):Lista(L.Lmax)
{
    if(!L.vacia())
    {
        n=L.n;
        for(posicion p=primera();p<fin();++p)
        {
            elementos[p]=L.elementos[p];
        }
    }
}

template <typename T>
inline Lista<T>& Lista<T>::operator=(const Lista& L)
{
    Lista L1(L);
    std::swap(elementos,L1.elementos);
    std::swap(Lmax,L1.Lmax);
    std::swap(n,L1.n);
    return *this;
}

template <typename T>
inline Lista<T>::~Lista()
{
    delete[] elementos;
}

#endif