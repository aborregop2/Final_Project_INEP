#ifndef CERCADORA_ELEM_COMPRA_H
#define CERCADORA_ELEM_COMPRA_H
#include "PassarellaElemCompra.h"
#include <iostream>
#include <vector>

using namespace std;

class CercadoraElemCompra {
public:
    CercadoraElemCompra();
    vector<PassarellaElemCompra> cercaElement(string elem);
    vector<PassarellaElemCompra> cercaTotsPaquet();

};
#endif