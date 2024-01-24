#ifndef TX_CONSULTA_VIDEOJOCS_H
#define TX_CONSULTA_VIDEOJOCS_H

#include <iostream>
#include <vector>
using namespace std;

class TxConsultaVideojocs{
    private:
        vector<string> resultat;
        
    public:
        TxConsultaVideojocs();
        vector<string> obteResultat();
        void executar();
     
};




#endif