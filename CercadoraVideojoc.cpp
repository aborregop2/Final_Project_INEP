#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"
#include <pqxx/pqxx>
#include <vector>

CercadoraVideojoc::CercadoraVideojoc()
{

}

vector<PassarellaVideojoc> CercadoraVideojoc::cercaVideojoc(string nomV) 
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT nom, qualificacio_edat, data_llansament, mins_estimat, genere FROM public.videojoc WHERE nom = '" + nomV + "'");
        
    vector<PassarellaVideojoc> pv;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaVideojoc pvi;
        pvi.modifyNom(row["nom"].as<string>());
        pvi.modifyQualificacioEdat(stoi(row["qualificacio_edat"].as<string>()));
        pvi.modifyDataLlansament(row["data_llansament"].as<string>());
        pvi.modifyMinsEstimat(stoi(row["mins_estimat"].as<string>()));
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
        pqxx::result r = txn.exec("SELECT nom, qualificacio_edat, data_llansament, mins_estimat, genere FROM public.videojoc");
        
        vector<PassarellaVideojoc> pv;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaVideojoc pvi;
            pvi.modifyNom(row["nom"].as<string>());
            pvi.modifyQualificacioEdat(stoi(row["qualificacio_edat"].as<string>()));
            pvi.modifyDataLlansament(row["data_llansament"].as<string>());
            pvi.modifyMinsEstimat(stoi(row["mins_estimat"].as<string>()));
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
    pqxx::result r = txn.exec("SELECT nom, qualificacio_edat, data_llansament, mins_estimat, genere FROM public.videojoc WHERE qualificacio_edat <= '"+ stredatV +"' ");

    vector<PassarellaVideojoc> pv;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaVideojoc pvi;
        pvi.modifyNom(row["nom"].as<string>());
        pvi.modifyQualificacioEdat(stoi(row["qualificacio_edat"].as<string>()));
        pvi.modifyDataLlansament(row["data_llansament"].as<string>());
        pvi.modifyMinsEstimat(stoi(row["mins_estimat"].as<string>()));
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
        pqxx::result r = txn.exec("SELECT nom, qualificacio_edat, data_llansament, mins_estimat, genere FROM public.videojoc WHERE data_llansament >= '" + dataV + "'");
        
        vector<PassarellaVideojoc> pv;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaVideojoc pvi;
            pvi.modifyNom(row["nom"].as<string>());
            pvi.modifyQualificacioEdat(stoi(row["qualificacio_edat"].as<string>()));
            pvi.modifyDataLlansament(row["data_llansament"].as<string>());
            pvi.modifyMinsEstimat(stoi(row["mins_estimat"].as<string>()));
            pvi.modifyGenere(row["genere"].as<string>());
            pv.push_back(pvi);
        }
        txn.commit();
        return pv; 
}

