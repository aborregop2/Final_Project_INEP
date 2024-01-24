#ifndef TX_CONSULTA_USUARI_H
#define TX_CONSULTA_USUARI_H
#include "PassarellaUsuari.h"
#include <iostream>
#include <vector>
using namespace std;

class TxConsultaUsuari{
    private:
        PassarellaUsuari usuari;
        vector<string> resultat;
        
    public:
        TxConsultaUsuari();

        void executar();
        vector<string> obteResultat();
        PassarellaUsuari obteUsuari();
};

#endif