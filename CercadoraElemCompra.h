#ifndef CERCADORA_ELEM_COMPRA_H
#define CERCADORA_ELEM_COMPRA_H
#include <isotream>
#include "PasarellaElemCompra.h"
using namespace std;

class CercadoraElemCompra{
    public:
        CercadoraElemCompra();
        vector<PasarellaElemCompra> cercaElement(string elem);
}
#endif