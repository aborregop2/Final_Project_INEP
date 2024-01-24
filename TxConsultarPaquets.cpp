#include "TxConsultarPaquets.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include <string>

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
        auxp.nomPaq = pe[i].obteNom();
        auxp.descPaq = pe[i].obteDescripcio();
        auxp.preuPaq = pe[i].obtePreu();
        
        
        float total = 0;
        vector<PassarellaConte> pc = cc.cercaConteP(nom);
        for (unsigned int i = 0; i < pc.size(); ++i){
            vector<PassarellaElemCompra> vv = cEC.cercaElement(pc[i].obteNomVideojoc());
            total += stof(vv[i].obtePreu());
        }
        auxp.estalvi = total - stof(pe[0].obtePreu());
        resultat.push_back(auxp);
    }
}
vector<InfoPaq> TxConsultarPaquets::obteResultat()
{
    return resultat;
}