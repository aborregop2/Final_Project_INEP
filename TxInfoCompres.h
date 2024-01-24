#ifndef TX_INFO_COMPRES_H
#define TX_INFO_COMPRES_H
#include <iostream>
#include <vector>
using namespace std;

class TxInfoCompres{
    private:
        vector<string> resultat;
        
    public:
        TxInfoCompres();

        void executar();
        vector<string> obteResultat();
};

#endif