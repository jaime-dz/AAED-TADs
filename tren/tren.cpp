#include "tren.hpp"
int main()
{
    Tren t1;
    t1.insertar(2);t1.insertar(3);t1.insertar(4);t1.insertar(5);
    t1.DesDer();t1.DesDer();
    t1.observar();
    t1.DesIzq();
    t1.observar();
    t1.eliminar();
    t1.vacio();
    return 0;
}