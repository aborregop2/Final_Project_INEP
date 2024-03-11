#ifndef TX_INFO_COMPRES_H
#define TX_INFO_COMPRES_H

#include <iostream>
using namespace std;

class TxInfoCompres{
    private:
        string* resultat;
        
    public:
        TxInfoCompres();

        void executar();
        string* obteResultat();
};

#endif