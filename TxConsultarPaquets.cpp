#include "TxConsultarPaquets.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"


TxConsultarPaquets::TxConsultarPaquets()
{

}

void TxConsultarPaquets::executar()
{
    CercadoraElemCompra cEC;
    CercadoraConte cc;
    vector<PassarellaElemCompra> pe = cEC.cercaTotsPaquet();

    for (unsigned int i = 0; i < pe.size(); i++) {
        InfoPaq auxp;
        auxp.nomPaq = nom;
        auxp.descPaq = pe[i].obteDescripcio();
        auxp.preuPaq = pe[i].obtePreu();
        
        
        int total = 0;
        vector<PassarellaConte> pc = cc.cercaConteP(nom);
        for (unsigned int i = 0; i < pc.size(); ++i){
            vector<PassarellaElemCompra> vv = cEC.cercaElement(pc[i].obteNomVideojoc());
            total += vv[i].obtePreu();
        }
        auxp.estalvi = total - pe[0].obtePreu();
        resultat.push_back(auxp);
    }
}
vector<InfoPaq> TxConsultarPaquets::obteResultat()
{
    return resultat;
}