#include "PassarellaCompra.h"
#include <pqxx/pqxx>


PassarellaCompra::PassarellaCompra(string u, string el, string d) : usuari(u), element(el), data(d){
    
}

string PassarellaCompra::obteUsuari()
{
    return usuari;
}

string PassarellaCompra::obteElementCompra()
{
    return element;
}

string PassarellaCompra::obteData()
{
    return data;
}

void PassarellaCompra::insereix()
{
    try{
      pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
      pqxx::work txn(conn);
      txn.exec("INSERT INTO public.compra(usuari, element, data) VALUES('"+usuari+"','"+element+"' , '"+data+"'");
      txn.commit();
    }
    catch(const exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } 
}

 
