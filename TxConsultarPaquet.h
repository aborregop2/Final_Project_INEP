#ifndef TX_CONSULTAR_PAQUET_H
#define TX_CONSULTAR_PAQUET_H

#include <iostream>
#include <vector>
#include "Structs.h"
using namespace std;



class TxConsultarPaquet {
    private:
        string nom;
        InfoPaq resultat;

    public:
        TxConsultarPaquet(string nomP);
        void executar();
        InfoPaq obteResultat();
};
    


#endif