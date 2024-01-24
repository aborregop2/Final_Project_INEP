#define _CRT_SECURE_NO_WARNINGS
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
#include <string>


TxComprarVideojoc::TxComprarVideojoc(std::string nomVid, string preu):nom(nomVid), preu_pagat(preu)
{

}



void TxComprarVideojoc::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    optional<PassarellaUsuari> u = v.obteUsuari();
    /*
    auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::tm local_tm = *std::localtime(&now_time);
    std::string dataavui = to_string(local_tm.tm_mday) + '/' + to_string((local_tm.tm_mon + 1)) + '/' + to_string((local_tm.tm_year + 1900)) + " " + to_string(local_tm.tm_hour) + ':' + std::to_string(local_tm.tm_min);
   
    */
    time_t tiempoActual = time(nullptr);
    tm* FechaHora = localtime(&tiempoActual);
    string dataavui;
    dataavui += to_string(FechaHora->tm_year + 1900);
    dataavui += '/';
    dataavui += to_string(FechaHora->tm_mon + 1);
    dataavui += '/';
    dataavui += to_string(FechaHora->tm_mday);


    PassarellaCompra pc(u.value().obteSobrenom(), nom, dataavui, preu_pagat);
    try {
      pc.insereix();
    }
    catch(const exception& e){
        string err = "ERROR: El videojoc ja ha estat comprat \n";
        throw err;
    }

    CercadoraConte ccont;
    vector<PassarellaConte> vpc = ccont.cercaConteV(nom);
    vector<string> vpcP; //-> Guarda les pasarellesConte dels videojocs similars
    vector<PassarellaConte> aux;
    for(unsigned int i = 0; i < vpc.size(); ++i){
        aux.push_back(vpc[i]);
    }
    vector<PassarellaConte> vnomvid;
    vector<string> nomsVids;
    for (unsigned int j = 0; j < aux.size(); ++j) {
        vnomvid = ccont.cercaConteP(aux[j].obteNomPaquet());
        for (unsigned int k = 0; k < vnomvid.size(); ++k) {
            nomsVids.push_back(vnomvid[k].obteNomVideojoc());
        }

    }

    vector<PassarellaVideojoc> videojocsrel;
    CercadoraVideojoc CercVid;
    
    for(unsigned int i = 0; i < nomsVids.size(); ++i){
        vector<PassarellaVideojoc> vid = CercVid.cercaVideojoc(nomsVids[i]);
        bool trobat = false;
        for (unsigned int k = 0; k < videojocsrel.size(); ++k) {
            if (videojocsrel[k].obteNom() == vid[0].obteNom()) {
                trobat = true;
            }
        }
        if (not trobat){
             videojocsrel.push_back(vid[0]);
        }
    }



    CercadoraElemCompra cvv;
    vector<PassarellaElemCompra> elemrel;
    for (unsigned int i = 0; i <  nomsVids.size(); ++i){
        vector<PassarellaElemCompra> vv = cvv.cercaElement(nomsVids[i]);
        elemrel.push_back(vv[0]);
    }
    vector<InfoRel> auxres;
    for (unsigned int i = 0; i < videojocsrel.size(); ++i){
        InfoRel r;
        r.nomVid = videojocsrel[i].obteNom();
        r.descVid = elemrel[i].obteDescripcio();
        r.preu = elemrel[i].obtePreu();
        if (r.nomVid != nom) {
            auxres.push_back(r);
        }
    }
    resultat = auxres;
}

vector<InfoRel> TxComprarVideojoc::obteResultat()
{
    return resultat;
}