#ifndef TX_COMPRAR_PAQUET_H
#define TX_COMPRAR_PAQUET_H

#include "Videoconsola.h"
#include "PassarellaCompra.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct InfoVid{
    string nomVid;
    string descVid;
    string preuVid;
};

struct InfoPaq{
    string nomPaq;
    string descPaq;
    string preuPaq;
    string dataPaq;
    int estalvi;
    vector<InfoVid> res;
};

class TxComprarPaquet{

    private:
        string nom; 
        InfoPaq resultat; 

    public:
        TxComprarPaquet(string nomPaq);
        void executar();
        void executar2();
        InfoPaq obteResultat();
};


#endif