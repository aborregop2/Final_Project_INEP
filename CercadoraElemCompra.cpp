#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include <pqxx/pqxx>

CercadoraElemCompra::CercadoraElemCompra()
{
    
}

vector<PasarellaElemCompra> CercadoraElemCompra::cercaElement(string elem)
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT nom, descripcio, preu, tipus FROM public.elementcompra WHERE nom = '" + elem + "'");
        
        vector<PassarellaElemCompra> ec;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PasarellaElemCompra pec;
            pec.nom = row["nom"].as<string>();
            pec.descripcio = row["descripcio"].as<string>();
            pec.preu = row["preu"].as<string>();
            pec.tipus = row["tipus"].as<string>();
            ec.push_back(pec);
        }
        txn.commit();

        return ec;

    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
 		return 1;
    } 
}