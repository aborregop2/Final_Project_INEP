#include "PassarellaElemCompra.h"
#include "TxInfoCompres.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"
#include "CercadoraCompres.h"
#include <vector>

void TxInfoCompres::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari u = v.obteUsuari();
    string sobrenomU = u.obteSobrenom();
    
    CercadoraCompres CeCo;
    vector<PassarellaCompra> compresU = CeCo.cercaCompra(sobrenomU);

    int totalEuros = 0, totalVideojocs = 0, totalPaquets = 0;
    
    for(unsigned int i = 0; i < compresU.size(); ++i){
        string elem = compresU[i].obteElementCompra();
        CercadoraElemCompra CE;
        PasarellaElemCompra ec = CE.cercaElement(elem);
        int preuE = ec.obtePreu();
        int tipusE = ec.obteTipus();
        totalEuros += preuE;

        if (tipusE == "paquet") totalPaquets++;
        else if (tipusE == "videojoc") totalVideojocs++;
    }

    resultat[0] = to_string(totalPaquets);
    resultat[1] = to_string(totalVideojocs);
    resultat[2] = to_string(totalEuros);
}

string[] TxInfoCompres::obteResultat()
{
    return resultat;
}