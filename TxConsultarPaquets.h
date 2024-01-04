#ifndef TX_CONSULTAR_PAQUETS_H
#define TX_CONSULTAR_PAQUETS_H

#include <iostream>
#include <vector>
#include "Structs.h"
using namespace std;



class TxConsultarPaquets {
    private:
        string nom;
        vector<InfoPaq> resultat;

    public:
        TxConsultarPaquets();
        void executar();
        vector<InfoPaq> obteResultat();
};
    


#endif