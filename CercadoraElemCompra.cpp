#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include <vector>
#include <pqxx/pqxx>

CercadoraElemCompra::CercadoraElemCompra()
{
    
}

vector<PassarellaElemCompra> CercadoraElemCompra::cercaElement(string elem)
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT nom, descripcio, preu, tipus FROM public.element_compra WHERE nom = '" + elem + "'");
    
    vector<PassarellaElemCompra> ec;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaElemCompra pec;
        pec.modifyNom(row["nom"].as<string>());
        pec.modifyDesc(row["descripcio"].as<string>());
        pec.modifyPreu(row["preu"].as<string>());
        pec.modifyTipus(row["tipus"].as<string>());
        ec.push_back(pec);
    }
    txn.commit();
    return ec;
}

vector<PassarellaElemCompra> CercadoraElemCompra::cercaTotsPaquet()
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    string paq = "paquet";
    pqxx::result r = txn.exec("SELECT nom, descripcio, preu, tipus FROM public.element_compra WHERE tipus = '"+paq+"'");
        
    vector<PassarellaElemCompra> ec;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaElemCompra pec;
        pec.modifyNom(row["nom"].as<string>());
        pec.modifyDesc(row["descripcio"].as<string>());
        pec.modifyPreu(row["preu"].as<string>());
        pec.modifyTipus(row["tipus"].as<string>());
        ec.push_back(pec);
    }
    txn.commit();

    return ec;
}
