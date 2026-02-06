#ifndef PILA_VEC0_H
#define PILA_VEC0_H
#include <cstddef>
class Pila{
public:
    typedef int T;
    Pila();
    bool vacia() const;
    size_t tama() const;
    size_t tamaMax() const;
    const T& tope() const;
    void pop();
    void push(const T&x);
private:
    static const size_t Lmax=100;
    T elementos[Lmax];
    size_t n_eltos;
};
#endif