#ifndef TX_CONSULTAR_PAQUET_H
#define TX_CONSULTAR_PAQUET_H

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