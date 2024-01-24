#include "TxConsultarPaquet.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include <string>

TxConsultarPaquet::TxConsultarPaquet(string nomP) : nom(nomP)
{
    
}

void TxConsultarPaquet::executar()
{
        CercadoraElemCompra cEC;
        CercadoraConte cc;
        vector<PassarellaElemCompra> pe = cEC.cercaElement(nom);

        resultat.nomPaq = nom;
        resultat.descPaq = pe[0].obteDescripcio();
        resultat.preuPaq = pe[0].obtePreu();
        
        float total = 0;
        vector<PassarellaConte> pc = cc.cercaConteP(nom);
        for (unsigned int i = 0; i < pc.size(); ++i){
            vector<PassarellaElemCompra> vv = cEC.cercaElement(pc[i].obteNomVideojoc());
            total += stof(vv[0].obtePreu());
            InfoVid auxv;
            auxv.nomVid = vv[0].obteNom();
            auxv.descVid = vv[0].obteDescripcio();
            auxv.preuVid = vv[0].obtePreu();
            resultat.res.push_back(auxv);
        }
        resultat.estalvi = total - stof(pe[0].obtePreu());
}

InfoPaq TxConsultarPaquet::obteResultat()
{
    return resultat;    
}