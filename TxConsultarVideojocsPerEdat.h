#ifndef TX_CONSULTAR_VIDEOJOCS_PER_EDAT_H
#define TX_CONSULTAR_VIDEOJOCS_PER_EDAT_H

#include <iostream>
#include <vector>
using namespace std;

class TxConsultarVideojocsPerEdat{
    private:
        int edat;
        vector<string> resultat;
        
    public:
        TxConsultarVideojocsPerEdat(int edatU);
        void executar();
        vector<string> obteResultat();
};

#endif 