#include "PassarellaCompra.h"
#include <pqxx/pqxx>

PassarellaCompra::PassarellaCompra(): element("")
{

}

PassarellaCompra::PassarellaCompra(string u, string el, string d, string preu) : usuari(u), element(el), data(d), preu_pagat(preu)
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

void PassarellaCompra::modifyUsuari(string us)
{
    usuari = us;
}
void PassarellaCompra::modifyElement(string elem)
{
    element = elem;
}
void PassarellaCompra::modifyData(string dat)
{
    data = dat;
}

void PassarellaCompra::insereix()
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    txn.exec("INSERT INTO public.compra(data, usuari, element, preu_pagat) VALUES ('"+data+"','"+usuari+"' , '"+element+"', '"+preu_pagat+"')");
    txn.commit();
    
}

bool PassarellaCompra::existeix()
{
    pqxx::connection conn("dbname =INEP user =postgres  password =018180 hostaddr =127.0.0.1 port =5432");
    pqxx::work txn(conn);
    pqxx::result r = txn.exec("SELECT data, usuari, element, preu_pagat FROM public.compra WHERE usuari = '" + usuari + "' AND element = '" + element + "'");
    txn.commit();
    if (r.size() == 0) {
        return true;
    }
    else return false;

}   