#ifndef PASSARELLA_ELEM_COMPRA_H
#define PASSARELLA_ELEM_COMPRA_H
#include <iostream>
using namespace std;

class PassarellaElemCompra{
    private:
        string nom;
        string descripcio;
        float preu;
        string tipus;
        
    public:
        string obteNom();
        string obteDescripcio();
        float obtePreu();
        string obteTipus();
};

#endif