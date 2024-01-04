#include "TxConsultarPaquet.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"

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
        
        
        int total = 0;
        vector<PassarellaConte> pc = cc.cercaConteP(nom);
        for (unsigned int i = 0; i < pc.size(); ++i){
            vector<PassarellaElemCompra> vv = cEC.cercaElement(pc[i].obteNomVideojoc());
            total += vv[i].obtePreu();
            InfoVid auxv;
            auxv.nomVid = vv[i].obteNom();
            auxv.descVid = vv[i].obteDescripcio();
            auxv.preuVid = vv[i].obtePreu();
            resultat.res.push_back(auxv);
        }
        resultat.estalvi = total - pe[0].obtePreu();
}

InfoPaq TxConsultarPaquet::obteResultat()
{
    return resultat;    
}