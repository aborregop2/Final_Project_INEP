#ifndef TX_CONSULTA_COMPRES_H
#define TX_CONSULTA_COMPRES_H

#include <iostream>
#include <vector>
#include "Structs.h"

using namespace std;




class TxConsultaCompres{
    private:
        pair< vector<InfoPaq>,vector<InfoVid> > resultat;
        
    public:
        TxConsultaCompres();
        pair< vector<InfoPaq> ,vector<InfoVid> >  obteResultat();
        void executar();
};




#endif