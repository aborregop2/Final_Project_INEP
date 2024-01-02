#ifndef TX_ESBORRA_USUARI_H
#define TX_ESBORRA_USUARI_H

#include <iostream>
using namespace std;

class TxEsborraUsuari{
    private:
        string contrasenyaU;
        
    public:
        TxEsborraUsuari(string contraU);
        
        void executar();
};

#endif