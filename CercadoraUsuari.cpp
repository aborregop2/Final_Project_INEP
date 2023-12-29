#include "CercadoraUsuari.hpp"
#include <pqxx/pqxx>

PasarellaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU) 
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT * FROM public.usuari WHERE sobrenom = '" + sobrenomU + "'");
        pqxx::row row = r[0];
        
        PassarellaUsuari u;
        u.nom = row["nom"].as<string>();
        u.sobrenom = row["sobrenom"].as<string>();
        u.contrasenya = row["contrasenya"].as<string>();
        u.correuElectronic = row["correuelectronic"].as<string>();
        u.dataNaixement = row["datanaixement"].as<string>();

        txn.commit();

        return u;

        return usuari;
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
 		return 1;
    } 
}