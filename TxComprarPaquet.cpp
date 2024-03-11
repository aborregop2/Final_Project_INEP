#include "TxComprarPaquet.h"
#include "PassarellaCompra.h"
#include "PassarellaConte.h"
#include "CercadoraConte.h"
#include "CercadoraElemCompra.h"
#include "CercadoraVideojoc.h"
#include "PassarellaElemCompra.h"
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>


TxComprarPaquet::TxComprarPaquet(string nomPaq): nom(nomPaq)
{

}

void TxComprarPaquet::executar()
{
    Videoconsola& v = Videoconsola::getInstance();
    optional<PassarellaUsuari> u = v.obteUsuari();
    CercadoraConte cp;
    CercadoraVideojoc cv;
    CercadoraElemCompra cc;

    vector<PassarellaElemCompra> pec = cc.cercaElement(nom);
    resultat.nomPaq = nom;
    resultat.descPaq = pec[0].obteDescripcio();
    resultat.preuPaq = pec[0].obtePreu();

    vector<PassarellaConte> videojocspaq = cp.cercaConteP(nom);
    vector<PassarellaElemCompra> pcc;
    for(unsigned int i = 0; i < videojocspaq.size(); ++i){
        InfoVid auxv;

        pcc = cc.cercaElement(videojocspaq[i].obteNomVideojoc());

        auxv.nomVid = videojocspaq[i].obteNomVideojoc();
        auxv.descVid = pcc[0].obteDescripcio();
        auxv.preuVid = pcc[0].obtePreu();

        resultat.res.push_back(auxv);
    }
    
}


void TxComprarPaquet::executar2() {
    Videoconsola& v = Videoconsola::getInstance();
    optional<PassarellaUsuari> u = v.obteUsuari();
    CercadoraConte cp;


    /*
        auto now = std::chrono::system_clock::now();
	    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	    std::tm local_tm = *std::localtime(&now_time);
        std::string dataavui = to_string(local_tm.tm_mday) + '/' + to_string((local_tm.tm_mon + 1)) + '/' + to_string((local_tm.tm_year + 1900)) + " " + to_string(local_tm.tm_hour) + ':' + std::to_string(local_tm.tm_min);
    

    */
   

    /*
    
    
    */
    string dataavui = "10/01/2024";
    vector<PassarellaConte> videojocspaq = cp.cercaConteP(nom);

    for(unsigned int i = 0; i < videojocspaq.size(); ++i){
        InfoVid auxv;
        PassarellaCompra pc(u.value().obteNom(), videojocspaq[i].obteNomVideojoc(), dataavui);
        pc.insereix();
    }
}


    /*
     InfoPaq TxComprarPaquet::obteResultat(){
       return resultat;
   }
    */
   