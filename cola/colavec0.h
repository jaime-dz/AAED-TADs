#ifndef COLA_VEC_H
#define COLA_VEC_H
#include <cstddef>
#include <cassert>
template <typename T> class Cola{
public:
    explicit Cola(size_t tamaMax);
    bool vacia() const;
    size_t tama() const;
    size_t tamaMax() const;
    const T& frente() const;
    void pop();
    void push(const T&x);
private:
    T* elementos;
    size_t Lmax,n_eltos;
};
template <typename T>
inline Cola<T>::Cola(size_t tamaMax):elementos(new T[tamaMax]),Lmax(tamaMax),n_eltos(0)
{}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return n_eltos==0;
}

template <typename T>
inline size_t Cola<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline size_t Cola<T>::tamaMax() const
{
    return Lmax;
}

template <typename T>
inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return elementos[0];
}

template <typename T>
void Cola<T>::pop()
{
    assert(!vacia());
    for(size_t i=1;i<n_eltos;++i)
    {
        elementos[i-1]=elementos[i];
    }
    --n_eltos;
}

template <typename T>
inline void Cola<T>::push(const T&x)
{
    assert(n_eltos<Lmax);
    elementos[n_eltos]=x;
    ++n_eltos;
}

#endif