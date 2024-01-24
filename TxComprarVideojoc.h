#ifndef TX_COMPRAR_VIDEOJOC_H
#define TX_COMPRAR_VIDEOJOC_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct InfoRel{
    string nomVid;
    string descVid;
    string preu;
};

class TxComprarVideojoc {
    private:
        string nom; 
        string preu_pagat;
        vector<InfoRel> resultat; 

    public:
        TxComprarVideojoc(std::string nomV, string preu);
        void executar();
        vector<InfoRel> obteResultat();
};


#endif