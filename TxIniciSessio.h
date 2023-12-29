#ifndef TX_INICI_SESSIO_H
#define TX_INICI_SESSIO_H

#include <iostream>
using namespace std;

class TxIniciSessio{
    private:
        string sobrenomU;
        string contrasenyaU;

    public:
        TxIniciSessio(string sU,string cU);
        void executar();
};

#endif