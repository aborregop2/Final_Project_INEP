#ifndef TX_CONSULTA_VIDEOJOC_H
#define TX_CONSULTA_VIDEOJOC_H
#include <iostream>
#include <vector>
using namespace std;

class TxConsultaVideojoc{
    private:
        string nom;
        vector<string> resultat;
        
    public:
        TxConsultaVideojoc(string nomV);
        vector<string> obteResultat();
        void executar();
     
};



#endif