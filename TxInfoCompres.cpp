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
    vector<PassarellaCompra> compresU = CeCo.cercaCompra(sobrenomU); //Error
    float totalEuros = 0;
    int totalVideojocs = 0, totalPaquets = 0;
    for(unsigned int i = 0; i < compresU.size(); ++i){
        string elem = compresU[i].obteElementCompra();
        CercadoraElemCompra CE;
        vector<PassarellaElemCompra> ec = CE.cercaElement(elem);
        float preuE = stof(ec[0].obtePreu());
        string tipusE = ec[0].obteTipus();
        totalEuros += preuE;

        if (tipusE == "paquet") totalPaquets++;
        else if (tipusE == "videojoc") totalVideojocs++;
    }
    
    resultat.push_back(to_string(totalPaquets));  
    resultat.push_back(to_string(totalVideojocs));
    resultat.push_back(to_string(totalEuros));
}

vector<string> TxInfoCompres::obteResultat()
{
    return resultat;
}