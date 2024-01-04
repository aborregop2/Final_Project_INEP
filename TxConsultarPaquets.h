#ifndef TX_CONSULTAR_PAQUETS_H
#define TX_CONSULTAR_PAQUETS_H

#include <iostream>
#include <vector>
using namespace std;


struct InfoVid{
    string nomVid;
    string descVid;
    string preuVid;
    string dataVid;
};

struct InfoPaq{
    string nomPaq;
    string descPaq;
    string preuPaq;
    string dataPaq;
    int estalvi;
    vector<InfoVid> res;
};

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