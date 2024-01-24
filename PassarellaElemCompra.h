#ifndef PASSARELLA_ELEM_COMPRA_H
#define PASSARELLA_ELEM_COMPRA_H
#include <iostream>
using namespace std;

class PassarellaElemCompra{
    private:
        string nom;
        string descripcio;
        string preu; //float preu
        string tipus;
        
    public:
        string obteNom();
        string obteDescripcio();
        string obtePreu(); //float obtepreu()
        string obteTipus();
        
        void modifyNom(string nomEc);
        void modifyDesc(string descEc);
        void modifyPreu(string preuEc);
        void modifyTipus(string tipusEc);
};

#endif