#ifndef TX_COMPRAR_PAQUET_H
#define TX_COMPRAR_PAQUET_H

#include "Videoconsola.h"
#include "PassarellaCompra.h"
#include <iostream>
#include <vector>
#include <string>
#include "Structs.h"
using namespace std;



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