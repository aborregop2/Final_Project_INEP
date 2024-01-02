#include "CercadoraUsuari.h"
#include "PasarellaUsuari.h"
#include <pqxx/pqxx>

CercadoraUsuari::CercadoraUsuari()
{

}

vector<PassarellaUsuari> CercadoraUsuari::cercaUsuari(string sobrenomU) 
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT FROM public.usuari WHERE sobrenom = '" + sobrenomU + "'");
        pqxx::row row = r[0];
        
        vector<PasarellaUsuari> pu;
        for (pqxx::result::const_iterator row = r.begin(); row != r.end(); ++row) {
            PassarellaUsuari u;
            u.nom = row["nom"].as<string>();
            u.sobrenom = row["sobrenom"].as<string>();
            u.contrasenya = row["contrasenya"].as<string>();
            u.correuElectronic = row["correuelectronic"].as<string>();
            u.dataNaixement = row["datanaixement"].as<string>();
            pu.push_back(u);
        }
        txn.commit();

        return u;

        return usuari;
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
 		return 1;
    } 
}