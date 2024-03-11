#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"
#include <pqxx/pqxx>

CercadoraVideojoc::CercadoraVideojoc()
{

}

vector<PassarellaVideojoc> CercadoraVideojoc::cercaVideojoc(string nomV) 
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT nom, qualificacioEdat, dataLLansament, minsEstimat, genere FROM public.videojoc WHERE nom = '" + nomV + "'");
        
    vector<PassarellaVideojoc> pv;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaVideojoc pvi;
        pvi.modifyNom(row["nom"].as<string>());
        pvi.modifyQualificacioEdat(stoi(row["qualificacioEdat"].as<string>()));
        pvi.modifyDataLlansament(row["dataLLansament"].as<string>());
        pvi.modifyMinsEstimat(stoi(row["minsEstimat"].as<string>()));
        pvi.modifyGenere(row["genere"].as<string>());
        pv.push_back(pvi);
    }
    txn.commit();

    return pv;

}

vector<PassarellaVideojoc> CercadoraVideojoc::cercaTotsVideojocs()
{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT nom, qualificacioEdat, dataLLansament, minsEstimat, genere FROM public.videojoc");
        
        vector<PassarellaVideojoc> pv;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaVideojoc pvi;
            pvi.modifyNom(row["nom"].as<string>());
            pvi.modifyQualificacioEdat(stoi(row["qualificacioEdat"].as<string>()));
            pvi.modifyDataLlansament(row["dataLLansament"].as<string>());
            pvi.modifyMinsEstimat(stoi(row["minsEstimat"].as<string>()));
            pvi.modifyGenere(row["genere"].as<string>());
            pv.push_back(pvi);
        }
        txn.commit();
        return pv; 
}

vector<PassarellaVideojoc> CercadoraVideojoc::cercaVideojocsEdat(int edatV)
{
    string stredatV = to_string(edatV);
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT nom, qualificacioEdat, dataLlansament, minsEstimat, genere FROM public.videojoc WHERE qualificacioEdat <= '"+ stredatV +"' ");

    vector<PassarellaVideojoc> pv;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaVideojoc pvi;
        pvi.modifyNom(row["nom"].as<string>());
        pvi.modifyQualificacioEdat(stoi(row["qualificacioEdat"].as<string>()));
        pvi.modifyDataLlansament(row["dataLLansament"].as<string>());
        pvi.modifyMinsEstimat(stoi(row["minsEstimat"].as<string>()));
        pvi.modifyGenere(row["genere"].as<string>());
        pv.push_back(pvi);
    }
    txn.commit();
    return pv;
}

vector<PassarellaVideojoc> CercadoraVideojoc::cercaVideojocsNovetat(string dataV)
{
    
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT nom, qualificacioEdat, dataLLansament, minsEstimat, genere FROM public.videojoc WHERE dataLLansament >= '" + dataV + "'");
        
        vector<PassarellaVideojoc> pv;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaVideojoc pvi;
            pvi.modifyNom(row["nom"].as<string>());
            pvi.modifyQualificacioEdat(stoi(row["qualificacioEdat"].as<string>()));
            pvi.modifyDataLlansament(row["dataLLansament"].as<string>());
            pvi.modifyMinsEstimat(stoi(row["minsEstimat"].as<string>()));
            pvi.modifyGenere(row["genere"].as<string>());
            pv.push_back(pvi);
        }
        txn.commit();
        return pv; 
}

