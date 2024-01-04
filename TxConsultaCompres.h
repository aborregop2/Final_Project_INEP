#ifndef TX_CONSULTA_COMPRES_H
#define TX_CONSULTA_COMPRES_H

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


class TxConsultaCompres{
    private:
        pair< vector<InfoPaq>,vector<InfoVid> > resultat;
        
    public:
        TxConsultaCompres();
        pair< vector<InfoPaq> ,vector<InfoVid> >  obteResultat();
        void executar();
};




#endif