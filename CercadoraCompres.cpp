#include "CercadoraCompres.h"
#include "PassarellaCompra.h"
#include <pqxx/pqxx>

CercadoraCompres::CercadoraCompres()
{

}

vector<PassarellaCompra> CercadoraCompres::cercaCompra(string sobrenomU)
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT data, usuari, element FROM public.compra WHERE sobrenom = '" + sobrenomU + "'");
        
        vector<PassarellaCompra> compresU;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaCompra pc;
            pc.element = row["element"].as<string>();
            pc.data = row["data"].as<string>();
            pc.usuari = row["usuari"].as<string>();
            compresU.push_back(pc);
        }
        txn.commit();

        return compresU;

    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
 		return 1;
    }
}