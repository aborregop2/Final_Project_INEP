#ifndef CERCADORA_COMPRES_H
#define CERCADORA_COMPRES_H
#include "PassarellaCompra.h"
#include <iostream>
#include <vector>

using namespace std;

class CercadoraCompres{
    public:
        CercadoraCompres();
        vector<PassarellaCompra> cercaCompra(string sobrenomU);
};

#endif