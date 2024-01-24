#define _CRT_SECURE_NO_WARNINGS
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
    string Errorpaq = "ERROR: No s'ha trobat el paquet que buscaves o ja ha estat comprat\n";
    if (resultat.nomPaq == "") throw(Errorpaq);
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
    CercadoraElemCompra cEM;


    /*
        auto now = std::chrono::system_clock::now();
	    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	    std::tm local_tm = *std::localtime(&now_time);
        std::string dataavui = to_string(local_tm.tm_mday) + '/' + to_string((local_tm.tm_mon + 1)) + '/' + to_string((local_tm.tm_year + 1900)) + " " + to_string(local_tm.tm_hour) + ':' + std::to_string(local_tm.tm_min);
    

    */
   

    /*
    
    
    */
    time_t tiempoActual = time(nullptr);
    tm* FechaHora = localtime(&tiempoActual);
    string dataavui;
    string horamin;
    dataavui += to_string(FechaHora->tm_mday);
    dataavui += '/';
    dataavui += to_string(FechaHora->tm_mon + 1);
    dataavui += '/';
    dataavui += to_string(FechaHora->tm_year + 1900);
    horamin += to_string(FechaHora->tm_hour);
    horamin += ':';
    horamin += to_string(FechaHora->tm_min);
    vector<PassarellaConte> videojocspaq = cp.cercaConteP(nom);

    vector<PassarellaElemCompra> vec = cEM.cercaElement(nom);


    for(unsigned int i = 0; i < videojocspaq.size(); ++i){
        PassarellaCompra pc(u.value().obteSobrenom(), videojocspaq[i].obteNomVideojoc(), dataavui, vec[0].obtePreu());
        bool exist = pc.existeix();
        if (exist != false) {
            pc.insereix();
        }
    }
    PassarellaCompra pcpaq(u.value().obteSobrenom(), nom, dataavui, vec[0].obtePreu());
    pcpaq.insereix();

}


  
     InfoPaq TxComprarPaquet::obteResultat(){
       return resultat;
   }
    
   