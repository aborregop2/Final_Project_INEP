#ifndef PASSARELLA_COMPRA_H
#define PASSARELLA_COMPRA_H

#include <iostream>
using namespace std;

class PassarellaCompra{
    private:
        string usuari;
        string element;
        string data;
        string preu_pagat;

    public:
        PassarellaCompra();
        PassarellaCompra(string u, string el, string d, string preupagat);

        string obteUsuari();
        string obteElementCompra();
        string obteData();
        void insereix();

        void modifyUsuari(string us);
        void modifyElement(string elem);
        void modifyData(string dat);
        bool existeix();
};


#endif