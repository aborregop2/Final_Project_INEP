#include "PassarellaCompra.h"
#include <pqxx/pqxx>

PassarellaCompra::PassarellaCompra()
{

}

PassarellaCompra::PassarellaCompra(string u, string el, string d) : usuari(u), element(el), data(d)
{
    
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
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    txn.exec("INSERT INTO public.compra(usuari, element, data) VALUES('"+usuari+"','"+element+"' , '"+data+"'");
    txn.commit();
    
}

 
