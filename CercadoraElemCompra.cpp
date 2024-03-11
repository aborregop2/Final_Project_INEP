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
    pqxx::result r = txn.exec("SELECT nom, descripcio, preu, tipus FROM public.elementcompra WHERE nom = '" + elem + "'");
        
    vector<PassarellaElemCompra> ec;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaElemCompra pec;
        pec.obteNom() = row["nom"].as<string>();
        pec.obteDescripcio() = row["descripcio"].as<string>();
        pec.obtePreu() = row["preu"].as<string>();
        pec.obteTipus() = row["tipus"].as<string>();
        ec.push_back(pec);
    }
    txn.commit();

    return ec;
}

vector<PassarellaElemCompra> CercadoraElemCompra::cercaTotsPaquet()
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT nom, descripcio, preu, tipus FROM public.elementcompra WHERE tipus = paquet");
        
    vector<PassarellaElemCompra> ec;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaElemCompra pec;
        pec.obtePreu();
        pec.obteNom() = row["nom"].as<string>();
        pec.obteDescripcio() = row["descripcio"].as<string>();
        pec.obtePreu() = row["preu"].as<string>();
        pec.obteTipus() = row["tipus"].as<string>();
        ec.push_back(pec);
    }
    txn.commit();

    return ec;
}
