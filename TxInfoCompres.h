#ifndef TX_INFO_COMPRES_H
#define TX_INFO_COMPRES_H

#include <iostream>
#include <pqxx/pqxx>
using namespace std;

class TxInfoCompres{
    private:
        string resultat[3];
        
    public:
        TxInfoCompres();

        void executar();
        string[] obteResultat();
};

#endif