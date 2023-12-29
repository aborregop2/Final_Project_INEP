#include "PassarellaUsuari.hpp"
#include <pqxx/pqxx>

PassarellaUsuari::PassarellaUsuari(string nU,string sU,string cU,string ceU,string dnU): nom(nU), sobrenom(sU),
                                        contrasenya(cU), correuElectronic(ceU), dataNaixement(dnU)
{

}

void PassarellaUsuari::insereix()
{
    insereixp();
}

void PassarellaUsuari::insereixp()
{
    try{
        pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
        pqxx::work txn(conn);
        txn.exec("INSERT INTO public.usuari(nom, sobrenom, contrasenya, correuelectronic, datanaixement) VALUES('"+nom+"','"+sobrenom+"' , '"+contrasenya+"', '"+correuElectronic+"', '"+dataNaixement+"')");
        txn.commit();
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
 		return 1;
    }    
}