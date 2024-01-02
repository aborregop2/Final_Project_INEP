#include "PassarellaElemCompra.h"
#include "TxInfoCompres.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"
#include "CercadoraCompres.h"
#include "CercadoraElemCompra.h"
#include <vector>
#include <string>
#include <iostream>

TxInfoCompres::TxInfoCompres()
{

}

void TxInfoCompres::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari u = v.obteUsuari().value();
    string sobrenomU = u.obteSobrenom();
    
    CercadoraCompres CeCo;
    vector<PassarellaCompra> compresU = CeCo.cercaCompra(sobrenomU);

    int totalEuros = 0, totalVideojocs = 0, totalPaquets = 0;
    
    for(unsigned int i = 0; i < compresU.size(); ++i){
        string elem = compresU[i].obteElementCompra();
        CercadoraElemCompra CE;
        vector<PassarellaElemCompra> ec = CE.cercaElement(elem);
        int preuE = ec[0].obtePreu();
        string tipusE = ec[0].obteTipus();
        totalEuros += preuE;

        if (tipusE == "paquet") totalPaquets++;
        else if (tipusE == "videojoc") totalVideojocs++;
    }
    string rest[3];
    
    rest[0] = to_string(totalPaquets);
    rest[1] = to_string(totalVideojocs);
    rest[2] = to_string(totalEuros);

    resultat = rest;
}

string* TxInfoCompres::obteResultat()
{
    return resultat;
}