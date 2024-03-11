#include "CercadoraCompres.h"
#include "PassarellaCompra.h"
#include <pqxx/pqxx>

CercadoraCompres::CercadoraCompres()
{

}

vector<PassarellaCompra> CercadoraCompres::cercaCompra(string sobrenomU)
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT data, usuari, element FROM public.compra WHERE sobrenom = '" + sobrenomU + "'");
        
    vector<PassarellaCompra> compresU;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaCompra pc;
        pc.obteElementCompra() = row["element"].as<string>();
        pc.obteData()  = row["data"].as<string>();
        pc.obteUsuari() = row["usuari"].as<string>();
        compresU.push_back(pc);
    }
    txn.commit();

    return compresU;


}