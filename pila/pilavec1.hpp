#ifndef PILA_VEC1_H
#define PILA_VEC1_H
#include <cstddef>
class Pila{
public:
    typedef int T;
    explicit Pila(size_t tamaMax);
    bool vacia() const;
    size_t tama() const;
    size_t tamaMax() const;
    const T& tope() const;
    void pop();
    void push(const T&x);
    Pila(const Pila& P);
    Pila& operator=(const Pila& P);
    ~Pila();
private:
    T* elementos;
    size_t Lmax, n_eltos;
};
#endif