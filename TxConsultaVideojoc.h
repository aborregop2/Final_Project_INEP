#ifndef TX_CONSULTA_VIDEOJOC_H
#define TX_CONSULTA_VIDEOJOC_H
#include <iostream>
using namespace std;

class TxConsultaVideojoc{
    private:
        string nom;
        string resultat[7];
        
    public:
        TxConsultaVideojoc(string nomV);
        string* obteResultat();
        void executar();
     
};



#endif