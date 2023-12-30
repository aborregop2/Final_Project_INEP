#ifndef TX_CONSULTA_USUARI_H
#define TX_CONSULTA_USUARI_H

#include <iostream>
#include <pqxx/pqxx>
using namespace std;

class TxConsultaUsuari{
    private:
        PasarellaUsuari usuari;
        string resultat[4];
        
    public:
        TxConsultaUsuari();

        void executar();
        string[] obteResultat();
        PassarellaUsuari obteUsuari();
};

#endif