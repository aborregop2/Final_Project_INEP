#ifndef PASSARELLA_COMPRA_H
#define PASSARELLA_COMPRA_H

#include <iostream>
using namespace std;

class PassarellaCompra{
    private:
        string usuari;
        string element;
        string data;

    public:
        PassarellaCompra(string u, string el, string d);

        string obteUsuari();
        string obteElementCompra();
        string obteData();
        void insereix();
};


#endif