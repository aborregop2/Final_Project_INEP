#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include <pqxx/pqxx>

CercadoraConte::CercadoraConte()
{

}

vector<PassarellaConte> CercadoraConte::cercaConteV(string nomV)
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT paquet FROM public.conte WHERE videojoc = '" + nomV + "'");
    
        vector<PassarellaConte> pcont;

        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaConte pconte;
            pconte.paquet = row["paquet"].as<string>();
            pcont.push_back(pconte);
        }

        txn.commit();

        return pcont;

    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

vector<PassarellaConte> CercadoraConte::cercaConteP(string nomP) 
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT videojoc FROM public.conte WHERE paquet = '" + nomP + "'");
    
        vector<PassarellaConte> pcont;

        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaConte pconte;
            pconte.videojoc = row["videojoc"].as<string>();
            //pcont contiene todos los videojuegos incluido el que se ha comprado (Hay que tratarlo despues)
            pcont.push_back(pconte);
        }

        txn.commit();

        return pcont;

    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}