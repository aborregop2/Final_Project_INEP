#include "CercadoraUsuari.h"
#include "PassarellaUsuari.h"
#include <pqxx/pqxx>

CercadoraUsuari::CercadoraUsuari()
{

}

vector<PassarellaUsuari> CercadoraUsuari::cercaUsuari(string sobrenomU) 
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT FROM public.usuari WHERE sobrenom = '" + sobrenomU + "'");
    pqxx::row row = r[0];
        
    vector<PassarellaUsuari> pu;
    for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
        PassarellaUsuari u;
        u.obteSobrenom() = row["nom"].as<string>();
        u.obteSobrenom() = row["sobrenom"].as<string>();
        u.obteContrasenya() = row["contrasenya"].as<string>();
        u.obteCorreuElectronic() = row["correuelectronic"].as<string>();
        u.obteDataNaixament() = row["datanaixement"].as<string>();
        pu.push_back(u);
    }
    txn.commit();
    
    return pu;
}