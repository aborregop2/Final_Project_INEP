#include "CercadoraVideojoc.h"
PassarellaVideojoc
#include <pqxx/pqxx>

CercadoraVideojoc::CercadoraVideojoc()
{

}

vector<PassarellaVideojoc> CercadoraVideojocs::cercaVideojoc(string nomV) 
{
     try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT nom, qualificacioEdat, dataLLansament, minsEstimat, genere FROM public.videojoc WHERE nom = '" + nomV + "'");
        
        vector<PassarellaVideojoc> pv;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PasarellaVideojoc pvi;
            pvi.nom = row["nom"].as<string>();
            pvi.qualificacioEdat = row["qualificacioEdat"].as<string>();
            pvi.dataLlansament = row["dataLLansament"].as<string>();
            pvi.minsEstimat = row["minsEstimat"].as<string>();
            pvi.genere = row["genere"].as<string>();
            pv.push_back(pvi);
        }
        txn.commit();

        return pv;

    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
 		return 1;
    } 
}