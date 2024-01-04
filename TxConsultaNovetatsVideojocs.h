#ifndef TX_CONSULTA_NOVETATS_VIDEOJOCS_H
#define TX_CONSULTA_NOVETATS_VIDEOJOCS_H

#include <iostream>
#include <vector>
using namespace std;

class TxConsultaNovetatsVideojocs{
    private:
        string data;
        vector<string> resultat;

    public:
        TxConsultaNovetatsVideojocs(string d);
        void executar();
        vector<string> obteResultat();
};


#endif
