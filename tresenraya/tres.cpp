#include "tres.hpp"

int main()
{
    Tablero t;
    for(size_t i=0;i<3;i++)
        for(size_t j=0;j<3;j++)
            assert(t.obtener_ficha_casilla({ i,j })==Ficha::Vacio);
    assert(!t.comprobar_ganador(Ficha::X));
    assert(!t.comprobar_ganador(Ficha::O));
    std::cout<<"Tablero nuevo: "<<endl<<t<<"---------------";
    std::cout<<"Fichas vacias:\n"<<t.casillas_libres()<<"-------------------------";
    t.colocar_ficha(Ficha::X, { 0,0 });
    t.colocar_ficha(Ficha::X, { 1,1 });
    t.colocar_ficha(Ficha::X, { 2,2 });
    assert(t.comprobar_ganador(Ficha::X));
    assert(!t.comprobar_ganador(Ficha::O));
    std::cout<<"Gana X: "<<endl<<t<<"---------------"<<endl;
    std::cout<<endl;
    std::cout<<"Fichas vacias al ganar X:\n"<<t.casillas_libres();
    std::cout<<"-------------------------"<<endl;

    return 0;
}