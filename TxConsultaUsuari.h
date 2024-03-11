#ifndef TX_CONSULTA_USUARI_H
#define TX_CONSULTA_USUARI_H
#include "PassarellaUsuari.h"
#include <iostream>
using namespace std;

class TxConsultaUsuari{
    private:
        PassarellaUsuari usuari;
        string* resultat;
        
    public:
        TxConsultaUsuari();

        void executar();
        string* obteResultat();
        PassarellaUsuari obteUsuari();
};

#endif