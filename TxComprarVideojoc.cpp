#include "TxComprarVideojoc.h"
#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"
#include "CercadoraElemCompra.h"
#include "PassarellaUsuari.h"
#include "PassarellaCompra.h"
#include "Videoconsola.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include <ctime>
#include <chrono>
#include <string>

TxComprarVideojoc::TxComprarVideojoc(std::string nomVid):nom(nomVid)
{

}



void TxComprarVideojoc::executar()
{
    Videoconsola* v = Videoconsola::getInstance();
    optional<PassarellaUsuari> u = v->obteUsuari();
    
    auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::tm local_tm = *std::localtime(&now_time);
    std::string dataavui = to_string(local_tm.tm_mday) + '/' + to_string((local_tm.tm_mon + 1)) + '/' + to_string((local_tm.tm_year + 1900)) + " " + to_string(local_tm.tm_hour) + ':' + std::to_string(local_tm.tm_min);
   

    
    PassarellaCompra pc(u.value().obteNom(), nom, dataavui);
   
    pc.insereix();

    CercadoraConte ccont;
    vector<PassarellaConte> vpc = ccont.cercaConteV(nom);
    vector<string> vpcP; //-> Guarda les pasarellesConte dels videojocs similars
    vector<PassarellaConte> aux;
    for(unsigned int i = 0; i < vpc.size(); ++i){
        aux = ccont.cercaConteP(vpc[i].obteNomPaquet());

        for(unsigned int j = 1; j < aux.size()+1; ++j){
            if((nom != aux[j].obteNomVideojoc()) && (nom != aux[j-1].obteNomVideojoc()) && (aux[j-1].obteNomVideojoc() != aux[j].obteNomVideojoc())){
                vpcP.push_back(aux[j].obteNomVideojoc());
            }
        }
    }

    
    CercadoraVideojoc cv;
    vector<PassarellaVideojoc> videojocsrel;
    for(unsigned int i = 0; i < vpcP.size(); ++i){
        vector<PassarellaVideojoc> vid = cv.cercaVideojoc(vpcP[i]);
        videojocsrel.push_back(vid[0]);
    }


    CercadoraElemCompra cvv;
    vector<PassarellaElemCompra> elemrel;
    for (unsigned int i = 0; i <  vpcP.size(); ++i){
        vector<PassarellaElemCompra> vv = cvv.cercaElement(vpcP[i]);
        elemrel.push_back(vv[0]);
    }
    vector<InfoRel> auxres;
    for (unsigned int i = 0; i < vpcP.size(); ++i){
        auxres[i].nomVid = videojocsrel[i].obteNom();
        auxres[i].descVid = elemrel[i].obteDescripcio();
        auxres[i].preu = to_string(elemrel[i].obtePreu());
    }
    resultat = auxres;
}

vector<InfoRel> TxComprarVideojoc::obteResultat()
{
    return resultat;
}