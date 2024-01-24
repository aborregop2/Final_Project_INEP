#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include <pqxx/pqxx>

CercadoraConte::CercadoraConte()
{

}

vector<PassarellaConte> CercadoraConte::cercaConteV(string nomV)
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT paquet, videojoc FROM public.conte WHERE videojoc = '" + nomV + "'");
    
    vector<PassarellaConte> pcont;

    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaConte pconte;
        pconte.modifyNomPaq(row["paquet"].as<string>());
        pcont.push_back(pconte);
    }

    txn.commit();

    return pcont;

}

vector<PassarellaConte> CercadoraConte::cercaConteP(string nomP) 
{
   
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT videojoc FROM public.conte WHERE paquet = '" + nomP + "'");
    
        vector<PassarellaConte> pcont;

        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaConte pconte;
            pconte.modifyNomVid(row["videojoc"].as<string>());
            //pcont contiene todos los videojuegos incluido el que se ha comprado (Hay que tratarlo despues)
            pcont.push_back(pconte);
        }

        txn.commit();

        return pcont;

}