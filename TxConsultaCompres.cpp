#include "TxConsultaCompres.h"
#include "Videoconsola.h"
#include "CercadoraCompres.h"
#include "PassarellaCompra.h"
#include "CercadoraElemCompra.h"
#include "CercadoraConte.h"


TxConsultaCompres::TxConsultaCompres()
{

}

pair< vector<InfoPaq> ,vector<InfoVid> >  TxConsultaCompres::obteResultat()
{
    return resultat;
}


void TxConsultaCompres::executar()
{
    Videoconsola* v = Videoconsola::getInstance();
    PassarellaUsuari u = v->obteUsuari().value();

    CercadoraCompres cc;
    
    vector<PassarellaCompra> vp = cc.cercaCompra(u.obteSobrenom());
    CercadoraElemCompra cEC;
    vector<PassarellaElemCompra> pEC;
    for(unsigned i = 0; i < vp.size(); ++i) {
            vector<PassarellaElemCompra> aux = cEC.cercaElement(vp[i].obteElementCompra());
            pEC.push_back(aux[0]);
           
            if (aux[0].obteTipus() == "videojoc"){
                InfoVid auxv;
                auxv.nomVid = aux[0].obteNom();
                auxv.descVid = aux[0].obteDescripcio();
                auxv.preuVid = aux[0].obtePreu();
                auxv.dataVid = vp[i].obteData();
                resultat.second.push_back(auxv);
            }
            else if (aux[0].obteTipus() == "paquet"){
                InfoPaq auxp;
                auxp.nomPaq = aux[0].obteNom();
                auxp.descPaq = aux[0].obteDescripcio();
                auxp.preuPaq = aux[0].obtePreu();
                auxp.dataPaq = vp[i].obteData();
                 
                CercadoraConte CCont;
                vector<PassarellaConte> pascont = CCont.cercaConteP(aux[0].obteNom());

                for (unsigned int i = 0; i < pascont.size(); ++i){
                    vector<PassarellaElemCompra> auxiliar = cEC.cercaElement(pascont[i].obteNomVideojoc());
                    InfoVid videojocaux;
                    videojocaux.nomVid = auxiliar[0].obteNom();
                    videojocaux.descVid = auxiliar[0].obteDescripcio();
                    videojocaux.preuVid = auxiliar[0].obtePreu();
                    auxp.res.push_back(videojocaux);
                }
                resultat.first.push_back(auxp);

            }
            
    }

    

}